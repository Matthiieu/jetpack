/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : MENU.HPP                  */
/*****************************************************/


#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include "main.hpp"
#include "button.hpp"
#include "jetpack.hpp"

using namespace std;

class Button;

class Menu
{
	public:
		Menu();
		~Menu();

		void display(sf::RenderTarget *rt);
		void display_texte(sf::RenderTarget *rt);
		void display_bouton(sf::RenderTarget *rt);
		int setCurrentAction(sf::Vector2i localPosition);
		void display_aide(sf::RenderTarget *rt);
		void display_looser(sf::RenderTarget *rt);

		void distance(sf::RenderTarget *rt, int number);
		void display_chrono(sf::RenderTarget *rt, int number);
		void display_bitcoin(sf::RenderTarget *rt, int number);

		void display_vie(sf::RenderTarget *rt, int number);

		void screenshot(sf::RenderTarget *rt);
		void display_presentation(sf::RenderTarget *rt);

 		void written_score(int number);
		void reading_score(sf::RenderTarget *rt);
		void display_level(sf::RenderTarget *rt, int number);

	private:
		sf:: Texture texture_first;
		sf:: Sprite *logo_first;
		sf:: Texture texture_screenshot;
		sf:: Sprite *logo_screenshot;
		sf:: Texture texture_score;
		sf:: Sprite *logo_score;
		sf:: Text textes_;
		sf:: Texture bitcoin_;
		sf:: Texture blesse_;
		sf:: Sprite *sprite_bitcoin_;
		sf:: Sprite *sprite_blesse;
		sf:: Sprite *sprite_vie_;
		sf:: Texture vie_;
		sf:: Font *font_;
		sf:: Font *font_2;
  		Button *bouton_play_;
  		Button *bouton_quitter_;
  		Button *bouton_score_;
  		Button *bouton_aide_;
};

#endif
