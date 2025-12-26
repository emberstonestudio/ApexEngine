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
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
        
        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }
}

void Application::shutdown()
{
}
