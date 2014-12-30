#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
#include "jetpack.hpp"
#include "main.hpp"

class Weapon
{
	public:
		Weapon();
		~Weapon(); 

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

	//private:
		//int x_, y_;
};

#endif
