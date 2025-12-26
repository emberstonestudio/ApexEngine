#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

Shader::Shader(const std::string& name, const char* vertPath, const char* fragPath)
    : shaderName(name), programId(0)
{
    const std::string vertexCode = readFile(vertPath);
    const std::string fragmentCode = readFile(fragPath);
    
    if (vertexCode.empty() || fragmentCode.empty())
    {
        std::cerr << "Failed to read shader files for: " << name << std::endl;
        return;
    }

    const unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode, "vertex");
    const unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode, "fragment");
    
    if (vertexShader && fragmentShader)
    {
        linkProgram(vertexShader, fragmentShader);
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    if (programId != 0)
    {
        glDeleteProgram(programId);
    }
}

void Shader::use() const
{
    glUseProgram(programId);
}

void Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(programId, name.c_str()), static_cast<int>(value));
}

void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(programId, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
}

std::string Shader::readFile(const std::string& filePath)
{
    std::ifstream codeFile(filePath);
    
    if (!codeFile.is_open())
    {
        std::cerr << "Error: Could not open file: " << filePath << std::endl;
        return "";
    }
    
    std::stringstream fileStream;
    fileStream << codeFile.rdbuf();
    codeFile.close();
    
    return fileStream.str();
}

unsigned int Shader::compileShader(GLenum type, const std::string& source, const std::string& typeName) const
{
    const unsigned int shader = glCreateShader(type);
    const char* sourcePtr = source.c_str();
    glShaderSource(shader, 1, &sourcePtr, nullptr);
    glCompileShader(shader);
    
    // Check for compilation errors
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed (" << shaderName << " - " << typeName << "): " 
                  << infoLog << std::endl;
        glDeleteShader(shader);
        return 0;
    }
    
    return shader;
}

void Shader::linkProgram(const unsigned int vertexShader, const unsigned int fragmentShader)
{
    programId = glCreateProgram();
    glAttachShader(programId, vertexShader);
    glAttachShader(programId, fragmentShader);
    glLinkProgram(programId);
    
    // Check for linking errors
    int success;
    char infoLog[512];
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(programId, 512, nullptr, infoLog);
        std::cerr << "Shader program linking failed (" << shaderName << "): " 
                  << infoLog << std::endl;
        glDeleteProgram(programId);
        programId = 0;
    }
}