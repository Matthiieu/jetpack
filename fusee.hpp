#ifndef FUSEE_HPP
#define FUSEE_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "jetpack.hpp"

class Fusee{

	public:
		Fusee();
		~Fusee(); 

		void launch(int X, const int Y);

		void display(sf::RenderTarget *rt);

		void setPosition (int x,const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool far_away(int x);

		bool from_scratch(bool boolean);

	private:
		sf:: Texture fusee_;
		sf:: Sprite *sprite_fusee_;
		int x_, y_;
};



#endif
