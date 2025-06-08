#include <string>
#include <glad/glad.h>
#include "spdlog/spdlog.h"

#include "shaderLoader.hpp"
#include "utils.hpp"


GLuint compileShader(GLenum type, const std::string& source) {
  unsigned int shader = glCreateShader(type);
  const char* src = source.c_str();

  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  GLint success;
  char infoLog[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
    spdlog::error("COMPILATION_FAILED: {}", infoLog);
    return 0;
  }

  return shader;
}

GLuint createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader) {
  std::string vertexSource = readFile(vertexShader);
  std::string fragmentSource = readFile(fragmentShader);

  GLuint vertexShaderId = compileShader(GL_VERTEX_SHADER, vertexSource);
  GLuint fragmentShaderId = compileShader(GL_FRAGMENT_SHADER, vertexSource);

  GLuint program = glCreateProgram();
  glAttachShader(program, vertexShaderId);
  glAttachShader(program, fragmentShaderId);
  glLinkProgram(program);

  glDeleteShader(vertexShaderId);
  glDeleteShader(fragmentShaderId);

  // Check link status
  GLint success;
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetProgramInfoLog(program, 512, nullptr, infoLog);
    spdlog::error("PROGRAM_LINK_FAILED: {}", infoLog);
    return 0;
  }

  return program;
}
