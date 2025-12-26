#include "application.h"

Application::Application() : window(800, 600, "Apex Engine")
{
}

Application::~Application()
{
    shutdown();
}

void Application::run()
{
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        renderer.draw(window.getWindow());
        
        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }
}

void Application::shutdown()
{
}
