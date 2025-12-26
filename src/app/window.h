#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
    
public:
    Window(int w, int h, const std::string& t);
    ~Window();
    
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    
    GLFWwindow* getWindow() const { return window; }
    int getWidth() const { return WIDTH; }
    int getHeight() const { return HEIGHT; }
    std::string getTitle() const { return TITLE; }
    
private:
    GLFWwindow* window = nullptr;
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const std::string TITLE = "Apex Engine";
    
    void initWindow(int w, int h, const std::string& t);
    static void windowFramebufferSizeCallback(GLFWwindow* window, int w, int h);
};
