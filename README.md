# Playable Alpha

Name is everything, naming is hardest problem for developer to solve and is 75% of success.

So this is going to be a 2D roguelike, based on imagination and Nethack rules written with
C++ and HGE-unix (which runs on OpenGL).

## Prerequisites

* SDL development libraries and headers
* Clang (may work with GCC, using clang for stricter linting and warnings)
* Git (for obvious reasons)
* CMake 2.8+

## Building

* Checkout `git clone https://github.com...`
* Update submodule (hge2): `git submodule update --init`
* Run make (requires CMake and Clang installed but probably will run on GCC too)
