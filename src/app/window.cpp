#include "window.h"
#include <iostream>

Window::Window(const int w, const int h, const std::string& t) : WIDTH(w), HEIGHT(h), TITLE(t)
{
    initWindow(w, h, t);
}

Window::~Window()
{
    if (window)
    {
        glfwDestroyWindow(window);
        std::cout << "Destroyed GLFW window" << std::endl;
    }
    
    glfwTerminate();
    std::cout << "GLFW terminated" << std::endl;
}

void Window::initWindow(const int w, const int h, const std::string& t)
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(w, h, t.c_str(), nullptr, nullptr);
    
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
    }
    
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
    }
    
    glViewport(0, 0, w, h);
    glfwSetFramebufferSizeCallback(window, windowFramebufferSizeCallback);
}

void Window::windowFramebufferSizeCallback(GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
}
