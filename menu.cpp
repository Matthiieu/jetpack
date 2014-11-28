#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "bouton.hpp"

using namespace std;

Menu:: Menu(){
	if(!texture_.loadFromFile("index.jpeg")){
		exit(1);
	}
	logo_.setTexture(texture_);
	logo_.setPosition(POSITION_IMAGE_MENU_X, POSITION_IMAGE_MENU_Y);
	logo_.setScale(ECHELLE_IMAGE_MENU_X, ECHELLE_IMAGE_MENU_Y);
	//bouton_play_ = new Bouton(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y1, "Play");	
	//bouton_aide_ = new Bouton(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y2, "Aide");	
	//bouton_option_ = new Bouton(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y1, "Option");	
	//bouton_score_ = new Bouton(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y2, "Score");	
}
	
Menu:: ~Menu(){

}

void
Menu:: display_bouton(sf::RenderTarget *rt){
	Bouton bouton_play_(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y1, "Play");
	Bouton bouton_option_(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y1, "Option");
	Bouton bouton_aide_(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y2, "Aide");
	Bouton bouton_score_(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y2, "Score");
	bouton_score_.display(rt);
	bouton_option_.display(rt);
	bouton_aide_.display(rt);
	bouton_play_.display(rt);
}

void 
Menu:: display_texte(sf::RenderTarget *rt){
	sf:: Text texte_;
	sf:: Font font_;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	texte_.setFont(font_);
	texte_.setRotation(ROTATE);
	texte_.setCharacterSize(TAILLE_POLICE);
	texte_.setColor(sf::Color::White);
	texte_.setPosition(POSITION_TITRE_MENU_X, POSITION_TITRE_MENU_Y);
	texte_.setString("Welcome to the\n");
	rt->draw(texte_);
}


void 
Menu:: display(sf::RenderTarget *rt){
	rt->draw(logo_);
	display_bouton(rt);
}

void
Menu:: display_aide(sf::RenderTarget *rt){
	sf:: Text texte_;
	sf:: Font font_;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	texte_.setFont(font_);
	texte_.setCharacterSize(20);
	texte_.setColor(sf::Color::White);
	texte_.setString("Bienvenue dans le (super) jeu de Jetpack Joyride.\n\n Pour jouer, rien de plus simple. Vous avez a votre disposition\n que deux boutons:\n le premier est la touche directionnelle UP et le deuxieme\n la touche directionnelle DOWN.\n\n Le but du jeu est d'aller le plus loin possible\n sans vous faire toucher par les lignes\n electriques ou les missiles!\n\n\n Bon courage et surtout.. Bonne chance!!!!\n\n\n Cliquer n'importe ou pour sortir de la centrale d'aide\n\n");
	rt->draw(texte_);
}

int
Menu:: setCurrentAction(sf::Vector2i localPosition){
	if (localPosition.x >= ZONE1 && localPosition.x <=ZONE2){
		if (localPosition.y >= ZONE5 && localPosition.y <= ZONE6){
			cout << "Play" << endl;
			return 0;
		}
		if (localPosition.y >= ZONE7 && localPosition.y <= ZONE8){
			cout << "Aide" << endl;
			return 1;
		}
	}
	else if(localPosition.x >= ZONE3 && localPosition.x <= ZONE4){
		if (localPosition.y >= ZONE5 && localPosition.y <= ZONE6){
			cout << "Option" << endl;
			return 2;
		}
		if (localPosition.y >= ZONE7 && localPosition.y <= ZONE8){
			cout << "Score" << endl;
			return 3;
		}
	}
	return 0;
}
