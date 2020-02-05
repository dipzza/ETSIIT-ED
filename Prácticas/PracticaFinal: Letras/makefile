INCLUDE = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin
DOC = ./doc
DAT = ./data

CC = g++ 

$(BIN)/letras: $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o $(OBJ)/bolsaLetras.o $(OBJ)/letras.o
	$(CC) -I$(INCLUDE) -o $@ $^

$(BIN)/cantidadLetras: $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o $(OBJ)/bolsaLetras.o $(OBJ)/cantidadLetras.o
	$(CC) -I$(INCLUDE) -o $@ $^

$(BIN)/testdiccionario: $(OBJ)/diccionario.o $(OBJ)/testdiccionario.o
	$(CC) -I$(INCLUDE) -o $@ $^

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INCLUDE)/diccionario.h
	$(CC) -I$(INCLUDE) -c $(SRC)/diccionario.cpp -o $@

$(OBJ)/letra.o: $(SRC)/letra.cpp $(INCLUDE)/letra.h
	$(CC) -I$(INCLUDE) -c $(SRC)/letra.cpp -o $@

$(OBJ)/conjuntoLetras.o: $(SRC)/conjuntoLetras.cpp $(INCLUDE)/conjuntoLetras.h $(INCLUDE)/letra.h
	$(CC) -I$(INCLUDE) -c $(SRC)/conjuntoLetras.cpp -o $@

$(OBJ)/bolsaLetras.o: $(SRC)/bolsaLetras.cpp $(INCLUDE)/conjuntoLetras.h $(INCLUDE)/letra.h $(INCLUDE)/bolsaLetras.h
	$(CC) -I$(INCLUDE) -c $(SRC)/bolsaLetras.cpp -o $@

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp $(INCLUDE)/diccionario.h
	$(CC) -I$(INCLUDE) -c $(SRC)/testdiccionario.cpp -o $@

$(OBJ)/cantidadLetras.o: $(SRC)/cantidadLetras.cpp $(INCLUDE)/diccionario.h $(INCLUDE)/conjuntoLetras.h $(INCLUDE)/letra.h
	$(CC) -I$(INCLUDE) -c $(SRC)/cantidadLetras.cpp -o $@

$(OBJ)/letras.o: $(SRC)/letras.cpp $(INCLUDE)/conjuntoLetras.h $(INCLUDE)/diccionario.h $(INCLUDE)/bolsaLetras.h $(INCLUDE)/letra.h
	$(CC) -I$(INCLUDE) -c $(SRC)/letras.cpp -o $@

Doxygen:
	doxygen

PruebaL: $(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras_spanish.txt
	$(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras_spanish.txt 8 -L

PruebaP: $(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras_spanish.txt
	$(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras_spanish.txt 8 -P

PruebaDiccionario: $(BIN)/testdiccionario $(DAT)/diccionario500.txt
	$(BIN)/testdiccionario $(DAT)/diccionario500.txt

PruebaCantidad: $(BIN)/cantidadLetras $(DAT)/spanish.txt $(DAT)/letras_spanish.txt
	$(BIN)/cantidadLetras $(DAT)/spanish.txt $(DAT)/letras_spanish.txt $(DAT)/salida.txt

Clean :
	rm $(BIN)/* $(OBJ)/*
