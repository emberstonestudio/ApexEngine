#include "renderer.h"
#include "mesh.h"

Renderer::Renderer()
{
    testMesh = std::make_unique<Mesh>();
}

Renderer::~Renderer()
{
    testMesh.reset();
}

void Renderer::draw() const
{
    if (testMesh)
        testMesh->Draw();
}
