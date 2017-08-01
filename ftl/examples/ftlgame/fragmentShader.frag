#version 330

in  vec4 theColor;
in  vec2 textureUV;

out vec4 color;

uniform sampler2D texture2D;
uniform int texturing;

void main()
{
    if(texturing == 1)
        color = texture(texture2D, textureUV) * theColor;
    else
        color = theColor;
}