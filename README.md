# build2-pybind11-pip Test

build2-Based Header-Only C++ Library wrapped by pybind11 into a Python-callable binary module installable by pip.

## Requirements
- C++11
- Linux: GCC | Clang
- Windows MSVC
- Python3
- Pybind11

## Build, Installation, and Test Instructions

    git clone https://github.com/lyrahgames/build2-pybind11-pip-test.git
    cd build2-pybind11-pip-test
    bdep init -C @gcc cc config.cxx=g++ "config.cxx.coptions=-O3 -march=native"
    cd python
    make
    make install
    make test

Sadly, we cannot directly call the Python executable the build2 buildfiles, yet.
Instead a simple makefile is used to get the most important information from the currently used Python installation.
The default is the command `python`.
To change it for the makefile, use the `PYTHON` variable.

    make PYTHON=python3
    make PYTHON=python3 install
    make PYTHON=python3 test

