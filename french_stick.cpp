/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : FRENCH_STICK.CPP          */
/*****************************************************/

#include "french_stick.hpp"

using namespace std;

French_stick:: French_stick(): x_(800), y_(100){ 
	french_stick_.loadFromFile("Pictures/Baguette.png");
	french_stick_.setSmooth(true);
	sprite_french_stick_ = new sf::Sprite;
	sprite_french_stick_->setTexture(french_stick_);
	sprite_french_stick_->rotate(100);
	sprite_french_stick_->setScale(0.4f, 0.2f);
}

French_stick:: ~French_stick(){
	delete sprite_french_stick_;
}

void
French_stick:: setPosition (int x, const int y){
  	 	x_ = x;
   	 	y_ = y;
}

bool
French_stick:: far_away(int x){
	// Verifie si notre neon est partie bien loin...
	if (x < (-10))
		return true;
	else
		return false;
}

void
French_stick:: scale(int number){
	int ok = number % 1 ;
	cout << ok << endl;
	sprite_french_stick_->setScale(0.1f , 0.1f * ok);
}

void
French_stick:: rotate(void){
	sprite_french_stick_->rotate(5);
}

void 
French_stick:: move(int X, const int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_french_stick_->move(x_, y_);
}

void
French_stick:: display(sf::RenderTarget *rt){
		sprite_french_stick_->setPosition(x_, y_);
		rt->draw(*sprite_french_stick_);
}

int 
French_stick:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 480;
	return alea;
}


bool
French_stick:: from_scratch(bool boolean){
	if (boolean){
		x_ = 800;
		return true;
	}
	else 
		return false;
}

int 
French_stick:: getX(){
    return x_;
}

int
French_stick:: getY(){
    return y_;
}
