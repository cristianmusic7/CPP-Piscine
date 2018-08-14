/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 00:20:30 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/08 00:20:31 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_DISPLAY_HPP
#define GRAPHICS_DISPLAY_HPP

#include <vector>
#include <GLFW/glfw3.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"


class GraphicsDisplay : public IMonitorDisplay{

    private:
        std::vector<IMonitorModule*> modules;
        int updateCounter;
        GLFWwindow* _window;
        bool _shouldClose;
        std::vector<IMonitorModule*> _modules;
        GraphicsDisplay(const GraphicsDisplay&);
        const GraphicsDisplay& operator=(const GraphicsDisplay&);

    public:
        virtual ~GraphicsDisplay();
        GraphicsDisplay();

        bool getCloseState(void);
        void update();
        void addWindow(IMonitorModule*);
        void freeModules();
        static void glfw_error_callback(int error, const char* description);
};

#endif
