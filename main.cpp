/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : MAIN.CPP                  */
/*****************************************************/

#include "jetpack.hpp"

int main(int argc, char *argv[]){

	Jetpack *jeu = new Jetpack;

	jeu->launch();

	delete jeu;

	return 0;
}  
