/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BOUTON.CPP                */
/*****************************************************/

#include "bouton.hpp"

Bouton::Bouton (int X, int Y, sf::String text) 
{
	rectangleShape_ = new sf::RectangleShape(sf::Vector2f(TAILLE_RECTANGLE_LONGUEUR, TAILLE_RECTANGLE_LARGEUR));
	texture_ = new sf::Texture;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	if(!texture_->loadFromFile("texture_bois.png")){
		exit(1);
	}
	rectangleShape_->setTexture(texture_);
	rectangleShape_->setPosition(X, Y);
	rectangleShape_->scale(2.6f, 2.4f);
	text_.setFont(font_);
	text_.setCharacterSize(POLICE_BOUTON);
	text_.setColor(sf::Color::White);
	text_.setString(text);
	text_.setPosition(X + 50, Y + 10);
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
