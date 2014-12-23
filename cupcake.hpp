#ifndef CUPCAKE_HPP
#define CUPCAKE_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "jetpack.hpp"

class Cupcake{

	public:
		Cupcake();
		~Cupcake(); 

		void move(int X, const int Y);
		void display(sf::RenderTarget *rt);

		void setPosition (int x, const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool far_away(int x);

		bool from_scratch(bool boolean);


	private:
		sf:: Texture cupcake_;
		sf:: Sprite *sprite_cupcake_;
		int xc_, yc_;
};



#endif
