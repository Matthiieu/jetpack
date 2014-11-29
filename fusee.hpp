#ifndef FUSEE_HPP
#define FUSEE_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "jetpack.hpp"

class Fusee{

	public:
		Fusee();
		~Fusee(); 

		void deplacer(int X, int Y);

		void display(sf::RenderTarget *rt);

		void setPosition (int x, int y);

		int getX();

		int getY();

	private:
		sf:: Texture fusee_;
		sf:: Sprite *sprite_fusee_;
};



#endif
