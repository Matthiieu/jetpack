/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BRIOCHE.CPP               */
/*****************************************************/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "brioche.hpp"


using namespace std;

Brioche:: Brioche(){ 
	brioche_.loadFromFile("Pictures/bread.png");
	sprite_brioche_ = new sf::Sprite;
	sprite_brioche_->setTexture(brioche_);
	sprite_brioche_->setScale(ECHELLE_BRIOCHE, ECHELLE_BRIOCHE);
	xf_ = 800;
	yf_ = 200;
}

Brioche:: ~Brioche(){
	delete sprite_brioche_;
}

void
Brioche:: setPosition (int x, const int y){
  	 	xf_ = x;
   	 	yf_ = y;
}

void 
Brioche:: launch(int X, const int Y){
	xf_ = xf_ - X;
	yf_ = yf_ - Y;
	sprite_brioche_->move(xf_, yf_);
}

void
Brioche:: display(sf::RenderTarget *rt){
		sprite_brioche_->setPosition(xf_, yf_);
		rt->draw(*sprite_brioche_);
}

int 
Brioche:: generator_number(){
	// Génerer un nombre entre 0 et 550!
	srand(time(NULL));
	int alea = rand() % 550;
	return alea;
}

bool
Brioche:: from_scratch(bool boolean){
	if (boolean){
		xf_ = 800;
		return true;
	}
	else 
		return false;
}

bool
Brioche:: far_away(int x){
	if (x < (-10))
		return true;
	else
		return false;
}

int 
Brioche:: getX(){
    return xf_;
}

int
Brioche:: getY(){
    return yf_;
}
