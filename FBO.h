#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>

class FBO {

private:

	unsigned int fbo;                   //framebuffer object
	unsigned int rgbTexture;
	unsigned int depthTexture;
	std::vector<GLenum> drawbuffer;     //add texture attachements

public:

	FBO();

	~FBO();

private:

	//delete objects
	void destroy();


	//generate an RGBA8 texture with bilinear filtering
	void GenerateRGBA8Texture(unsigned int width, unsigned int height);



	//generate a single channel depth texture with bilinear filtering
	void GenerateDepthTexture(unsigned int width, unsigned int height);

public:

	//Generate FBO
	void GenerateFBO(unsigned int width, unsigned int height);

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