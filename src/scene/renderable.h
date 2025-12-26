#pragma once
#include <memory>
#include <string>
#include <vector>
#include "transform.h"

class Mesh;
class Material;

class Renderable
{
public:
    Renderable(const std::string& name);
    ~Renderable() = default;
    
    void AddMesh(std::shared_ptr<Mesh> mesh);
    void SetMaterial(std::shared_ptr<Material> material);
    
    std::shared_ptr<Material> GetMaterial() const { return material; }
    const std::vector<std::shared_ptr<Mesh>>& GetMeshes() const { return meshes; }
    
    Transform& GetTransform() { return transform; }
    const Transform& GetTransform() const { return transform; }
    
    const std::string& GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }
    
    bool IsVisible() const { return visible; }
    void SetVisible(bool isVisible) { visible = isVisible; }
    
    void Draw() const;
    
private:
    std::string name;
    Transform transform;
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::shared_ptr<Material> material;
    bool visible = true;
};