CC = g++
CFLAGS := -std=c++11 -Wall -Wfatal-errors -c -ggdb -O0
LDFLAGS := -lsfml-window -lsfml-audio -lsfml-graphics -lsfml-system
BIN = main
OBJ = main.o jetpack.o menu.o bouton.o personnage.o

all: depends $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

depends:
	@echo -n > depends
	@$(foreach obj,$(OBJ), g++ -MM $(subst .o,.cpp,$(obj)) >> depends;)

-include depends

clean::
	rm -f $(OBJ) $(BIN) depends
