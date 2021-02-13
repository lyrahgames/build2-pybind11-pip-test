PYTHON = python
PYBIND11_INCLUDES = $(shell $(PYTHON) -m pybind11 --includes)
PYTHON_PREFIX = $(shell $(PYTHON) -c "import sys; print(sys.prefix)")
PYTHON_VERSION_MAJOR = $(shell $(PYTHON) -c "import sys; print(sys.version_info.major)")
PYTHON_VERSION_MINOR = $(shell $(PYTHON) -c "import sys; print(sys.version_info.minor)")

# build2 configuration files are also valid makefiles.
include build/bootstrap/out-root.build

# OUT_ROOT = $(shell cat build/bootstrap/out-root.build | grep out_root | sed -En "s/out_root = (.*)/\1/p")
# $(info $(OUT_ROOT))
# $(info $(out_root))
# $(info $(CONFIG))
# TEST = $(shell sqlite3 -list "../.bdep/bdep.sqlite3" "SELECT path FROM configuration WHERE name='$(CONFIG)'")
# $(info $(TEST))

.PHONY: default clean install uninstall test

default:
	b configure config.pxart_python.pybind11.includes="$(PYBIND11_INCLUDES)" config.pxart_python.python.prefix="$(PYTHON_PREFIX)" config.pxart_python.python.version.major="$(PYTHON_VERSION_MAJOR)" config.pxart_python.python.version.minor="$(PYTHON_VERSION_MINOR)"
	b -v

clean:
	b clean

install:
	$(PYTHON) -m pip install $(out_root)

uninstall:
	$(PYTHON) -m pip uninstall pxart

test:
	$(PYTHON) tests/main.py