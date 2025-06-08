cmake_minimum_required(VERSION 3.10)
project(sandboxgl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define our asset paths.
set(ASSETS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/data")
set(ASSETS_DEST_DIR "${CMAKE_BINARY_DIR}/data")

set(ASSETS_CONFIG_SOURCE "${CMAKE_SOURCE_DIR}/config.yaml")
set(ASSETS_CONFIG_DEST "${CMAKE_BINARY_DIR}/config.yaml")

# Find and include GLFW
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include")

include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY  https://github.com/gabime/spdlog.git
  GIT_TAG         v1.13.0  # Latest stable version
)

FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG master
)

FetchContent_MakeAvailable(yaml-cpp)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

FetchContent_Declare(
	stb
	GIT_REPOSITORY	https://github.com/nothings/stb.git
	GIT_TAG 	5c205738c191bcb0abc65c4febfa9bd25ff35234 #refs/tags/1.0.1
)

FetchContent_MakeAvailable(stb)

# Copy assets to build dir.
file(COPY "${ASSETS_SOURCE_DIR}" DESTINATION "${ASSETS_DEST_DIR}")
file(COPY "${ASSETS_CONFIG_SOURCE}" DESTINATION "${ASSETS_CONFIG_DEST}")


add_executable(sandboxgl 
    sandboxgl.cpp
    utils.cpp
    shaderLoader.cpp
    external/glad/src/glad.c
)

target_link_libraries(
    sandboxgl
    glfw
    OpenGL::GL
    spdlog::spdlog
    m
    glm::glm
    yaml-cpp::yaml-cpp
)

enable_testing()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(BUILD_GMOCK OFF CACHE BOOL "Disable gMock" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Disable gtest install" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(sandboxgl_test
  sandboxgl_test.cpp
)
target_link_libraries(
  sandboxgl_test
  PRIVATE
  gtest
  gtest_main
  spdlog::spdlog
  m
  glm::glm
  yaml-cpp::yaml-cpp
)

add_test(NAME RunTests COMMAND sandboxgl_test)

include(GoogleTest)
gtest_discover_tests(sandboxgl_test)


