#version 330

in vec2 vUV;
in vec4 vColour;

out vec4 outColour;

uniform sampler2D diffuseTexture;

void main()
{
	vec4 textureColor = texture(diffuseTexture, vUV);
	if(textureColor.a < 0.001) {
		discard;
	}
	outColour = textureColor * vColour;
}