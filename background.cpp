#include "background.hpp"

using namespace std;

Background:: Background(){ 
	background_.loadFromFile("ESSAIE.png");
	background_.setSmooth(true);
	sprite_background_ = new sf::Sprite;
	sprite_background_->setTexture(background_);
	sprite_background_->setPosition(0, 0);
	sprite_background_->setScale(1.6f, 1.6f);
	xb_ = 0;
	yb_ = 0;
	background2_.loadFromFile("ecran.jpg");
	background2_.setSmooth(true);
	sprite_background2_ = new sf::Sprite;
	sprite_background2_->setTexture(background_);
	sprite_background2_->setPosition(0, 0);
	sprite_background2_->setScale(1.6f, 1.6f);
	xa_ = 0;
	ya_ = 0;
}

void
Background:: setPosition (int x, const int y){
  	 	xb_ = x;
   	 	yb_ = y;
}

bool
Background:: from_scratch(bool boolean){
	if (boolean){
		xb_ = 800;
		return true;
	}
	else 
		return false;
}

void 
Background:: launch(int X, const int Y){
	xb_ = xb_ - X;
	yb_ = yb_ - Y;
	sprite_background_->move(xb_, yb_);
}


Background:: ~Background(){
	delete sprite_background_;
	delete sprite_background2_;
}

void
Background:: display(sf::RenderTarget *rt){
		sprite_background_->setPosition(xb_, yb_);
		rt->draw(*sprite_background_);
}

bool
Background:: far_away(int x){
	// Verifie si notre fusée est partie bien loin...
	if (x < (-1491)){
		return true;
	}
	else
		return false;
}
/****************************************************************************************************************/
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

int 
Background:: getX(){
    return xb_;
}

int
Background:: getY(){
    return yb_;
}

