# mai-ead-enigne
enigne is the next powerful engine

## additionaly implemented
* different build system -> `cmake`
* different error handling
* different state-of-the-art directories for libraries (online guideline cited it as state of the art)

## development

### requirements
* `cmake` version >= `3.21`
* `make`
* c++ `compiler` 

### compile project

#### via command line

* create `./build` directory and `cd build` into it
* execute `cmake .. && make -j` for building the project

#### via clion
* project should automatically recognise cmake file (tested on macOS only)


### run project
* `./build/Sandbox/Sandbox`