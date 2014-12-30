#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <SFML/Graphics.hpp>
#include "jetpack.hpp"


class Personnage{

	public:
		Personnage();
		~Personnage();

		void deplacer(int X, int Y); 

		void display(sf::RenderTarget *rt);

		void setPosition (int x, int y);

		int getX();

		int getY();

		int getLIFE();
		void bend(void);
	
		void run();
		void rotation_personnage1(void);
		void rotation_personnage2(void);

		void gravity(int X, int Y, bool boolean);

		bool collision1(int a, int b, int c, int d);
		bool collision2(int a, int b, int c, int d);
		bool collision3(int a, int b, int c, int d);
		bool collision4(int a, int b, int c, int d);
		bool collision5(int a, int b, int c, int d);
		void more_life(void);
		void less_life(void);
		bool is_alive();
		
		friend class Bitcoin;

	private:
		int nbre_vie;
		sf:: Texture personnage_;
		sf:: Sprite *sprite_perso_;
		int x_, y_;
		sf:: Vector2i anim;
		sf:: Clock time;
};



#endif
