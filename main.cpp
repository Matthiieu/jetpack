#include "jetpack.hpp"

int main(int argc, char *argv[]){

	Jetpack *jeu = new Jetpack;

	jeu->launch();

	delete jeu;

	return 0;
}
