#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "object.hpp"


class Triangle : public Object {
  public:
    Triangle(const glm::vec2 & size) {

      const float vertices[] = {
        -size.x, -size.y, 0.0f,
        size.x, -size.y, 0.0f,
        0.0f,  size.y, 0.0f
      };


      glGenVertexArrays(1, &m_vao);
      glGenBuffers(1, &m_vbo);

      glBindVertexArray(m_vao);
      glBindBuffer(GL_ARRAY_BUFFER, m_vao);

      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

      glEnableVertexAttribArray(0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);
    }

    ~Triangle() {
      glDeleteVertexArrays(1, &m_vao);
      glDeleteBuffers(1, &m_vbo)
    }

    void render() const {
      glBindVertexArray(m_vao);
      glDrawArrays(GL_TRIANGLES, 0, 3);
    }
protected:
  unsigned int m_vbo, m_vao;
}


#endif
