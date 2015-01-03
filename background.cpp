/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BACKGROUND.CPP            */
/*****************************************************/

#include "background.hpp"

using namespace std;

//Constructeur Background, permet de charger les fonds d'ecran.
Background:: Background(string name, int x, int y){ 
	background_.loadFromFile(name);
	background_.setSmooth(true);
	sprite_background_ = new sf::Sprite;
	sprite_background_->setTexture(background_);
	sprite_background_->setPosition(x, y);
	xb_ = x;	
	yb_ = y;
}

//Destructeur
Background:: ~Background(){
	delete sprite_background_;
}

//Permet de positionner les fonds d'écran.
void
Background:: setPosition (int x, const int y){
  	 	xb_ = x;
   	 	yb_ = y;
}

//Permet de remettre a zero notre defilement de sprite.
bool
Background:: from_scratch(bool boolean){
	if (boolean){
		xb_ = 0;
		return true;
	}
	else 
		return false;
}

//Permet de faire défiler le fond d ecran.
void 
Background:: parade(int X, const int Y){
	xb_ = xb_ - X;
	yb_ = yb_ - Y;
	sprite_background_->move(xb_, yb_);
}


//Afficher les fonds d ecran.
void
Background:: display(sf::RenderTarget *rt){
		sprite_background_->setPosition(xb_, yb_);
		rt->draw(*sprite_background_);
}

//Permet de savoir où se situe la fin du defilement des sprites.
bool
Background:: far_away(int x){
	if (x < LIMIT_BACKGROUND)
		return true;
	else
		return false;
}

//Permet d'obtenir l abscisse du sprite.
int 
Background:: getX(){
    return xb_;
}

//Permet d obtenir l ordonnee du sprite
int
Background:: getY(){
    return yb_;
}


