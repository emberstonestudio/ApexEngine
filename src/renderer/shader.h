#pragma once

#include <glad/glad.h>
#include <string>

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
    
    unsigned int getProgramId() const { return programId; }
    
private:
    std::string shaderName;
    unsigned int programId;

    static std::string readFile(const std::string& filePath);
    unsigned int compileShader(GLenum type, const std::string& source, const std::string& typeName) const;
    void linkProgram(unsigned int vertexShader, unsigned int fragmentShader);
};