# Programming Project 2048

I. Files includes with this project

- README.txt				This file
- CMakeLists.txt			Used to build this project, must be in each (sub)directory of the project
- play.c					Play implementation (main, display, auto_play)

grid						Directory
|- CMakeLists.txt
|- grid.h					Grid header
|- grid.c					Grid implementation (grid source code)

test						Directory
|- CMakeLists.txt
|- test_grid.c				This file countains the source code to test functions of grid.c



II. How to build your project and play ?

CMake is used to build this project. Build directory will contain your executables.
Place yourself in the PROJECT ROOT and run theses instructions to generate Makefiles :

- mkdir build
- cd build
- cmake ..


By now Makefiles should be created. Then, to create executable and libgrid.a (grid library) :

- make

To run all tests easily :

- make test

If you want to check detailed tests :

- cd test
- ./test_grid
- cd ..

If everything passed successfully, you can now play :

- ./play

Use Z, Q, S, D to play. Good luck !
Use A to generate a random session.



III. Credits

SEEGERS Aurore
PARPAITE Thibault
LE GARREC Damien

University of Bordeaux, Talence (33)
IN400A4

Lien du dépot git : https://github.com/superdaminou/ProjetProg/commits/master






