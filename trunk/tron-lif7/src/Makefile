CC=gcc
CFLAGS=-Wall -ggdb -pedantic
EXEC_NAME= ../bin/jeu
LIBS= #-lSDL
OBJ_FILES= TableauDynamique.o Grid.o Control.o Jeu.o Moto.o Mur.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC_NAME)  $(LIBS)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm $(OBJ_FILES)
