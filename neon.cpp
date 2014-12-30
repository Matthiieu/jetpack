#include "neon.hpp"

using namespace std;

Neon:: Neon(): x_(800), y_(100){ 
	neon_.loadFromFile("Baguette.png");
	neon_.setSmooth(true);
	sprite_neon_ = new sf::Sprite;
	sprite_neon_->setTexture(neon_);
	sprite_neon_->rotate(100);
	sprite_neon_->setScale(0.4f, 0.2f);
}

Neon:: ~Neon(){
	delete sprite_neon_;
}

void
Neon:: setPosition (int x, const int y){
  	 	x_ = x;
   	 	y_ = y;
}

bool
Neon:: far_away(int x){
	// Verifie si notre neon est partie bien loin...
	if (x < (-10))
		return true;
	else
		return false;
}

void
Neon:: scale(int number){
	int ok = number % 1 ;
	cout << ok << endl;
	sprite_neon_->setScale(0.1f , 0.1f * ok);
}

void
Neon:: rotate(void){
	sprite_neon_->rotate(5);
}

void 
Neon:: move(int X, const int Y){
	x_ = x_ - X;
	y_ = y_ - Y;
	sprite_neon_->move(x_, y_);
}

void
Neon:: display(sf::RenderTarget *rt){
		sprite_neon_->setPosition(x_, y_);
		rt->draw(*sprite_neon_);
}

int 
Neon:: generator_number(){
	// Génerer un nombre entre 0 et 600!
	srand(time(NULL));
	int alea = rand() % 480;
	return alea;
}


bool
Neon:: from_scratch(bool boolean){
	if (boolean){
		x_ = 800;
		return true;
	}
	else 
		return false;
}

int 
Neon:: getX(){
    return x_;
}

int
Neon:: getY(){
    return y_;
}
