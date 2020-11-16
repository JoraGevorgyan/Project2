#       **Account Information System**
#
## General info
   This project will work with a database of Bank accounts.
    There are many ways to work with them, and when the program finishes, all the data will be saved in the base file.

## **Setup**
    To compile and run this project, you need to run the following commands in your terminal.
    Ued g++ version: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
    Used cmake version 3.16.3
#
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
### *A project created using* **[nlohmann/json](https://github.com/nlohmann/json)** *library.*
#
## ***The Structure Of The File Location***

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
|   |   |__ CMakeLists.txt ........................... description for libraries
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
