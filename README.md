Sterne Framework
===============

Game engine framework. Written in C++ and Python.

### Dependencies

1. python3.2-dev
2. libsfml (>= 2.0)

### Building and running

	$ make
	$ cd build && ./main

### Building on Ubuntu

Since this engine requires `libsfml` version __>= 2.0__ and Ubuntu (12.04 to 13.04)
only provides __1.6__, you have to install `libsfml2` yourself using one of
these methods:

1. Find a ppa and install it from there
2. Install pre-built libs from http://www.sfml-dev.org/
3. Compile libsfml yourself

#### Using pre-built libsfml

The second methods is the simplest and we'll be using it for 12.10 and 13.04 but
not for 12.04 as the pre-built binary depends on `libGLEW 1.7` whilst 12.04 has
1.6. People using 12.04 should follow instructions on compiling `libsfml2` below,
then come back here for instructions for running.

Download the [tarball][1] and extract it inside `sterne-framework` source code
directory, named as `sfml`. It will have this tree structure:

    sfml
     |
     +- lib
     |
     +- include
     |
     +- share

The normal way for `g++` to detect and include these libaries is to have them
installed in system directories (i.e. `/usr/lib/` and `/usr/include`) but it's
better to separate system libraries and personal libaries. Run these commands
to build and run the demo program with our custom libraries:

    $ export CPLUS_INCLUDE_PATH=sfml/include
    $ export LIBRARY_PATH=sfml/lib
    $ make
    $ export LD_LIBRARY_PATH=$(pwd)/sfml/lib
    $ cd build
    $ ./main

[1]: http://www.sfml-dev.org/download/sfml/2.1/

#### Building libsfml

This command should install all build-time dependencies (thanks to
the Debian Games Team <pkg-games-devel@lists.alioth.debian.org>):

	$ sudo apt-get build-dep libsfml-dev

Then proceed to building libsfml:

	mkdir build
	cd build
	cmake -DCMAKE_INSTALL_PREFIX:PATH=sfml ..
	make -j4
	cp -R sfml /path/to/stern-framework/

