/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 00:21:54 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/08 00:21:56 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "IMonitorModule.hpp"
#include "GraphicsDisplay.hpp"

#include <unistd.h>
#include <limits.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>



GraphicsDisplay::GraphicsDisplay()
:_shouldClose(false)
{
    updateCounter = 0;
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        std::cout << "glfw error" << std::endl;
    // Setup window    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    this->_window = glfwCreateWindow(300, 960, "ft_gkrellm - ldehaudt - cfranco", NULL, NULL);
    glfwMakeContextCurrent(this->_window);
    glfwSwapInterval(1);
    gl3wInit();

    // Setup Dear ImGui binding
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(this->_window, true);
    ImGui_ImplOpenGL3_Init();

    // Setup style
    ImGui::StyleColorsDark();  
}

void GraphicsDisplay::update(){

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    if (glfwWindowShouldClose(this->_window))
        this->_shouldClose = true;
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);

    float h = 10;

    std::vector<IMonitorModule*>::iterator iter;
    updateCounter--;
    for (iter = this->_modules.begin(); iter < this->_modules.end(); iter++){
        ImGui::Begin((*iter)->getTitle().c_str());

        if (updateCounter <= 0)
             (*iter)->update();  

         if ((*iter)->getGraphValues().size() > 0)
        {
            int values_count = static_cast<int>((*iter)->getNumGraphValues());
            float values[values_count];

            if ((*iter)->getGraphValues().size() > 0)
            {
                for (int i = 0; i < values_count; i++)
                {
                    if (i < static_cast<int>((*iter)->getGraphValues().size()))
                        values[i] = (*iter)->getGraphValues()[i];  
                    else
                        values[i] = 0;    
                }
                bool change = (*iter)->getTypeGraph();
                ImGui::Checkbox("Line", &change);
                if (!change)
                    ImGui::PlotHistogram("", values, values_count, 0, "", 0, (*iter)->getGraphMax(), ImVec2(200,100));
                else
                    ImGui::PlotLines("", values, values_count, 0, "", 0, (*iter)->getGraphMax(), ImVec2(200,100)); 

                if (change != (*iter)->getTypeGraph())
                    (*iter)->changeGraph();
            }
        }
      
       int num = 0;
       for (unsigned int i = 0; i < (*iter)->getInfo().size(); i++)
       {
            num++;
            std::string str = (*iter)->getInfo()[i];
            if (str.find("%%") != std::string::npos){
                str = str.substr(0, str.find("%%") + 1) + "      ";
            }
            ImGui::Text("%s",(str).c_str());
       }
        h += ImGui::GetTextLineHeight()* (num * 1.3f + 4);
        if ((*iter)->getGraphValues().size() > 0)
            h += 120;
        ImGui::End();
        ImGui::SetNextWindowPos(ImVec2(10, h), ImGuiCond_FirstUseEver);
    } 
    if (updateCounter <= 0)
        updateCounter = 55; 
    ImGui::Render();
    int display_w, display_h;
    glfwMakeContextCurrent(this->_window);
    glfwGetFramebufferSize(this->_window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    glfwMakeContextCurrent(this->_window);
    glfwSwapBuffers(this->_window);
}
        
void GraphicsDisplay::addWindow(IMonitorModule* mod){
   _modules.push_back(mod);
}

GraphicsDisplay::GraphicsDisplay(const GraphicsDisplay&){

}

const GraphicsDisplay& GraphicsDisplay::operator=(const GraphicsDisplay&){
    return *this;
}

GraphicsDisplay::~GraphicsDisplay()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(this->_window);
    glfwTerminate();
}

void GraphicsDisplay::glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

bool GraphicsDisplay::getCloseState(void)
{
    return this->_shouldClose;
}

void GraphicsDisplay::freeModules(){
    std::vector<IMonitorModule*>().swap(modules);
}

