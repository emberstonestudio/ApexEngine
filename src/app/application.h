#pragma once
#include "window.h"
#include "renderer/renderer.h"

class Application
{
    
public:
    Application();
    ~Application();
    
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    
    void run();
    
private:
    Window window;
    Renderer renderer;
    
    void shutdown();
};
