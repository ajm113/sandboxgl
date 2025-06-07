# SandboxGL

A personal sandbox project to experiment with GLSL shaders and OpenGL tech. Ideally the purpose of this project is to
learn how to re-create the same effects games in the early 2000s like DOOM and F.E.A.R did their shaders and create a easy to use tool to expirement such as stencil and shadow mapping.

I don't plan on making this into a full thing, but free to create a PR or open a issue!

## Feature Goals

- Ability to load different scenes and assets.
- Ability to auto reload GLSL fragment and vertex shaders.
- Include everything I learned in a easy to use tool with multiple examples.

## Build Instructions

### Using bash script

`sh ./build.sh`

### Manually using CMake

```bash
git clone https://github.com/ajm113/sandboxgl.git
cd sandboxgl
mkdir build && cd build
cmake ..
make
```

## Other Notes

This is WIP and things are expected to break!
