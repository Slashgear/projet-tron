CC=gcc
CFLAGS=-Wall -ggdb -pedantic
EXEC_NAME= ./bin/jeu
LIBS= -L./lib/FMOD/lib/ -lSDL -lSDL_ttf -lm -lfmodex

OBJDIR=obj
SRCDIR=src

OBJ_FILES= $(OBJDIR)/main.o $(OBJDIR)/Bonus.o $(OBJDIR)/Jeu.o $(OBJDIR)/Controle.o $(OBJDIR)/Grid.o $(OBJDIR)/Joueur.o $(OBJDIR)/Joystick.o $(OBJDIR)/Moto.o $(OBJDIR)/Musique.o $(OBJDIR)/SDL.o $(OBJDIR)/TableauDynamiqueEntier.o $(OBJDIR)/TableauDynamiqueMur.o  $(OBJDIR)/Mur.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC_NAME)  $(LIBS)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm $(OBJ_FILES)
