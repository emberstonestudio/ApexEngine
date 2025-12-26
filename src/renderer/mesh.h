#pragma once
#include <memory>

class Shader;

class Mesh
{
    
public:
    Mesh();
    ~Mesh();
    
    Mesh(const Mesh&) = delete;
    Mesh &operator=(const Mesh&) = delete;
    
    void CreateTriangle();
    void Draw() const;
    
private:
    unsigned int VBO = 0;
    unsigned int VAO = 0;
    
    std::shared_ptr<Shader> shader;
};
