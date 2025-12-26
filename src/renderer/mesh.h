#pragma once
#include <vector>
#include <glm/glm.hpp>

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Color;
};

class Mesh
{
public:
    
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();
        
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;
        
    void Bind();
    void Unbind();
        
    size_t GetIndexCount() const { return indices.size(); }
    
private:
    unsigned int VAO, VBO, EBO = 0;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    
    void setupMesh();
};
