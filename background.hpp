#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "jetpack.hpp"

class Background{
	public:

	Background();
	~Background();
	int generator_number1();
	int generator_number2();
	int generator_number3();

	void launch(int X, const int Y);

	bool far_away(int x);

	void setPosition (int x, const int y);

	int getX();

	int getY();

	bool from_scratch(bool boolean);

	void display(sf::RenderTarget *rt);

	private:
		sf:: Texture background_;
		sf:: Sprite *sprite_background_;
		sf:: Texture background2_;
		sf:: Sprite *sprite_background2_;
		int xb_, yb_;
		int xa_, ya_;
};



#endif
