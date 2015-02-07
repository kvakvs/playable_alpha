#!/usr/bin/make -f

.PHONY: build
build: _build
	cd _build && $(MAKE) -j4

_build:
	mkdir _build && cd _build && cmake -G "Unix Makefiles" .. && $(MAKE) -j4

.PHONY: rebuild
rebuild:
	rm -rf _build && $(MAKE) build
