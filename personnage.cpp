#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "personnage.hpp"
#include "jetpack.hpp"

using namespace std;

Personnage:: Personnage(){
	nbre_vie = 1;
	personnage_.loadFromFile("character.png");
	personnage_.setSmooth(true);
	sprite_perso_ = new sf::Sprite;
	sprite_perso_->setTexture(personnage_);
	
	x_ = 300;
	y_ = 540;
	anim.x = 0;
	anim.y = 2;
}

Personnage:: ~Personnage(){
	//delete personnage_;
	delete sprite_perso_;
}

void
Personnage:: setPosition (int x, int y){
  	 	x_ = x;
   	 	y_ = y;
		if(y_ >= 540)
			y_ = 540;
		if (y_ <= 0)
			y_ = 0;
}

void
Personnage:: gagner_vie(){
	nbre_vie += 1;
}

void 
Personnage:: deplacer(int X, int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_perso_->move(x_, y_);
}

bool
Personnage:: courrir(){

	//cout << time.getElapsedTime().asMilliseconds() << endl;
	/*if (time.getElapsedTime().asMilliseconds() >= 50){
		cout << "je suis une pastèque!" << endl;
	}
	else{
		time.restart();
		cout << "restart" << endl;
	}*/
	if (y_ == 540){
		anim.x--;
		if (anim.x * 32 >= personnage_.getSize().x){
			anim.x = 2;
			sprite_perso_->setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32));
			sprite_perso_->setScale(1.5f, 1.5f);
			return true;
		}
	}
	else{
		sprite_perso_->setTextureRect(sf::IntRect(64, 64, 32, 32));
		sprite_perso_->setScale(1.5f, 1.5f);
		return false;
	}
}

void
Personnage:: display(sf::RenderTarget *rt){
		sprite_perso_->setPosition(x_, y_);
		rt->draw(*sprite_perso_);
}

void
Personnage:: gravity(){
	do{
		sprite_perso_->move(0, 4);
	}while(y_ != 540);
}

int 
Personnage:: getX(){
    return x_;
}

int
Personnage:: getY(){
    return y_;
}
