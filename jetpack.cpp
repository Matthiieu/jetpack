#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "menu.hpp"
#include "jetpack.hpp"
#include "audio.hpp"
#include "personnage.hpp"
#include "fusee.hpp"
#include "neon.hpp"
#include "background.hpp"

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
 // audio_->play_menu();
  int Round = 0;
  int Play = 0;
  int gravity = 0;
  int Attaque = 0;
  int Loose =0;
  int First = 1;
  int ok1 = 0, ok2 = 0, ok3 = 0;
  Personnage *sam = NULL;
  Fusee *fusee = NULL;
  Neon *neon = NULL;
  Background *background = NULL;
  background = new Background;
  neon = new Neon;
  sam = new Personnage;
  fusee = new Fusee;
  sf:: Clock time;
  sf:: Clock time2;
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
           					// audio_->stop_menu();
						// audio_->play_fond();
						 sam->run();
						 sam->display(win_);
						time2.restart();
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
			sam->gravity(0, SPEED2);
			sam->run();
				fusee->launch(7, 0);
				neon->move(5, 0);
			if (fusee->from_scratch(fusee->far_away(fusee->getX()))){
				fusee->setPosition(fusee->getX(), fusee->generator_number());
				fusee->launch(7, 0);
			}
			if (neon->from_scratch(neon->far_away(neon->getX()))){
				neon->setPosition(neon->getX(), neon->generator_number());
				neon->move(5, 0);
			}
			win_->clear(sf::Color(ok1, ok2, ok3));
			sf::Time elapsed1 = time.getElapsedTime();
			//cout << elapsed1.asSeconds() << endl;
			if (elapsed1.asSeconds() > 5){
				ok1 = background->generator_number1();
				ok2 = background->generator_number2(), 
				ok3 = background->generator_number3();
				cout << ok1 << ok2 << ok3 << endl;
				time.restart();
			}			
			sam->display(win_);
			fusee->display(win_);
			neon->display(win_);
			sf::Time elapsed2 = time2.getElapsedTime();
			menu_->distance(win_, elapsed2.asMilliseconds());
			if(((sam->collision(sam->getX(), sam->getY(), fusee->getX(), fusee->getY())) == true) || (sam->collision(sam->getX(), sam->getY(), neon->getX(), (neon->getY() + 30))) == true){
				Play = 0;
				Loose = 1;
			}	
		}
		if (Loose == 1){
			win_->clear();
			menu_->display_looser(win_);
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
