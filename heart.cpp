/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : HEART.CPP                 */
/*****************************************************/

#include "heart.hpp"

using namespace std;

bool limit_heart = true;

Heart:: Heart(){ 
	heart_.loadFromFile("Pictures/vie.png");
	heart_.setSmooth(true);
	sprite_heart_ = new sf::Sprite;
	sprite_heart_->setTexture(heart_);
	sprite_heart_->setScale(ECHELLE_HEART, ECHELLE_HEART);
	xh_ = 800;
	yh_ = 375;
}

Heart:: ~Heart(){
	delete sprite_heart_;
}

void
Heart:: setPosition (int x, const int y){
  	 	xh_ = x;
   	 	yh_ = y;
}
 
void 
Heart:: move(int X, const int Y){
	xh_ = xh_ - X;
	if (limit_heart == true){
		yh_++;
		if (yh_ >= 215)
			limit_heart = false;
	}
	else{
		yh_--;
		if (yh_ <= 50)	
			limit_heart = true;
	}
	sprite_heart_->move(xh_, yh_);
}

void
Heart:: display(sf::RenderTarget *rt){
		sprite_heart_->setPosition(xh_, yh_);
		rt->draw(*sprite_heart_);
}

bool
Heart:: from_scratch(bool boolean){
	if (boolean){
		xh_ = 800;
		return true;
	}
	else 
		return false;
}


int 
Heart:: getX(){
    return xh_;
}

int
Heart:: getY(){
    return yh_;
}
