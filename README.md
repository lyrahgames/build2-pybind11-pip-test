# build2-pybind11-pip Test

build2-Based Header-Only C++ Library wrapped by pybind11 into a Python-callable binary module installable by pip.

## Requirements
- Standard: C++11
- Compiler: GCC | Clang | MSVC
- Operating System: Linux | Windows | MacOS
- build2 >= 0.13.0
- Python ^ 3.0.0
- pip
- Pybind11 ^ 2.6.0 

# Explanation and Adjustment
Sadly, we cannot directly call the Python executable inside the build2 buildfiles directly, yet.
Instead a simple makefile is used to get the most important information from the currently used Python installation.
The default is the command `python`.
To change it for the makefile, use the `PYTHON` variable.

    make PYTHON=python3
    make PYTHON=python3 install
    make PYTHON=python3 test

# Linux / MacOS
## Build, Installation, and Test Instructions

Clone the repository and change into the directory.

    git clone https://github.com/lyrahgames/build2-pybind11-pip-test.git
    cd build2-pybind11-pip-test

Initialize the default build2 configuration with GCC or Clang.
We recommend maximum compiler optimization.

    bdep init -C @gcc cc config.cxx=g++ "config.cxx.coptions=-O3 -march=native"

Afterwards, traverse to the `python` directory and build the library by using Make.
This calls the Python executable to get important information and initializes configuration variables by using `b configure`.
Then `b` is called to build the library.

    cd python
    make # Probably, this one has to be called two times.

On some platforms, the last command fails the first time.
Run it a second time and everything should be fine.

At the end, the generated Python package should be installed and tested.

    make install
    make test

At this point, you are able to import a new module `pxart` in Python and run its function `monte_carlo_pi(n)` to estimate the value of π.

## Windows
In my opinion, you should really consider to use Linux in the future.
But if you are brave enough then try the following.

### Requirements
List of Requirements:
- [Git](https://)
- Make
- [MSVC](https://visualstudio.microsoft.com/downloads/)
- [build2](https://build2.org)
- [Python](https://www.python.org)
- pip
- [Pybind11](https://github.com/pybind/pybind11)

We emphasize to use a package manager, like [Chocolatey](https://chocolatey.org/), for Windows.
This will not always work but will make things easier from time to time.

For Git and Make, use Chocolatey like in the following listing or install them by hand.

    choco install git
    choco install make

The [Microsoft Visual Studio C++ compiler build tools](https://visualstudio.microsoft.com/downloads/) should not be installed by Chocolatey.
Things are likely to break here.
Install the build tools manually.
Make sure after the installation the `x64 Native Tools Command Prompt for VS 2019` or some alternative is available.

[build2](https://build2.org) has to be manually compiled by any compiler and not necessarily by MSVC.
Go to the webpage and follow the installation instructions for Windows, but maybe enable the trusted installation options.
Make sure to add build2 to the path environment variable to be able to call it from the command line.

Last but not least, install [Python](https://www.python.org/) (also possible by Chocolatey) and [Pybind11](https://github.com/pybind/pybind11) by using `pip`.
Anaconda is currently not working.
Help is welcome to get rid of errors.

    choco install python
    python -m pip install pybind11

### Build, Test, and Installation Instructions
Make sure to have a terminal where all requirements are available through environment variables, like the `x64 Native Tools Command Prompt for VS 2019`, or set all the path variables yourself.

Clone the repository and change into the directory.

    git clone https://github.com/lyrahgames/build2-pybind11-pip-test.git
    cd build2-pybind11-pip-test

Initialize the default build2 configuration.
You have to use MSVC because Python does not allow to build `.pyd` libraries by MinGW.

    bdep init -C @gcc cc config.cxx=cl "config.cxx.coptions=/O2"

Afterwards, traverse to the `python` directory and build the library by using Make.

    cd python
    make # Probably, this one has to be called two times.

On some platforms, the last command fails the first time.
Run it a second time and everything should be fine.

At the end, the generated Python package should be installed and then tested.

    make install
    make test

At this point, you are able to import a new module `pxart` in Python and run its function `monte_carlo_pi(n)` to estimate the value of π.