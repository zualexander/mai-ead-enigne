# mai-ead-enigne
enigne is the next powerful engine

## additionaly implemented
* different OS (developed on macOS)
* different build system -> `cmake`
* different error handling
* different state-of-the-art directories for libraries (online guideline cited it as state of the art)

## development

### requirements
* `cmake` version >= `3.21`
* `make`
* c++ `compiler` 

### checkout project including submodules

* clone project
* init submodules with `git submodule init && git submodule update`

### build project

#### via command line
* create `./build` directory and `cd build` into it
* execute `cmake .. && make -j` for building the project

#### via clion
* project should automatically recognise cmake file (tested on macOS only)


### run project
* `./build/Sandbox/Sandbox`