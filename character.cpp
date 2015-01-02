/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : CHARACTER.CPP             */
/*****************************************************/

#include "character.hpp"

using namespace std;

Character:: Character(){ 
	nbre_vie = 1;
	character_.loadFromFile("Pictures/samy.png");
	character_.setSmooth(true);
	sprite_character_ = new sf::Sprite;
	sprite_character_->setTexture(character_);
	sprite_character_->setScale(1.7f, 1.7f);
	x_ = MIDDLE;
	y_ = FLOOR;
	anim.x = 0;
	anim.y = 2;
}

Character:: ~Character(){
	delete sprite_character_;
}

void
Character:: setPosition (int x, int y){
  	 	x_ = x;
   	 	y_ = y;
		if(y_ >= FLOOR)
			y_ = FLOOR;
		if (y_ <= 0)
			y_ = 0;
}

bool 
Character:: collision1(int a, int b, int c, int d){
	if ((abs(a-c) <= 50 ) && (abs(b-d) <= 50)){
		cout << "COLLISION DE TYPE BRIOCHE, CUPCAKE, HEART, CROISSANT, BITCOIN" << endl;
		return true;
	}
	else
		return false;
}

bool 
Character:: collision2(int a, int b, int c, int d){
	if ((abs(a-c) <= 15 ) && (abs(b-d) <= 80)){
		cout << abs(a-c) << endl << abs(b-d) << endl << c << endl << d << endl;
		cout << "COLLISION DE TYPE BAGUETTE" << endl;
		return true;
	}
	else
		return false;
}

void 
Character:: more_life(void){
		nbre_vie++;
}

void 
Character:: less_life(void){
		nbre_vie--;
}

bool
Character:: is_alive(){
	if(nbre_vie == 0){
		return false;
	}
	else
		return true;
}

void 
Character:: deplacer(int X, int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_character_->move(x_, y_);
}

void
Character:: run(){
	sf::Time elapsed1 = time.getElapsedTime();
	if (y_ == FLOOR){
		if (elapsed1.asMilliseconds() > UPDATE){
			anim.x++;
			if ((unsigned)anim.x * 32 >= character_.getSize().x)
				anim.x = 0;
			time.restart();
		}
		sprite_character_->setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32));
	}
	else{
		sprite_character_->setTextureRect(sf::IntRect(32, 64, 32, 32));
	}
}

void
Character:: display(sf::RenderTarget *rt){
		sprite_character_->setPosition(x_, y_);
		rt->draw(*sprite_character_);
}

void
Character:: rotation_personnage2(void){
	sprite_character_->setScale(1.7f, -1.7f);
}

void
Character:: rotation_personnage1(void){
	sprite_character_->setScale(1.7f, 1.7f);
}

void
Character:: gravity(int X, int Y, bool boolean){
		if (boolean == false){	// correspond à la gravité
			rotation_personnage1();
			x_ = x_ - X;
			y_ = y_ - Y;
			if(y_ >= FLOOR)
				y_ = FLOOR;
			if (y_ <= 0)
				y_ = 0;
		}
		else{			// correspond à l'anti gravité
			rotation_personnage2();
			x_ = x_ - X;
			y_ = y_ + Y;
			if (y_ >= FLOOR2)	
				y_ = FLOOR2;
			if (y_ <= CEILING)
				y_ = CEILING;
		}
		sprite_character_->move(x_, y_);
}

int 
Character:: getX(){
    return x_;
}

int
Character:: getY(){
    return y_;
}

int 
Character:: getLIFE(){
	return nbre_vie;
}
