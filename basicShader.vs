#version 330

in vec4 Position;
in vec2 UV;
in vec4 Colour;

out vec2 vUV;
out vec4 vColour;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

void main()
{
	vUV = UV;
	vColour = Colour;
	gl_Position = Projection * View * Model * Position;
}