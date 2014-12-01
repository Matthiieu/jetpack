#ifndef BOUTON_HPP
#define BOUTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp" 

class Bouton{
	public:
		Bouton(int X, int Y, sf::String text);
		~Bouton();

		void display(sf::RenderTarget *rt);
	
	private:
		sf:: RectangleShape *rectangleShape_;
		sf:: Texture *texture_;
		sf:: Text text_;
		sf:: Font font_;

};

#endif

