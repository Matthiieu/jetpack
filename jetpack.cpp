#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "jetpack.hpp"
#include "audio.hpp"
#include "personnage.hpp"

using namespace std;

Jetpack::Jetpack()
{
	win_ = new sf::RenderWindow(sf::VideoMode(LONGUEUR_FENETRE, LARGEUR_FENETRE), "Jetpack Joyride", sf::Style::Close); 
	//win_->setFramerateLimit(50);
 	menu_ = new Menu;
	audio_ = new Audio;
}

Jetpack::~Jetpack ()
{
  delete menu_;
  delete win_;
  delete audio_;
}

void
Jetpack::launch ()
{	
  audio_->play_menu();
  int Round = 0;
  int Play = 0;
  int gravity = 0;
  Personnage *sam = NULL;
  sam = new Personnage;
  while (win_->isOpen()){
		sf:: Event event;
		sf::Vector2i localPosition = sf::Mouse::getPosition();	
		while(win_->pollEvent(event)){
			switch(event.type){
				case sf:: Event:: MouseButtonPressed:	
					if (Round == 0){		
					switch (menu_->setCurrentAction(localPosition)) {
        				  case 0:
						 Round = 1;
						 Play = 1;
           					 audio_->stop_menu();
						 audio_->play_fond();
						 win_->clear();
						//sam->deplacer();
						 sam->courrir();
						 sam->display(win_);
         					 break;
        				  case 1:
						Round = 1;
						win_->clear();
						menu_->display_aide(win_);
						break;
         				  case 2:
						Round = 1;
						break;
					  case 3:
						Round = 1;
						break;
         				  default: break;
         				 }
					}
					
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Up){
						if (Play == 1){
						gravity = 1;
						sam->setPosition(sam->getX(), sam->getY());	
						sam->deplacer(0, SPEED);
						}					
					}
					break;
				case sf::Event:: Closed: 
        				win_->close();
       					break;
				default:
					break;
			}
		}
		if (Play == 1){
			if (gravity == 1){
				sam->courrir();
				gravity = 0;
			}
			else{
				sam->gravity(0, SPEED2);
				sam->courrir();
			}
			win_->clear();
			sam->display(win_);
		}
		if (Round == 0){
			win_->clear();
			menu_->display(win_);
			menu_->display_texte(win_);
		}
		//win_->setPosition(sf::Vector2i(POSITION_FENETRE_X, POSITION_FENETRE_Y));
		win_->display();			
	}
}
