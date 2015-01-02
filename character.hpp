/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : CHARACTER.HPP             */
/*****************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "jetpack.hpp"


class Character{

	public:
		Character();
		~Character();

		void deplacer(int X, int Y); 

		void display(sf::RenderTarget *rt);

		void setPosition (int x, int y);

		int getX();

		int getY();

		int getLIFE();
	
		void run();
		void rotation_personnage1(void);
		void rotation_personnage2(void);

		void gravity(int X, int Y, bool boolean);

		bool collision1(int a, int b, int c, int d);
		bool collision2(int a, int b, int c, int d);
		void more_life(void);
		void less_life(void);
		bool is_alive();

	private:
		int nbre_vie;
		sf:: Texture character_;
		sf:: Sprite *sprite_character_;
		int x_, y_;
		sf:: Vector2i anim;
		sf:: Clock time;
};



#endif
