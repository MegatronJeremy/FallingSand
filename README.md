# Falling Sand

A small falling sand simulation that runs in the Windows console. Particles live on a grid and are
updated cell by cell each frame, then redrawn as colored characters through the Win32 console API.
The current scene drips water from the top of the map until it settles.

One of my first C++ projects (2021).

## Building

Windows only, since it draws through `windows.h`.

```sh
cmake -S . -B build
cmake --build build
build\Debug\FallingSand.exe
```
