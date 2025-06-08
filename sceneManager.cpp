#include "sceneManager.hpp"


SceneManager::SceneManager() {

}

SceneManager::~SceneManager() {
  unload();
}

void SceneManager::update(float delta) const {
  if (!m_scene) {
    return;
  }

  m_scene->update(delta);
}

void SceneManager::render() const {
  if (!m_scene) {
    return;
  }
  m_scene->render();
}

void SceneManager::unload() const {
  m_scene.reset();
}

void SceneManager::load(const std::string & file) const {
  YAML::Node config = YAML::LoadFile(file);

}

