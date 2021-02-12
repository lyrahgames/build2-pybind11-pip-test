PYTHON = python3
PYBIND11_INCLUDES = $(shell $(PYTHON) -m pybind11 --includes)

OUT_ROOT = $(shell cat build/bootstrap/out-root.build | grep out_root | sed -En "s/out_root = (.*)/\1/p")

# $(info $(OUT_ROOT))
# $(info $(CONFIG))
# TEST = $(shell sqlite3 -list "../.bdep/bdep.sqlite3" "SELECT path FROM configuration WHERE name='$(CONFIG)'")
# $(info $(TEST))

.PHONY: default clean install uninstall test

default:
	b disfigure
	b configure: config.cxx.poptions+="$(PYBIND11_INCLUDES)"
	b

clean:
	b clean
	b disfigure

install: default
	$(PYTHON) -m pip install $(OUT_ROOT)

uninstall:
	$(PYTHON) -m pip uninstall pxart

test:
	$(PYTHON) tests/main.py