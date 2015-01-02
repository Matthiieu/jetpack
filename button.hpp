#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp" 

class Button{
	public:
		Button(int X, int Y, sf::String text);
		~Button();

		void display(sf::RenderTarget *rt);
	
	private:
		sf:: RectangleShape *rectangleShape_;
		sf:: Texture *texture_;
		sf:: Text text_;
		sf:: Font *font_;

};

#endif

