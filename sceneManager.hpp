#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <string>
#include "scene.hpp"

class SceneManager {
public:
  SceneManager();
  ~SceneManager();

  void update(float delta) const;
  void render() const;

  void unload() const;
  void load(const std::string & file) const;

protected:
  std::unique_ptr<Scene> m_scene;
};

#endif
