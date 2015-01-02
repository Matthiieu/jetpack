/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : CUPCAKE.CPP               */
/*****************************************************/

#include "cupcake.hpp"


using namespace std;

Cupcake:: Cupcake(){ 
	cupcake_.loadFromFile("Pictures/cupcake.png");
	cupcake_.setSmooth(true);
	sprite_cupcake_ = new sf:: Sprite;
	sprite_cupcake_->setTexture(cupcake_);
	sprite_cupcake_->setScale(0.03f, 0.03f);
	xc_ = 800;
	yc_ = 500;
}

Cupcake:: ~Cupcake(){
	delete sprite_cupcake_;
}

void
Cupcake:: setPosition (int x, const int y){
  	 	xc_ = x;
   	 	yc_ = y;
}

void 
Cupcake:: move(int X, const int Y){
	xc_ = xc_ - X;
	yc_ = yc_ - Y;
	sprite_cupcake_->move(xc_, yc_);
}

void
Cupcake:: display(sf::RenderTarget *rt){
		sprite_cupcake_->setPosition(xc_, yc_);
		rt->draw(*sprite_cupcake_);
}

int 
Cupcake:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 580;
	return alea;
}

bool
Cupcake:: from_scratch(bool boolean){
	if (boolean){
		xc_ = 820;
		return true;
	}
	else 
		return false;
}

bool
Cupcake:: far_away(int x){
	if (x < (-10))
		return true;
	else
		return false;
}

int 
Cupcake:: getX(){
    return xc_;
}

int
Cupcake:: getY(){
    return yc_;
}
