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
		void display_bitcoin(sf::RenderTarget *rt, int number);

		void display_vie(sf::RenderTarget *rt, int number);

		void screenshot(sf::RenderTarget *rt);
		void display_presentation(sf::RenderTarget *rt);

 		void written_score(int number);
		void reading_score(sf::RenderTarget *rt);


	private:
		sf:: Texture texture_first;
		sf:: Sprite logo_first;
		sf:: Texture texture_screenshot;
		sf:: Sprite logo_screenshot;
		sf:: Text textes_;
		
};

#endif
