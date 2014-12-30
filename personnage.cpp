#include "personnage.hpp"

using namespace std;

Personnage:: Personnage(){ 
	nbre_vie = 1;
	personnage_.loadFromFile("samy.png");
	personnage_.setSmooth(true);
	sprite_perso_ = new sf::Sprite;
	sprite_perso_->setTexture(personnage_);
	sprite_perso_->setScale(1.7f, 1.7f);
	x_ = MIDDLE;
	y_ = FLOOR;
	anim.x = 0;
	anim.y = 2;
}

Personnage:: ~Personnage(){
	delete sprite_perso_;
}

void
Personnage:: setPosition (int x, int y){
  	 	x_ = x;
   	 	y_ = y;
		if(y_ >= FLOOR)
			y_ = FLOOR;
		if (y_ <= 0)
			y_ = 0;
}

//PREVOIR UNE FONCTION GENERALE COLLISION!!!!!!!!!!!!!!!!
bool 
Personnage:: collision1(int a, int b, int c, int d){
	// previens s'il y a eu collision avec la brioche!
	if ((abs(a-c) <= 5 ) && (abs(b-d) <= 15)){
		cout << "COLLISION BRIOCHE" << endl;
		return true;
	}
	else
		return false;
}

bool 
Personnage:: collision2(int a, int b, int c, int d){
	// previens s'il y a eu collision avec la baguette!
	if ((abs(a-c) <= 5 ) && (abs(b-d) <= 80)){
		cout << abs(a-c) << endl << abs(b-d) << endl << c << endl << d << endl;
		cout << "COLLISION BAGUETTE" << endl;
		return true;
	}
	else
		return false;
}

bool 
Personnage:: collision3(int a, int b, int c, int d){
	// previens s'il y a eu collision avec le cupcake!
	if ((abs(a-c) <= 5 ) && (abs(b-d) <= 80)){
		cout << "COLLISION CUPCAKE" << endl;
		return true;
	}
	else
		return false;
}

bool 
Personnage:: collision4(int a, int b, int c, int d){
	// previens s'il y a eu collision avec le coeur!
	if ((abs(a-c) <= 5 ) && (abs(b-d) <= 80)){
		cout << "COLLISION COEUR" << endl;
		return true;
	}
	else
		return false;
}

bool 
Personnage:: collision5(int a, int b, int c, int d){
	// previens s'il y a eu collision avec le croissant!
	if ((abs(a-c) <= 1) && (abs(b-d) <= 1)){
		cout << "COLLISION CROISSANT" << endl;
		return true;
	}
	else
		return false;
}

void 
Personnage:: more_life(void){
		nbre_vie++;
}

void 
Personnage:: less_life(void){
		nbre_vie--;
}

bool
Personnage:: is_alive(){
	if(nbre_vie == 0){
		return false;
	}
	else
		return true;
}

void 
Personnage:: deplacer(int X, int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_perso_->move(x_, y_);
}

void
Personnage:: run(){
	sf::Time elapsed1 = time.getElapsedTime();
	if (y_ == FLOOR){
		if (elapsed1.asMilliseconds() > UPDATE){
			anim.x++;
			if ((unsigned)anim.x * 32 >= personnage_.getSize().x)
				anim.x = 0;
			time.restart();
		}
		sprite_perso_->setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32));
		//sprite_perso_->setScale(ECHELLE_SAM, gravity);
	}
	else{
		sprite_perso_->setTextureRect(sf::IntRect(32, 64, 32, 32));
		//sprite_perso_->setScale(ECHELLE_SAM, gravity);
	}
}

void 
Personnage:: bend(void){
	sprite_perso_->rotate(-5);
}


void
Personnage:: display(sf::RenderTarget *rt){
		sprite_perso_->setPosition(x_, y_);
		rt->draw(*sprite_perso_);
}

void
Personnage:: rotation_personnage2(void){
	sprite_perso_->setScale(1.7f, -1.7f);
}

void
Personnage:: rotation_personnage1(void){
	sprite_perso_->setScale(1.7f, 1.7f);
}

void
Personnage:: gravity(int X, int Y, bool boolean){
		if (boolean == true){	// correspond à la gravité
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
		sprite_perso_->move(x_, y_);
}

int 
Personnage:: getX(){
    return x_;
}

int
Personnage:: getY(){
    return y_;
}

int 
Personnage:: getLIFE(){
	return nbre_vie;
}
