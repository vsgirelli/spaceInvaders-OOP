IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -Wall

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = menu.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o menu.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

spaceInvaders: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY = clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
