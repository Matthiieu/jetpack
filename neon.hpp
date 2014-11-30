#ifndef NEON_HPP
#define NEON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
#include "main.hpp"
#include "audio.hpp"
#include "jetpack.hpp"

class Neon{

	public:
		Neon();
		~Neon(); 

		void move(int X, const int Y);

		void display(sf::RenderTarget *rt);

		void setPosition (int x,const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool far_away(int x);

		bool from_scratch(bool boolean);


	private:
		sf:: Texture neon_;
		sf:: Sprite *sprite_neon_;
		int xn_, yn_;
};

#endif
