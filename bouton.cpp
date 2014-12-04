

#include "bouton.hpp"

Bouton::Bouton (int X, int Y, sf::String text) 
{
	rectangleShape_ = new sf::RectangleShape(sf::Vector2f(TAILLE_RECTANGLE_LONGUEUR, TAILLE_RECTANGLE_LARGEUR));
	texture_ = new sf::Texture;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	if(!texture_->loadFromFile("texture_metallique.jpg")){
		exit(1);
	}
	rectangleShape_->setTexture(texture_);
	rectangleShape_->setPosition(X, Y);
	rectangleShape_->scale(ECHELLE_RECTANGLE, ECHELLE_RECTANGLE);
	text_.setFont(font_);
	text_.setCharacterSize(POLICE_BOUTON);
	text_.setColor(sf::Color::Black);
	text_.setString(text);
	text_.setPosition(X, Y);
}

Bouton:: ~Bouton(){
	delete texture_;
	delete rectangleShape_;
}

void 
Bouton:: display(sf::RenderTarget *rt){
	rt->draw(*rectangleShape_);
	rt->draw(text_);	
}
