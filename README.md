#project2

#line of commands for using project

step 1: chmod +x build.sh
step 2: ./build.sh
step 3: cd _build/program
step 4: ENJOY

#info about file locations for users

this directory
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



