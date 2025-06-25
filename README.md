# Logger

This repository contains a simple logger implementation in C, providing a lightweight logging solution for C programs. The logger allows developers to easily log messages at different levels directly to the terminal or command prompt.

## Features

- Log messages at different levels: DEBUG, INFO, WARNING, ERROR.
- Print log messages directly to the terminal/cmd window.
- Designed to work both standalone and as a submodule in larger projects.
- Compatible with AUTOSAR-style `Std_Types.h` definitions using `E_OK`, `E_NOT_OK`.

# Usage

1. To use the logger in your C program, clone the repository:

   ```bash
   git clone https://github.com/StjepanPrakljacic/Logger.git
   ```
2. Clone with Submodule

The Logger depends on shared types defined in `common-config`.

To ensure the dependency is available, clone the repository with submodules:

```bash
git clone --recurse-submodules https://github.com/StjepanPrakljacic/Logger.git
cd Logger
```
If you cloned without --recurse-submodules, initialize manually:

```bash
git submodule update --init --recursive
```

3. Build the Project
   
```bash
mkdir build && cd build
cmake .. -DCOMMON_CONFIG_PATH=../common-config/inc
cmake --build . -- -j4
```

If you're on Windows using MinGW:

```bash
cmake .. -G "MinGW Makefiles" -DCOMMON_CONFIG_PATH=../common-config/inc
mingw32-make
```
4. Run the tests
   
```bash
cd .\build\test\
.\runTests.exe
```

# Contributing
Contributions to the Error Handler project are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request on the GitHub repository.

# License
This project is licensed under the [MIT License](LICENSE).
