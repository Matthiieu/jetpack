
#include "background.hpp"

int 
Background:: generator_number1(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea1 = rand() % 100;
	return alea1;
}

int 
Background:: generator_number2(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea2 = (rand() % 255) - 50;
	if (alea2 < 0)
		alea2 = 0;
	return alea2;
}

int 
Background:: generator_number3(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea3 = (rand() % 150) - 20;
	if(alea3 < 0)
		alea3 = 20;
	return alea3;
}

