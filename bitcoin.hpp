#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "jetpack.hpp"

class Bitcoin{

	public:
		Bitcoin();
		~Bitcoin(); 

		void move(int X, const int Y);
		void display(sf::RenderTarget *rt);

		void setPosition (int x, const int y);

		int getX();

		int getY();
		
		int generator_number();

		bool far_away(int x);

		bool from_scratch(bool boolean);

		void increase_collection(void);

		int getCOLLECTION(void);

	private:
		sf:: Texture bitcoin_;
		sf:: Sprite *sprite_bitcoin_;
		int xb_, yb_;
		int collection_;
};



#endif
