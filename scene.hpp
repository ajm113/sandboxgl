#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "object.hpp"

class Scene {
public:
  Scene()
  ~Scene() {
    m_objects.clear();
  };

  virtual void render() const = 0;
  
protected:
  std::vector<std::unique_ptr<Object>> m_objects;
};


#endif
