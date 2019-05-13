# Author: Sanjo Abraham
#Description: makefile for the predator prey game

#Project Name
PROJ = PredatorPrey_Group24

SRC = main.cpp
SRC += Ant.cpp
SRC += Critter.cpp
SRC += Doodlebug.cpp
SRC += Edge.cpp
SRC += Game.cpp
SRC += Menu.cpp
SRC += RNG.cpp
SRC += inputValidation.cpp


OBJ = $(SRC:.c=.o)

output: $(OBJ) 
	g++ $(SRC)   -std=c++11 -o output

main.o: %.h main.cpp

clean: 
	rm *.o output
zip: 
	zip $(PROJ).zip *.cpp *.hpp makefile
