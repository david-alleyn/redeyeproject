#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "FBO.h"

FBO::FBO(unsigned int width, unsigned int height) {
	GenerateFBO(width, height);
}

FBO::~FBO() {
	destroy();
}

void FBO::destroy() {
	glDeleteFramebuffers(1, &fbo);
	glDeleteTextures(1, &rgbTexture);
	glDeleteTextures(1, &depthTexture);
}

void FBO::GenerateRGBA8Texture(unsigned int width, unsigned int height) {

	glGenTextures(1, &rgbTexture);
	glBindTexture(GL_TEXTURE_2D, rgbTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
}

void FBO::GenerateDepthTexture(unsigned int width, unsigned int height) {

	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);

}

void FBO::GenerateFBO(unsigned int width, unsigned int height) {

	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	GenerateRGBA8Texture(width, height);
	GenerateDepthTexture(width, height);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, rgbTexture, 0);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

	drawbuffer.push_back(GL_COLOR_ATTACHMENT0);
	glDrawBuffers(drawbuffer.size(), &drawbuffer[0]);

	//Check if FBO is complete. Incomplete FBOs don't work
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		throw "Framebuffer incomplete!!";
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

unsigned int FBO::getRGBATexture() {
	return rgbTexture;
}

unsigned int FBO::getDepthTexture() {
	return depthTexture;
}

void FBO::resize(unsigned int width, unsigned int height) {
	destroy();
	GenerateFBO(width, height);
}

void FBO::bind() {

	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	//This is done seperate from GenerateFBO because of the need for multiple render targets

}

void FBO::unbind() {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
