IDIR = ../Headers
CC = g++
CFLAGS = -std=c++11 -I$(IDIR) -g

ODIR = ../Objects
LDIR = ../lib

LIBS = -lm

_DEPS = dominios.h entidades.h interfacesApresentacao.h interfacesServico.h controladorasApresentacao.h controladorasServico.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = dominios.o entidades.o controladorasApresentacao.o controladorasServico.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 