#version 330

layout(location = 0) in vec3 in_position; //vertices must be specified in Normalized Device Coordinates		
layout(location = 1) in vec2 in_texcoord;

uniform samplerBuffer offsets;

out vec2 texcoord;

void main(){

	texcoord = in_texcoord;
	vec4 offset = texelFetch(offsets, gl_InstanceID);
	vec4 offSetPosition = vec4(in_position,1.0f) + offset;

	gl_Position = offSetPosition;
	//gl_Position = vec4(in_position,1); 
}
