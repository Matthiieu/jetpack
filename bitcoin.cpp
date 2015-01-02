/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BITCOIN.CPP               */
/*****************************************************/

#include "bitcoin.hpp"

using namespace std;

Bitcoin:: Bitcoin(){ 
	bitcoin_.loadFromFile("Pictures/bitcoin1.png");
	bitcoin_.setSmooth(true);
	sprite_bitcoin_ = new sf:: Sprite;
	sprite_bitcoin_->setTexture(bitcoin_);
	sprite_bitcoin_->setScale(0.05f, 0.05f);
	xb_ = 800;
	yb_ = 100;
	collection_ = 0;
}

Bitcoin:: ~Bitcoin(){
	delete sprite_bitcoin_;
}

void
Bitcoin:: setPosition (int x, const int y){
  	 	xb_ = x;
   	 	yb_ = y;
}

void 
Bitcoin:: move(int X, const int Y){
	xb_ = xb_ - X;
	yb_ = yb_ - Y;
	sprite_bitcoin_->move(xb_, yb_);
}

void
Bitcoin:: display(sf::RenderTarget *rt){
		sprite_bitcoin_->setPosition(xb_, yb_);
		rt->draw(*sprite_bitcoin_);
}

int 
Bitcoin:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 580;
	return alea;
}

int generator_number2(){
	// Génerer un nombre entre 0 et -400!
	srand(time(NULL));
	int alea2 = rand() % (900);
	alea2 -= 1600;
	return alea2;
}

bool
Bitcoin:: from_scratch(bool boolean){
	if (boolean){
		xb_ = 820;
		return true;
	}
	else 
		return false;
}

bool
Bitcoin:: far_away(int x){
	// Verifie si notre cupcake est partie bien loin...
	if (x < (generator_number2())){
		cout << generator_number2() << endl;
		return true;
	}
	else
		return false;
}

int 
Bitcoin:: getX(){
    return xb_;
}

int
Bitcoin:: getY(){
    return yb_;
}

void
Bitcoin:: increase_collection(){
	collection_++;
}

void
Bitcoin:: restart_collection(){
	collection_ = 0;
}

int 
Bitcoin:: getCOLLECTION(){
	return collection_;
}


