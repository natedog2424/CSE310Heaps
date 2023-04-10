# Project 1: Min Heap

This project impliments a min heap data structure in c++ along with a set of commands to interface with the heap.

## Build Instructions

Build to executable `main` using `make` command or simply use `make run` to build and run the executable.
```make clean``` is also available in the event that the build directory needs to be cleaned.

## Directory Structure (after build)
```
.
├── obj/
│   ├── Heap.o
│   ├── Main.o
│   └── util.o
├── src/
│   ├── Heap.cpp
│   ├── Heap.h
│   ├── HeapElement.h
│   ├── Main.cpp
│   ├── Util.cpp
│   └── Util.h
├── Makefile
├── main
└── README.MD
```
Running make compiles all .cpp files in src to .o files and places them in the obj directory. All .o files are then linked to the main executable at the root directory.

## Implementation Notes

The project consists of: `Heap` and `Util` classes, the `HeapElement` struct, and a file `Main.cpp` that contains the main function. The main function is responsible for handling the user's input and dispatching heap events accordingly. The `Util` class provides utility methods for getting the user's next command, extracting arguments from the command, and reading files into an array. A `command` enum is used within the util class to abstract constant values and provide readability to both the util class and the main function. The heap class implements all necessary functions for creating and manipulating a min heap. Notable implementations include the resize method which can take in any size for heap and allocate new memory to fill that heap capacity using `realloc`. In the event that the `realloc` call fails, the method can create a new array using the `new` keyword and copy the contents into the new array. The insert method inserts a new `HeapElement` into the heap with a given key. If the heap is already at capacity, it must be resized to fit the new element. The size for the array is determined by selecting the nearest power of 2 that is greater than the current capacity. In order to determine the nearest power of 2, bit twiddling is used as described in the resource listed below. The `MinHeapify` and `BuildHeap` methods are implemented directly accordingly to the textbook implementation. **Note, all methods in the Heap class use 0 indexing so inputs are decremented by the main function before being sent to the Heap class**

## Resources

- [Google Style Guide](https://google.github.io/styleguide/cppguide.html#Type_Names) referenced to ensure consistent style.
- [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2) used for rounding to the nearest power of 2.