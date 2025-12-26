#include "scene.h"

#include <iostream>

#include "model.h"
#include "renderable.h"
#include "renderer/material.h"
#include "renderer/shader.h"
#include "renderer/texture.h"

Scene::Scene()
{
    Initialize();
}

Scene::~Scene()
{
    renderables.clear();
}

void Scene::Initialize()
{
    create_demo_entity();
}

void Scene::create_demo_entity()
{
    std::cout << "Loading shader..." << std::endl;
    auto shader = std::make_shared<Shader>("default", "src/renderer/shaders/default_vert.glsl", "src/renderer/shaders/default_frag.glsl");
    
    std::cout << "Loading diffuse texture..." << std::endl;
    auto diffuseMapTexture = std::make_shared<Texture>("src/renderer/textures/test_diffuse.png");
    
    std::cout << "Loading normal texture..." << std::endl;
    auto normalMapTexture = std::make_shared<Texture>("src/renderer/textures/test_normal.png");
    
    std::cout << "Creating material..." << std::endl;
    auto material = std::make_shared<Material>("Test Material", shader);
    material->SetTexture("Diffuse_Map", diffuseMapTexture);
    material->SetTexture("Normal_Map", normalMapTexture);
    material->SetVec3("Albedo", glm::vec3(0.8f, 0.6f, 0.4f));
    
    std::cout << "Loading model..." << std::endl;
    Model demoModel("src/renderer/models/test_model.obj");
    
    std::cout << "Creating entity..." << std::endl;
    auto demoEntity = std::make_shared<Renderable>("Demo Entity");
    for (auto& mesh : demoModel.GetMeshes())
    {
        demoEntity->AddMesh(mesh);
    }
    demoEntity->SetMaterial(material);
    demoEntity->GetTransform().SetPosition(glm::vec3(0.0f, 2.0f, 0.0f));
    demoEntity->GetTransform().SetScale(glm::vec3(2.0f));
    
    renderables.push_back(demoEntity);
    std::cout << "Done loading!" << std::endl;
}