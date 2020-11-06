#       **Account Information System**
#
# 
## General info
    This project will work with bank account base.
    There are any options for working with them,
    and when program ended, all data will be saved in the base file.

## Setup
    To run this project you need to run the following commands in your terminal
step 1:
```sh
$ chmod +x ./build.sh
$ ./build.sh
```
step 2:
```sh
$ cd ./_build/program/
```
step 3:
```sh
$ make
$ ./editBase
```
#
### *project created with* **[nlohmann/json](https://github.com/nlohmann/json)** *librery*
#
## ***File Location Structure***

```txt
main directory
|
|__ ./_build/ .... directory for building results (must be made from ./build.sh)
|
|__ ./source/ ............................ directory for source files of project
|   |
|   |__ ./lib/ ......................................... directory for libreries
|   |   |
|   |   |__ account.cpp
|   |   |
|   |   |__ base.cpp
|   |   |
|   |   |__ accountCtrl.hpp ..................................... my header file
|   |   |
|   |   |__ json.hpp ........... nlohmann's librery for working with .json files
|   |   |
|   |   |__ CMakeLists.txt ........................... description for libreries
|   |
|   |__ ./program
|   |   |
|   |   |__ main.cpp
|   |   |
|   |   |__ CMakeLists ........................... description for project files
|   |
|   |
|   |__ CMakeLists.txt ........................... description for program files
|   |
|__ ./build.sh .................................... simple bash script for Cmake
```
