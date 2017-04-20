#version 330 core

in vec2 geomUV;

out vec4 finalColor;

uniform sampler2D fontTexture;

void main()
{
	finalColor = texture(fontTexture, geomUV);
}