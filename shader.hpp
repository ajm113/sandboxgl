#ifndef SHADER_HPP
#define SHADER_HPP
#include <GLFW/glfw3.h>

class Shader {
public:
  Shader(GLuint program) : m_program(program) {}
  ~Shader() {
    clear();
  }
  void clear() const {
    glDeleteProgram(m_program);
  }
  void use() const {
    glUseProgram(m_program);
  }

  static void unuse() const {
    glUseProgram(0);
  }

protected:
  GLuint m_program;
};


#endif
