#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Daniele Cássia
# Histórico	: 04-04-2024 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC       = g++
CFLAGS   = -std=c++11 -Wall -I. -I$(INCLUDEDIR)

LINKER   = g++
LFLAGS   = -Wall -I. -I$(INCLUDEDIR) -lm

SRCDIR     = src
INCLUDEDIR = include
OBJDIR     = obj
BINDIR     = bin

DEPS = main

SRC := $(addsuffix .cpp, $(DEPS))

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

EXE := $(BINDIR)/tp0.out

run:  all

# Rule to compile all source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the main executable
all: $(OBJ)
	mkdir -p $(BINDIR)
	$(LINKER) $(LFLAGS) $(OBJ) -o $(BINDIR)/tp0.out

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*