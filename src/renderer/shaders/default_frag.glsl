#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;
in vec3 Color;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

uniform bool hasTexture = false;

void main()
{
    if (hasTexture)
    {
        FragColor = texture(texture_diffuse1, TexCoords);
    }
    else
    {
        // Use vertex color if no texture
        FragColor = vec4(Color, 1.0);
    }
}