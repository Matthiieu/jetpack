#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>
#include "jetpack.hpp"


class Heart{

	public:
		Heart();
		~Heart();

		void move(int X, int Y); 	

		void display(sf::RenderTarget *rt);

		void setPosition (int x, int y);

		int getX();

		int getY();

	private:
		sf:: Texture heart_;
		sf:: Sprite *sprite_heart_;
		int xh_, yh_;
};



#endif
