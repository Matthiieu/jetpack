/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BUTTON.CPP                */
/*****************************************************/

#include "button.hpp"


Button::Button (int X, int Y, sf::String text) 
{
	rectangleShape_ = new sf::RectangleShape(sf::Vector2f(TAILLE_RECTANGLE_LONGUEUR, TAILLE_RECTANGLE_LARGEUR));
	texture_ = new sf::Texture;
	font_ = new sf::Font;
	if(!font_->loadFromFile("Font/police.ttf")){
		exit(1);
	}
	if(!texture_->loadFromFile("Pictures/texture_bois.png")){
		exit(1);
	}
	rectangleShape_->setTexture(texture_);
	rectangleShape_->setPosition(X, Y);
	rectangleShape_->scale(ECHELLE_BUTTON_X, ECHELLE_BUTTON_Y);
	text_.setFont(*font_);
	text_.setCharacterSize(POLICE_BOUTON);
	text_.setColor(sf::Color::White);
	text_.setString(text);
	text_.setPosition(X + OFFSET2_1, Y + OFFSET2_2);
}

Button:: ~Button(){
	delete texture_;
	delete rectangleShape_;
	delete font_;
}

void 
Button:: display(sf::RenderTarget *rt){
	rt->draw(*rectangleShape_);
	rt->draw(text_);	
}
