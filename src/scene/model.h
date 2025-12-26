#pragma once
#include <string>
#include <vector>
#include <memory>

class Mesh;
class Material;

struct aiNode;
struct aiScene;
struct aiMesh;

class Model
{
public:
    Model(const std::string& path);
    ~Model() = default;
    
    const std::vector<std::shared_ptr<Mesh>>& GetMeshes() const { return meshes; }
    
private:
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::string directory;
    
    void LoadModel(const std::string& path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    std::shared_ptr<Mesh> ProcessMesh(aiMesh* mesh, const aiScene* scene);
};