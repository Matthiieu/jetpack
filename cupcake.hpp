/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : CUPCAKE.HPP               */
/*****************************************************/

#ifndef CUPCAKE_HPP
#define CUPCAKE_HPP

#include <SFML/Graphics.hpp>
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

		bool from_scratch(bool boolean);


	private:
		sf:: Texture cupcake_;
		sf:: Sprite *sprite_cupcake_;
		int xc_, yc_;
};



#endif
