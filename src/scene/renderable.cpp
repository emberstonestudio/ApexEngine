#include "renderable.h"
#include "renderer/mesh.h"
#include "renderer/material.h"
#include <glad/glad.h>

Renderable::Renderable(const std::string& name) : name(name)
{
}

void Renderable::AddMesh(std::shared_ptr<Mesh> mesh)
{
    meshes.push_back(mesh);
}

void Renderable::SetMaterial(std::shared_ptr<Material> mat)
{
    material = mat;
}

void Renderable::Draw() const
{
    if (!visible || meshes.empty()) return;
    
    if (material)
    {
        material->Use();
        material->SetMat4("model", transform.GetModelMatrix());
    }
    
    for (const auto& mesh : meshes)
    {
        mesh->Bind();
        glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
        mesh->Unbind();
    }
}