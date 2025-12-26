#pragma once
#include <memory>
#include <vector>

class Renderable;

class Scene
{
public:
    Scene();
    ~Scene();
    
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;
    
    std::vector<std::shared_ptr<Renderable>> GetRenderables() const { return renderables; }
    
private:
    void create_demo_entity();
    void Initialize();
    
    std::vector<std::shared_ptr<Renderable>> renderables;
};
