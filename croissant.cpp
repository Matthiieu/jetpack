/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : CROISSANT.CPP             */
/*****************************************************/

#include "croissant.hpp"

using namespace std;

Croissant:: Croissant(): x_(800), y_(550)
{ 
	croissant_.loadFromFile("Pictures/croissant.png");
	croissant_.setSmooth(true);
	sprite_croissant_ = new sf::Sprite;
	sprite_croissant_->setTexture(croissant_);
	//sprite_croissant_->rotate(100);
	sprite_croissant_->setScale(0.05f, 0.07f);
}

Croissant:: ~Croissant(){
	delete sprite_croissant_;
}

void
Croissant:: setPosition (int x, const int y){
  	 	x_ = x;
   	 	y_ = y;
}

void
Croissant:: rotate(void){
	sprite_croissant_->rotate(10);
}

bool
Croissant:: far_away(int x){
	// Verifie si notre neon est partie bien loin...
	if (x < (-10))
		return true;
	else
		return false;
}

void
Croissant:: scale(int number){
	int ok = number % 1 ;
	cout << ok << endl;
	sprite_croissant_->setScale(0.1f , 0.1f * ok);
}

void 
Croissant:: move(int X, const int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_croissant_->move(x_, y_);
}

void
Croissant:: display(sf::RenderTarget *rt){
		sprite_croissant_->setPosition(x_, y_);
		rt->draw(*sprite_croissant_);
}

int 
Croissant:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 480;
	return alea;
}


bool
Croissant:: from_scratch(bool boolean){
	if (boolean){
		x_ = 800;
		return true;
	}
	else 
		return false;
}

int 
Croissant:: getX(){
    return x_;
}

int
Croissant:: getY(){
    return y_;
}
