/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BRIOCHE.HPP               */
/*****************************************************/

#ifndef BRIOCHE_HPP
#define BRIOCHE_HPP

#include <SFML/Graphics.hpp>
#include "jetpack.hpp"

class Brioche{

	public:
		Brioche();
		~Brioche(); 

		void launch(int X, const int Y);

		void display(sf::RenderTarget *rt);

		void setPosition (int x,const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool far_away(int x);

		bool from_scratch(bool boolean);


	private:
		sf:: Texture brioche_;
		sf:: Sprite *sprite_brioche_;
		int xf_, yf_;
};



#endif
