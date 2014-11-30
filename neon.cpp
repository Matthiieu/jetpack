#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "audio.hpp"
#include "neon.hpp"


using namespace std;

Neon:: Neon(){ 
	neon_.loadFromFile("neon.png");
	//fusee_.setSmooth(true);
	sprite_neon_ = new sf::Sprite;
	sprite_neon_->setTexture(neon_);
	sprite_neon_->setScale(0.1f, 0.2f);
	xn_ = 800;
	yn_ = 100;
}

Neon:: ~Neon(){
	delete sprite_neon_;
}

void
Neon:: setPosition (int x, const int y){
  	 	xn_ = x;
   	 	yn_ = y;
}

void 
Neon:: move(int X, const int Y){
	xn_ = xn_ - X;
	yn_ = yn_ - Y;
	sprite_neon_->move(xn_, yn_);
}

void
Neon:: display(sf::RenderTarget *rt){
		sprite_neon_->setPosition(xn_, yn_);
		rt->draw(*sprite_neon_);
}

int 
Neon:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 600;
	return alea;
}

bool
Neon:: from_scratch(bool boolean){
	if (boolean){
		xn_ = 800;
		return true;
	}
	else 
		return false;
}

bool
Neon:: far_away(int x){
	// Verifie si notre neon est partie bien loin...
	if (x < 0)
		return true;
	else
		return false;
}

int 
Neon:: getX(){
    return xn_;
}

int
Neon:: getY(){
    return yn_;
}
