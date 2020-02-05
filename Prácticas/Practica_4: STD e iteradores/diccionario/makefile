INCLUDE = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin
DOC = ./doc
DAT = ./datos

usodiccionario: usodiccionario.o
	g++ -I$(INCLUDE) -o $(BIN)/usodiccionario $(OBJ)/usodiccionario.o
	
usodiccionario.o: $(SRC)/usodiccionario.cpp
	g++ -I$(INCLUDE) -o $(OBJ)/usodiccionario.o -c $(SRC)/usodiccionario.cpp

Prueba: usodiccionario
	$(BIN)/usodiccionario < $(DAT)/data.txt

Clean :
	rm $(BIN)/* $(OBJ)/*
