#pragma once
#include "window.h"

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
    
    void shutdown();
};
