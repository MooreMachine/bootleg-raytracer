# Bootleg Ray Tracer
![Tests](https://github.com/MooreMachine/bootleg-raytracer/workflows/Tests/badge.svg)

A bootleg ray tracing project by a bunch of proud Mexicans. Based on [_Ray Tracing in One Weekend_ ](https://raytracing.github.io/books/RayTracingInOneWeekend.html) (version 3.2.3) by Peter Shirley.

## Installation

To fastest way to start developing in a Unix system is with Docker (engine 19.03 or later).

Download the repository:

```bash
git clone --recurse-submodules https://github.com/MooreMachine/bootleg-raytracer.git
cd bootleg-raytracer
```

And verify that the project can be compiled and run:

```
./execute_tests.sh
```

### Toolchain

Our Docker-based toolchain contains all the necessary tools to build the application. We use CMake to generate the Makefiles to build our unit tests and the ray tracer. To read more about our toolchain, check out the [toolchain README.md file](toolchain/README.md).

## Development

The source code is organized into four different directories inside the [code](code) directory:

- [include](code/include) contains header files. There are a few header-only modules.
- [lib](code/lib) contains implementation (`.cpp`) files. For every file here, there is a corresponding header file in [include](code/include).
- [src](code/src) contains application code that does not belong to the `raytracerlib` library. Right now, the only file here is [main.cpp](code/src/main.cpp), which brings together the different modules in the library.
- [tests](code/tests) has all our unit test files.

To create a new module, let's call it `my_module`, create two new files: `include/my_module.h` and `lib/my_module.cpp`. Include `lib/my_module.cpp` in the list of `LIB_FILES` in [CMakeLists.txt](code/CMakeLists.txt).

### Building

To build the application or the unit tests, you can choose to run [execute_tests.sh](execute_tests.sh). However, if you want to manually run either the application or the tests, it's easier to launch an interactive Docker container with [run_interactive_container.sh](run_interactive_container.sh). The first time you build either the application or the unit tests, you'll want to do the following:

```bash
mkdir build
cd build
cmake ..
make raytracerlib
make raytracer
make raytracer_tests
make # if you want to build all previous targets at once
```

Alternatively, we provide a couple of scripts to this: [build_app.sh](code/build_app.sh) and [build_unit_tests.sh](code/build_unit_tests.sh).

Executables are saved in `build/bin` and libraries are in `build/lib`.

### Testing

We use [GoogleTest](https://github.com/google/googletest) for our unit tests. [unit_tests.cpp](code/tests/unittests/unit_tests.cpp) contains the entry point, `main`, to all our unit tests. If you are creating a new module in [lib](code/lib), add a corresponding test file `tests/unittests/test_my_module.cpp`. Add this new file to the list of `TEST_FILES` in [tests/CMakeLists.txt](code/tests/CMakeLists.txt).

A basic `test_my_module.cpp` file will include the following boilerplate code:

```C++
#include "my_module.h"
#include "gtest/gtest.h"

TEST(TestSuiteName, TestName) {
    // your assertions go here
}
```

Our unit tests are automatically run with [GitHub Actions](https://docs.github.com/en/actions) whenever we `push` something new to our remote repository. In a nutshell, the workflow is described in [.github/workflows/main.yml](.github/workflows/main.yml) and it consists of multiple steps:

- First, we check out [our repository](https://github.com/MooreMachine/bootleg-raytracer).
- Then we run all our build and unit tests as described in [action.yml](action.yml).
- [execute_tests.sh](execute_tests.sh) will launch a Docker container and build both the application and the unit tests, and run them all.
- At each step in [execute_tests.sh](execute_tests.sh), the result is assigned to a variable `*_result` which is propagated to the main workflow.
- [.github/workflows/main.yml](.github/workflows/main.yml) checks these results and reports any failures.
- If every test passes, we exit with a "success" message.

### Style

#### Naming conventions

We are trying to follow the naming conventions laid out in the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Naming). The most important rules are:

- Classes use upper `CamelCase`
- Member functions use upper `CamelCase`
- Except for _getters_ and _setters_, which use lower `camelCase`

#### Sorting header files

Header files should be sorted in the following order:

1. If applicable, `.h` file corresponding to this `.cpp` file
1. Headers from the same module
1. Headers from other modules
1. System headers

Headers in each category should be sorted alphabetically.

Reserve angle brackets (`< >`) for system headers.

For example:

```C++
#include "my_module.h"

#include "utils.h"
#include "vector.h"

#include "external/external_module.h"

#include <cmath>
#include <iostream>
```

## Version control

We intend to use [semantic versioning 2.0.0](https://semver.org/spec/v2.0.0.html) to keep track of new versions of this repository. Document any official changes in the [CHANGELOG.md](CHANGELOG.md) file.

### Git

Ideally, the `master` branch should only contain changes that pass all our tests. Most changes should be pushed to a development branch first. I like to name my branches `my_new_branch` because Vim autocompletes strings like that, but not `my-new-branch`.

## About

Version: 0.1.0
