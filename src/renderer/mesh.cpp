#include "mesh.h"
#include "shader.h"

Mesh::Mesh()
{
    shader = std::make_shared<Shader>("default", "src/renderer/shaders/default_vert.glsl", "src/renderer/shaders/default_frag.glsl");
    CreateTriangle();
}

Mesh::~Mesh()
{
    shader.reset();
}

void Mesh::CreateTriangle()
{
    constexpr float vertices[] = {
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::Draw() const
{
    if (shader) shader->use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
