CC = g++
CFLAGS := -std=c++11 -Wall -Wfatal-errors -c -ggdb
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
BIN = main
OBJ = main.o  personnage.o bouton.o menu.o neon.o fusee.o background.o jetpack.o
all: .depend $(BIN)

$(BIN): $(OBJ)
	$(CC)  $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.depend: *.hpp *.cpp
	@echo -n > .depend
	@$(foreach obj,$(OBJ), g++ -MM $(subst .o,.cpp,$(obj)  $(CFLGAS) ) >> .depend;)

-include .depend

clean::
	rm -f *~ $(OBJ) $(BIN) .depend
