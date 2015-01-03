/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : CROISSANT.HPP             */
/*****************************************************/

#ifndef CROISSANT_HPP
#define CROISSANT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
#include "main.hpp"
#include "jetpack.hpp"


class Croissant
{
	public:
		Croissant();
		~Croissant(); 

		void move(int X, const int Y);

		void display(sf::RenderTarget *rt);

		void setPosition (int x,const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool from_scratch(bool boolean);

		void rotate(void);

		void scale(int number);

	private:
		sf:: Texture croissant_;
		sf:: Sprite *sprite_croissant_;
		int x_, y_;
};

#endif
