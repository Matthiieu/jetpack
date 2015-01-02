#ifndef FRENCH_STICK_HPP
#define FRENCH_STICK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
#include "main.hpp"
#include "jetpack.hpp"


class French_stick
{
	public:
		French_stick();
		~French_stick(); 

		void move(int X, const int Y);

		void display(sf::RenderTarget *rt);

		void setPosition (int x,const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool far_away(int x);

		bool from_scratch(bool boolean);

		void rotate(void);

		void scale(int number);

	private:
		sf:: Texture french_stick_;
		sf:: Sprite *sprite_french_stick_;
		int x_, y_;
};

#endif
