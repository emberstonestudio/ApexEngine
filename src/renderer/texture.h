#pragma once
#include <string>

class Texture
{
public:
    Texture(const std::string& path);
    ~Texture();
    
    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
    
    void Bind(unsigned int slot = 0) const;
    void Unbind() const;
    
    unsigned int GetID() const { return id; }
    const std::string& GetPath() const { return path; }
    
private:
    unsigned int id = 0;
    std::string path;
    int width = 0;
    int height = 0;
    int channels = 0;
};