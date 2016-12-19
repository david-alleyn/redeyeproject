#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>

class FrameBufferWrapper {

private:

	unsigned int fbo;                   //framebuffer object
	unsigned int rgbTexture;
	unsigned int depthTexture;
	std::vector<GLenum> drawbuffer;     //add texture attachements

public:

	FrameBufferWrapper(unsigned int width, unsigned int height);

	~FrameBufferWrapper();

private:

	//delete objects
	void destroy();


	//generate an RGBA8 texture with bilinear filtering
	void GenerateRGBA8Texture(unsigned int width, unsigned int height);



	//generate a single channel depth texture with bilinear filtering
	void GenerateDepthTexture(unsigned int width, unsigned int height);
	
	//Generate FBO
	void GenerateFBO(unsigned int width, unsigned int height);

public:

	

	//Get RGBA8 texture from FBO
	unsigned int getRGBATexture();

	//Get alpha texture from FBO
	unsigned int getDepthTexture();

	//resize window
	void resize(unsigned int width, unsigned int height);


	//bind framebuffer
	void bind();

	//unbind framebuffer
	void unbind();
};