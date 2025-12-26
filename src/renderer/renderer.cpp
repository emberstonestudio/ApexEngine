#include "renderer.h"
#include <GLFW/glfw3.h>
#include "material.h"
#include "scene/renderable.h"
#include "scene/scene.h"

Renderer::Renderer()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    
    scene = std::make_unique<Scene>();
}

Renderer::~Renderer()
{
    scene.reset();
}

void Renderer::draw(GLFWwindow* window) const
{
    // Set clear color FIRST
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    // THEN clear both color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);
    
    float aspect = (float)width / (float)height;
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        aspect,
        0.1f,
        100.0f
    );
    
    glm::mat4 view = glm::lookAt(
        glm::vec3(4.0f, 3.0f, 4.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
    
    for (auto& renderable : scene->GetRenderables())
    {
        if (renderable && renderable->GetMaterial())
        {
            auto material = renderable->GetMaterial();
            material->SetMat4("projection", projection);
            material->SetMat4("view", view);
        }
        
        renderable->Draw();
    }
}