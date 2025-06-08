#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>

// Treated as a physical object in the 3D world. Lighting/3D objects
class Object {
public:
  virtual ~Object() = default;
  virtual void render() const = 0;

  void updatePosition(const glm::vec3 position) {
    m_position = position;
  }

  void updateRotation(const glm::vec3 rotation) {
    m_rotation = rotation;
  }

protected:
  glm::vec3 m_position;
  glm::vec3 m_rotation;
};

#endif
