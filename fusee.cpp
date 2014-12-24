#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "fusee.hpp"


using namespace std;

Fusee:: Fusee(){ 
	fusee_.loadFromFile("bread.png");
	//fusee_.setSmooth(true);
	sprite_fusee_ = new sf::Sprite;
	sprite_fusee_->setTexture(fusee_);
	sprite_fusee_->setScale(0.2f, 0.2f);
	xf_ = 800;
	yf_ = 200;
}

Fusee:: ~Fusee(){
	delete sprite_fusee_;
}

void
Fusee:: setPosition (int x, const int y){
  	 	xf_ = x;
   	 	yf_ = y;
}

void 
Fusee:: launch(int X, const int Y){
	xf_ = xf_ - X;
	yf_ = yf_ - Y;
	sprite_fusee_->move(xf_, yf_);
}

void
Fusee:: display(sf::RenderTarget *rt){
		sprite_fusee_->setPosition(xf_, yf_);
		rt->draw(*sprite_fusee_);
}

int 
Fusee:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 550;
	return alea;
}

bool
Fusee:: from_scratch(bool boolean){
	if (boolean){
		xf_ = 800;
		return true;
	}
	else 
		return false;
}

bool
Fusee:: far_away(int x){
	// Verifie si notre fusée est partie bien loin...
	if (x < (-10))
		return true;
	else
		return false;
}

int 
Fusee:: getX(){
    return xf_;
}

int
Fusee:: getY(){
    return yf_;
}
