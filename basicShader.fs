#version 330

in vec2 vUV;
in vec4 vColour;

out vec4 outColour;

uniform sampler2D diffuseTexture;

void main()
{
	outColour = texture2D(diffuseTexture, vUV) * vColour;
}