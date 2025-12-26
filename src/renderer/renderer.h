#pragma once
#include <memory>

class Mesh;

class Renderer
{
    
public:
    Renderer();
    ~Renderer();
    
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    void draw() const;
    
private:
    std::unique_ptr<Mesh> testMesh;
};
