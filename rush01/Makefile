NAME = ft_gkrellm

FLAGS = -Wall -Wextra -Werror

LIBS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
LIBS += -L./imgui/libs/glfw/lib -lglfw3

INCS = -I./imgui/ -I./imgui/libs/gl3w -I./imgui/libs/glfw/include/

SRC = *.cpp
SRC += ./imgui/imgui_impl_glfw.cpp ./imgui/imgui_impl_opengl3.cpp
SRC += ./imgui/imgui.cpp ./imgui/imgui_demo.cpp ./imgui/imgui_draw.cpp
SRC += ./imgui/libs/gl3w/GL/gl3w.cpp

all : $(NAME)

$(NAME) :
	clang++ $(FLAGS) $(INCS) $(SRC) -lcurses -o $(NAME) $(LIBS)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)
	rm -f imgui.ini

re: fclean all