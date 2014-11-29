#include <SFML/Graphics.hpp>
//#include<st>
//#include <time.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "fusee.hpp"


using namespace std;

Fusee:: Fusee(){ 
	fusee_.loadFromFile("balle.png");
	//fusee_.setSmooth(true);
	sprite_fusee_ = new sf::Sprite;
	sprite_fusee_->setTexture(fusee_);
	sprite_fusee_->setScale(0.05f, 0.05f);
	x_ = 800;
	y_ = 200;
}

Fusee:: ~Fusee(){
	delete sprite_fusee_;
}

void
Fusee:: setPosition (int x, const int y){
  	 	x_ = x;
   	 	y_ = y;
}

void 
Fusee:: launch(int X, const int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_fusee_->move(x_, y_);
}

void
Fusee:: display(sf::RenderTarget *rt){
		sprite_fusee_->setPosition(x_, y_);
		rt->draw(*sprite_fusee_);
}

int 
Fusee:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 600;
	return alea;

}

bool
Fusee:: from_scratch(bool boolean){
	if (boolean){
		x_ = 800;
		return true;
	}
	else 
		return false;
}

bool
Fusee:: far_away(int x){
	// Verifie si notre fusée est partie bien loin...
	if (x < 0)
		return true;
	else
		return false;
}

int 
Fusee:: getX(){
    return x_;
}

int
Fusee:: getY(){
    return y_;
}
