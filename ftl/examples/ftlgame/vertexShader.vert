#version 330

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 textureCoords;

out vec4 theColor;
out vec2 textureUV;

void main()
{
    textureUV = textureCoords;
    theColor = color;
    gl_Position = position;
}