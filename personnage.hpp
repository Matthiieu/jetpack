#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "jetpack.hpp"
#include "fusee.hpp"

class Personnage{

	public:
		Personnage();
		~Personnage();

		void deplacer(int X, int Y); 

		void gagner_vie();

		void display(sf::RenderTarget *rt);

		void setPosition (int x, int y);

		int getX();

		int getY();
	
		void run();

		void gravity(int X, int Y);

		bool collision(int a, int b, int c, int d);

		friend class Fusee;

	private:
		int nbre_vie;
		sf:: Texture personnage_;
		sf:: Sprite *sprite_perso_;
		int x_, y_;
		sf:: Vector2i anim;
		sf:: Clock time;
};



#endif
