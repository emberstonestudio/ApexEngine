#include "material.h"
#include <iostream>
#include <utility>
#include "shader.h"
#include "texture.h"

Material::Material(const std::string& name, std::shared_ptr<Shader> shader)
    : name(name), shader(std::move(shader))
{
}

void Material::SetShader(std::shared_ptr<Shader> newShader)
{
    shader = std::move(newShader);
}

void Material::SetTexture(const std::string& name, std::shared_ptr<Texture> texture)
{
    textures[name] = std::move(texture);
}

std::shared_ptr<Texture> Material::GetTexture(const std::string& name) const
{
    auto it = textures.find(name);
    return (it != textures.end()) ? it->second : nullptr;
}

void Material::SetFloat(const std::string& name, float value)
{
    floatUniforms[name] = value;
}

void Material::SetInt(const std::string& name, int value)
{
    intUniforms[name] = value;
}

void Material::SetVec3(const std::string& name, const glm::vec3& value)
{
    vec3Uniforms[name] = value;
}

void Material::SetVec4(const std::string& name, const glm::vec4& value)
{
    vec4Uniforms[name] = value;
}

void Material::SetMat4(const std::string& name, const glm::mat4& value)
{
    mat4Uniforms[name] = value;
}

void Material::Use() const
{
    if (!shader) return;
    
    shader->use();
    
    // Bind textures
    unsigned int textureSlot = 0;
    for (const auto& [name, texture] : textures)
    {
        if (texture)
        {
            texture->Bind(textureSlot);
            shader->setInt(name.c_str(), textureSlot);
            textureSlot++;
        }
    }
    
    shader->setBool("hasTexture", !textures.empty());
    
    // Apply stored uniforms
    ApplyUniforms();
}

void Material::ApplyUniforms() const
{
    if (!shader) return;
    
    for (const auto& [name, value] : floatUniforms)
        shader->setFloat(name.c_str(), value);
    
    for (const auto& [name, value] : intUniforms)
        shader->setInt(name.c_str(), value);
    
    for (const auto& [name, value] : vec3Uniforms)
        shader->setVec3(name.c_str(), value);
    
    for (const auto& [name, value] : vec4Uniforms)
        shader->setVec4(name.c_str(), value);
    
    for (const auto& [name, value] : mat4Uniforms)
        shader->setMat4(name.c_str(), value);
}