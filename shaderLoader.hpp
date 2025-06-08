#ifndef SHADER_LOADER_HPP
#define SHADER_LOADER_HPP

#include <string>
#include <glad/glad.h>

GLuint compileShader(GLenum type, const std::string& source);
GLuint createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

#endif
