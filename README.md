# build2-pybind11-pip Test

build2-Based Header-Only C++ Library wrapped by pybind11 into a Python-callable binary module installable by pip.

## Requirements
- Standard: C++11
- Compiler: GCC | Clang | MSVC
- Operating System: Linux | Windows | MacOS
- [build2](https://build2.org/) >= 0.13.0
- [Python](https://www.python.org/) ^ 3.0.0
- pip
- [Pybind11](https://pybind11.readthedocs.io/en/stable/) ^ 2.6.0 

# Explanation and Adjustment
The build2 build system uses a custom configuration variable to hold the value for the Python executable.
This variable also encodes the used version of the Python environment.
The default value is `python`.
On some platforms, this command may be linked to Python 2 and therefore must be adjusted.
To tweak or customize the used version, use the following command inside the `python` directory after a successful initialization of a persistent configuration done in the following sections.

    b configure "config.pxart_python.python=python3"

After compiling the wrapper library, pip is used to install the generated Python package.
This installation process seems only to link against the configuration folder.
For now, the configuration and source code need to reside at their locations to make the Python package work.
For a full installation, somehow an archive has to be created and fed into Python and the pip package manager.
This is not done here.

# Linux / MacOS
## Build, Installation, and Test Instructions

Clone the repository and change into the directory.

    git clone https://github.com/lyrahgames/build2-pybind11-pip-test.git
    cd build2-pybind11-pip-test

Make sure that Pybind11 is already installed.
Otherwise the initialization of the build2 configuration will abort.
If that happens then remove the created configuration first by `bdep config remove @gcc` and run the following initialization process again with an appended `--wipe` option.

Initialize the default build2 configuration with GCC or Clang.
We recommend maximum compiler optimization.

    bdep init -C @default cc config.cxx=c++ "config.cxx.coptions=-O3 -march=native"

Afterwards, traverse to the `python` directory and adjust the used Python executable as described in the previous section, if needed.
Then build the library by using `b`.
This calls the configured Python executable to get important information needed for the compilation.

    cd python
    b

At the end, the generated Python package should be installed and tested.
The output should be some statistical approximation to the number π.

    b install
    python tests/main.py

At this point, you are able to import a new module `pxart` in Python and run its function `monte_carlo_pi(n)` to estimate the value of π.

To uninstall the library call the following command.

    b uninstall

## Windows
In my opinion, you should really consider to use Linux in the future.
But if you are brave enough then try the following.

### Requirements
List of Requirements:
- [Git](https://)
- [MSVC](https://visualstudio.microsoft.com/downloads/)
- [build2](https://build2.org)
- [Python](https://www.python.org)
- pip
- [Pybind11](https://github.com/pybind/pybind11)

We emphasize to use a package manager, like [Chocolatey](https://chocolatey.org/), for Windows.
This will not always work but will make things easier from time to time.

For Git, use Chocolatey like in the following listing or install them by hand.

    choco install git

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

    bdep init -C @msvc cc config.cxx=cl "config.cxx.coptions=/O2"

Afterwards, traverse to the `python` directory and customize the python executable as stated in the previous section, if needed.
Then build the library by using `b`.

    cd python
    b

At the end, the generated Python package should be installed and then tested.

    b install
    python tests/main.py

At this point, you are able to import a new module `pxart` in Python and run its function `monte_carlo_pi(n)` to estimate the value of π.

To uninstall the library call the following command.

    b uninstall

