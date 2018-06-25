IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -Wall

ODIR = obj
LDIR = ../lib

LIBS = -lm -lcurses

_DEPS = menu.h config.h game.h spaceship.h barrier.h element.h enemySpaceship.h \
movingElement.h shot.h userSpaceship.h utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o menu.o game.o spaceship.o barrier.o element.o enemySpaceship.o \
movingElement.o shot.o userSpaceship.o utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

spaceInvaders: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY = clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
