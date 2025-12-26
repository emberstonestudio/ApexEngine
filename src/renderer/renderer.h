#pragma once
#include <memory>
#include "app/window.h"

class Scene;

class Mesh;

class Renderer
{
    
public:
    Renderer();
    ~Renderer();
    
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    void draw(GLFWwindow* window) const;
    
private:
    std::unique_ptr<Scene> scene;
};
