#pragma once

#include <glad/glad.h>
#include <string>
#include <unordered_map>
#include <glm/fwd.hpp>

class Shader
{
public:
    Shader(const std::string& name, const char* vertPath, const char* fragPath);
    ~Shader();
    
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setVec4(const std::string& name, const glm::vec4& value) const;
    void setMat4(const std::string& name, const glm::mat4& value) const;
    
    unsigned int getProgramId() const { return programId; }
    
private:
    std::string shaderName;
    unsigned int programId;

    static std::string readFile(const std::string& filePath);
    unsigned int compileShader(GLenum type, const std::string& source, const std::string& typeName) const;
    void linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
    
    mutable std::unordered_map<std::string, int> uniformLocationCache;
    
    int GetUniformLocation(const std::string& name) const;
};
