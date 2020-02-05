INCLUDE = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin
DOC = ./doc
DAT = ./datos

usoguia: guiatlf.o usoguia.o
	g++ -I$(INCLUDE) -o $(BIN)/usoguia $(OBJ)/guiatlf.o $(OBJ)/usoguia.o
	
guiatlf.o: $(SRC)/guiatlf.cpp
	g++ -I$(INCLUDE) -o $(OBJ)/guiatlf.o -c $(SRC)/guiatlf.cpp
	
usoguia.o: $(SRC)/usoguia.cpp
	g++ -I$(INCLUDE) -o $(OBJ)/usoguia.o -c $(SRC)/usoguia.cpp

Doxygen:
	doxygen

Prueba: usoguia
	$(BIN)/usoguia $(DAT)/guia.txt

Clean :
	rm $(BIN)/* $(OBJ)/*
