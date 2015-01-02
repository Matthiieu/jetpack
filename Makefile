CC = g++
CFLAGS := -std=c++11 -Wall -Wfatal-errors -c -ggdb
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
BIN = main
OBJ = main.o  character.o button.o menu.o french_stick.o brioche.o background.o jetpack.o cupcake.o heart.o bitcoin.o croissant.o
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
