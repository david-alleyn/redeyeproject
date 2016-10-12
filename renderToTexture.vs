#version 330

layout(location = 0) in vec3 in_position; //vertices must be specified in Normalized Device Coordinates		
layout(location = 1) in vec2 in_texcoord;

uniform sampler1D offsets;

out vec2 texcoord;

void main(){

	texcoord = in_texcoord;
	vec4 offset = texelFetch(offsets, gl_InstanceID, 0);
	vec4 offSetPosition = vec4(vec3(in_position + offset.xyz), 1);

	gl_Position = vec4(offSetPosition.xyz,1); 
	//gl_Position = vec4(in_position,1); 
}
