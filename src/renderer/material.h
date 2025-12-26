#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader;
class Texture;

class Material
{
public:
    Material(const std::string& name, std::shared_ptr<Shader> shader);
    ~Material() = default;
    
    void SetShader(std::shared_ptr<Shader> shader);
    std::shared_ptr<Shader> GetShader() const { return shader; }
    
    // Texture management
    void SetTexture(const std::string& name, std::shared_ptr<Texture> texture);
    std::shared_ptr<Texture> GetTexture(const std::string& name) const;
    
    // Uniform setters
    void SetFloat(const std::string& name, float value);
    void SetInt(const std::string& name, int value);
    void SetVec3(const std::string& name, const glm::vec3& value);
    void SetVec4(const std::string& name, const glm::vec4& value);
    void SetMat4(const std::string& name, const glm::mat4& value);
    
    // Apply material (bind shader and set all uniforms/textures)
    void Use() const;
    void ApplyUniforms() const;
    
    const std::string& GetName() const { return name; }
    
private:
    std::string name;
    std::shared_ptr<Shader> shader;
    
    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
    std::unordered_map<std::string, float> floatUniforms;
    std::unordered_map<std::string, int> intUniforms;
    std::unordered_map<std::string, glm::vec3> vec3Uniforms;
    std::unordered_map<std::string, glm::vec4> vec4Uniforms;
    std::unordered_map<std::string, glm::mat4> mat4Uniforms;
};