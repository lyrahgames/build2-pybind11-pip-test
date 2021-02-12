# build2-pybind11-pip Test

build2-Based Header-Only C++ Library wrapped by pybind11 into a Python-callable binary module installable by pip.

## Instructions

    git clone https://github.com/lyrahgames/build2-pybind11-pip-test.git
    cd build2-pybind11-pip-test
    bdep init -C @gcc cc config.cxx=g++ "config.cxx.coptions=-O3 -march=native"
    cd python
    make install
    make test

