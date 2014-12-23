#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "bouton.hpp"
#include "jetpack.hpp"

using namespace std;

class Menu
{
	public:
		Menu();
		~Menu();

		void display(sf::RenderTarget *rt);
		void display_texte(sf::RenderTarget *rt);
		void display_bouton(sf::RenderTarget *rt);
		int setCurrentAction(sf::Vector2i localPosition);
		void display_aide(sf::RenderTarget *rt);
		void display_looser(sf::RenderTarget *rt);

		void distance(sf::RenderTarget *rt, int number);
		void display_chrono(sf::RenderTarget *rt, int number);

		void display_vie(sf::RenderTarget *rt, int number);

 		void written_score(int number);
		void reading_score(sf::RenderTarget *rt);
		sf::Text transformator_string(int Taille, int PosX, int PosY, string String);

	private:
		sf:: Texture texture_;
		sf:: Sprite logo_;
		sf:: Text textes_;
		
};

#endif
