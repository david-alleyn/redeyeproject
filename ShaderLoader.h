//-------------------------------------------------------------------------------------------------
// Autor: Lucian Petrescu(laborant)
// Data: 28 Sep 2013
//-------------------------------------------------------------------------------------------------

#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


class ShaderLoader {
public:
	static unsigned int loadShader(const std::string &vertex_shader_file, const std::string &fragment_shader_file);
	static unsigned int loadShader(const std::string &vertex_shader_file, const std::string &geometry_shader_file, const std::string &fragment_shader_file);
	static unsigned int _createShader(const std::string &shader_file, GLenum shader_type);
	static unsigned int _createProgram(const std::vector<unsigned int> &shader_objects);
};