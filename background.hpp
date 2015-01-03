/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : BACKGROUND.HPP            */
/*****************************************************/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "jetpack.hpp"

using namespace std;

class Background
{
	public:

	Background(string name, int x, int y);
	~Background();

	void parade(int X, const int Y);

	bool far_away(int x);

	void setPosition (int x, const int y);

	bool from_scratch(bool boolean);

	void display(sf::RenderTarget *rt);
	
	int getX();
	int getY();

	private:
		sf:: Texture background_;
		sf:: Sprite *sprite_background_;
		int xa_, ya_;	
		int xb_, yb_;
};



#endif
