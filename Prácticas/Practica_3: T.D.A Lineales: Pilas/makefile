INCLUDE = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin
DOC = ./doc

prueba : Pila_max_VD.o VDG.o prueba.o
	g++ -I$(INCLUDE) -o $(BIN)/prueba $(OBJ)/Pila_max_VD.o $(OBJ)/VDG.o $(OBJ)/prueba.o

Pila_max_VD.o : $(SRC)/Pila_max_VD.cpp
	g++ -I$(INCLUDE) -o $(OBJ)/Pila_max_VD.o -c $(SRC)/Pila_max_VD.cpp

VDG.o : $(SRC)/VDG.cpp
	g++ -I$(INCLUDE) -o $(OBJ)/VDG.o -c $(SRC)/VDG.cpp

prueba.o : $(SRC)/prueba.cpp
	g++ -I$(INCLUDE) -o $(OBJ)/prueba.o -c $(SRC)/prueba.cpp
	
Doxygen :

Clean :
	rm $(BIN)/* $(OBJ)/*
