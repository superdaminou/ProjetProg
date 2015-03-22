# Programming Project 2048

I. Files includes with this project

- README.txt				This file
- CMakeLists.txt			Used to build this project, must be in each (sub)directory of the project

grid					Directory
|- CMakeLists.txt
|- grid.h				Grid header
|- grid.c				Grid implementation (grid source code)
|- play.c				Play implementation (main, display, auto_play)



II. How to build your project and play ?

CMake is used to build this project. Build directory will contain your executables.
Place yourself in the PROJECT ROOT and run theses instructions to generate Makefiles :

- mkdir build
- cd build
- cmake ..


By now Makefiles should be created. Then, to create executables :

- make

To prepare all your tests, run this :

- cmake -Dtest=ON ..

To run all tests easily :

- make test


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

IV. A faire

- Rajouter des tests
- Rajouter commentaires + balises pour la doc






