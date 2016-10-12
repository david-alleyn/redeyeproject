#version 330

layout(location = 0) out vec4 out_color;

uniform sampler2D texture_color;
in vec2 texcoord;

void main(){
	out_color = texture2D(texture_color, texcoord);
}