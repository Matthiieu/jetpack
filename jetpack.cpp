/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : JETPACK.CPP               */
/*****************************************************/

#include "jetpack.hpp"

using namespace std;

Jetpack::Jetpack()
{
	win_ = new sf::RenderWindow(sf::VideoMode(LONGUEUR_FENETRE, LARGEUR_FENETRE), "Jetpack Joyride", sf::Style::Close); 
	win_->setFramerateLimit(FRAMERATELIMIT);
	audio_ = new Audio();
}

Jetpack::~Jetpack ()
{
  delete win_;
  delete audio_;
}

void
Jetpack::launch ()
{	
  audio_->play_menu();
  int Round = 0;
  int Play = 0;
  int Loose = 0;
  int Level = 0;
  int Presentation = 0;
  int Aide = 0;
  int High_Score = 0;
  bool semaphore = true;
  bool semaphore2 = true;	//verouillage changer de touche!
  bool semaphore4 = true;	//bloque une fois la collision avec le cupcake.	
  bool semaphore3 = true;
  bool semaphore5 = true;
  bool semaphore6 = true;
  bool anti_gravity = false;
  Character *sam = NULL;
  Brioche *brioche = NULL;
  Bitcoin *bitcoin = NULL;
  French_stick *french_stick = NULL;
  Cupcake *cupcake = NULL;
  Menu *menu_ = NULL;
  Heart *heart = NULL;
  Croissant *croissant = NULL;
  Background *background = NULL;
  menu_ = new Menu();
  background = new Background("Pictures/essaic.png", 0, 0);
  french_stick = new French_stick;
  bitcoin = new Bitcoin;
  heart = new Heart;
  sam = new Character;
  cupcake = new Cupcake;
  brioche = new Brioche;
  croissant = new Croissant;
  sf:: Clock time;	//Compteur score
  sf:: Clock time2;	//Decompteur avant lancement jeu
  sf:: Clock time3;	//Decompteur avant lancement menu
  sf:: Clock time4;	//semaphore3
/****************************************************************/
  while (win_->isOpen()){
		sf:: Event event;
		sf::Vector2i localPosition = sf::Mouse::getPosition();	
	/*********************************************************************************/ //BOUCLE EVENEMENT
		while((win_->pollEvent(event))){
			switch(event.type){
				case sf:: Event:: MouseButtonPressed:	
					if (Round == 0){		
						switch (menu_->setCurrentAction(localPosition)){
        					  case 0://Play
							 Round = 1;
							 Presentation = 1;
           					 	 audio_->stop_menu();
							 audio_->play_main();
						 	 time2.restart();
         					 	 break;
        				 	  case 1://Score
							Round = 1;
							High_Score = 1;
							audio_->stop_menu();
							audio_->play_score();
							time3.restart();
							break;
						case 2:	//Help
							 Round = 1;
							 Aide = 1;
							 audio_->stop_menu();
							 audio_->play_score();
						 	 time2.restart();
         					 	 break;
						case 3:	//Exit
							 win_->close();
         					 	 break;
         				  	  default: break;
         					 }
					}
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Up){
						if ((Play == 1) && (semaphore2 == true)){
							sam->setPosition(sam->getX(), sam->getY());	
							sam->deplacer(0, SPEED);		
						}					
					}
					else if (event.key.code == sf::Keyboard::Down){
						if ((Play == 1) && (semaphore2 == false)){
							sam->setPosition(sam->getX(), sam->getY());	
							sam->deplacer(0, -SPEED);		
						}					
					}
					else if (event.key.code == sf::Keyboard::Escape)
						win_->close();
					break;
				case sf::Event:: Closed: 
        				win_->close();
       					break;
				default:
					break;
			}
		}
	/*********************************************************************************/ // BOUCLE LEVEL
		switch(Level){
			case 0:
				if (Play == 1){
					background->parade(BACKGROUND0, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(BACKGROUND0, 0);
					}
					sam->gravity(0, SPEED0, anti_gravity);
					sam->run();
					bitcoin->move(BITCOIN0, 0);
					croissant->move(CROISSANT0,0);
					french_stick->move(FRENCH_STICK0, 0);
					if (french_stick->from_scratch(french_stick->far_away(french_stick->getX()))){
						french_stick->setPosition(french_stick->getX(), french_stick->generator_number());
						french_stick->move(FRENCH_STICK0, 0);
					}
					sf::Time elapsed1 = time.getElapsedTime();
					if (elapsed1.asMilliseconds() > SOSO){
						Level = 1;
						croissant->from_scratch(true);
					}
					win_->clear();
					background->display(win_);
					sam->display(win_);
					menu_->display_level(win_, 1);
					french_stick->display(win_);
					bitcoin->display(win_);
					croissant->rotate();
					croissant->display(win_);
					menu_->distance(win_, elapsed1.asMilliseconds());
				}				
				break;
			case 1:
				if (Play == 1){
					background->parade(BACKGROUND1, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(BACKGROUND1, 0);
					}
					sam->gravity(0, SPEED1, anti_gravity);
					sam->run();
					bitcoin->move(BITCOIN0, 0);
					brioche->launch(BRIOCHE1, 0);
					french_stick->move(FRENCH_STICK1, 0);
					cupcake->move(CUPCAKE1, 0);
					croissant->move(CROISSANT1,0);
					if (brioche->from_scratch(brioche->far_away(brioche->getX()))){
						brioche->setPosition(brioche->getX(), brioche->generator_number());
						brioche->launch(BRIOCHE1, 0);
					}
					if (french_stick->from_scratch(french_stick->far_away(french_stick->getX()))){
						french_stick->setPosition(french_stick->getX(), french_stick->generator_number());
						french_stick->move(FRENCH_STICK1, 0);
					}
					sf::Time elapsed2 = time.getElapsedTime();
					if (elapsed2.asMilliseconds() > HARD){
						Level = 2;
						croissant->from_scratch(true);
					}
					win_->clear();
					background->display(win_);
					sam->display(win_);
					bitcoin->display(win_);
					brioche->display(win_);
					croissant->rotate();
					menu_->display_level(win_, 2);
					croissant->display(win_);
					french_stick->display(win_);
					cupcake->display(win_);
					menu_->distance(win_, elapsed2.asMilliseconds());
				}
				break;
			case 2:
				if (Play == 1){
					background->parade(BACKGROUND2, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(BACKGROUND2, 0);
					}
					sam->gravity(0, SPEED2, anti_gravity);
					sam->run();
					bitcoin->move(BITCOIN0, 0);
					brioche->launch(BRIOCHE2, 0);
					heart->move(HEART2, 0);
					french_stick->move(FRENCH_STICK2, 0);
					if (brioche->from_scratch(brioche->far_away(brioche->getX()))){
						brioche->setPosition(brioche->getX(), brioche->generator_number());
						brioche->launch(BRIOCHE2, 0);
					}
					if (french_stick->from_scratch(french_stick->far_away(french_stick->getX()))){
						french_stick->setPosition(french_stick->getX(), french_stick->generator_number());
						french_stick->move(FRENCH_STICK2, 0);
					}
					sf::Time elapsed3 = time.getElapsedTime();
					french_stick->rotate();
					win_->clear();
					background->display(win_);
					sam->display(win_);
					bitcoin->display(win_);
					brioche->display(win_);
					menu_->display_level(win_, 0);
					french_stick->display(win_);
					menu_->distance(win_, elapsed3.asMilliseconds());
					heart->display(win_);
				}
				break;
			default:
				break;
		}
	/*********************************************************************************/ 
		if (Presentation == 1){
			win_->clear();
			menu_->display_presentation(win_);
			sf::Time elapsed4 = time2.getElapsedTime();
			int number = DECOMPTEUR1 - elapsed4.asSeconds();
			if (number < 1){
				Presentation = 0;
				Level = 0;
				Play = 1;
				time.restart();
			}
			menu_->display_chrono(win_, number);
		}
	/*********************************************************************************/ 
		if (Aide == 1){
			win_->clear();
			menu_->display_aide(win_);
			sf::Time elapsed4 = time2.getElapsedTime();
			int number = DECOMPTEUR2 - elapsed4.asSeconds();
			if (number < 1){
				Aide = 0;
				Round = 0;
				audio_->stop_score();
				audio_->play_menu();
			}
			menu_->display_chrono(win_, number);
		}
	/*********************************************************************************/ 
		if(High_Score == 1){
			sf::Time elapsed5 = time3.getElapsedTime();
			int number = DECOMPTEUR1 - elapsed5.asSeconds();
			if (number < 1){
				Round = 0;
				High_Score = 0;
				audio_->stop_score();
  				audio_->play_menu();
			}
			win_->clear();
			menu_->reading_score(win_);
			menu_->display_chrono(win_, number);	
			menu_->screenshot(win_);
		}
	/*********************************************************************************/ //
		if (Loose == 1){
			sf::Time elapsed6 = time3.getElapsedTime();
			int number = DECOMPTEUR3 - elapsed6.asSeconds();
			if (number < 1){
				High_Score = 1;
				Loose = 0;
				sam->more_life();
				french_stick->initial();
				time3.restart();
				audio_->stop_main();
				audio_->stop_menu();
				audio_->play_score();
			}
			Play = 0;
			win_->clear();
			menu_->display_looser(win_);
			french_stick->from_scratch(true);
			brioche->from_scratch(true);
			background->from_scratch(true);
			croissant->from_scratch(true);
			croissant->from_scratch(true);
			heart->from_scratch(true);
			bitcoin->from_scratch(true);
  			semaphore2 = true;
		   	semaphore4 = true;	
 			semaphore3 = true;
		 	anti_gravity = false;
		}
	/*********************************************************************************/ // Menu!
		if (Round == 0){
			win_->clear();
			menu_->display(win_);
			menu_->display_texte(win_);
		}
	/*********************************************************************************/ //
		if (Play == 1){
			menu_->display_vie(win_, sam->getLIFE());
			menu_->display_bitcoin(win_, bitcoin->getCOLLECTION());
			if (bitcoin->from_scratch(bitcoin->far_away(bitcoin->getX()))){
				bitcoin->setPosition(bitcoin->getX(), bitcoin->generator_number());
				bitcoin->move(BITCOIN1, 0);
			}
			if(((sam->collision2(sam->getX(), sam->getY(), french_stick->getX(), french_stick->getY() + OFFSET)) == true) && (semaphore5 == true)){
				if (anti_gravity == true){
					anti_gravity = false;
					semaphore2 = true;
					sam->run();
				}
				else
					sam->less_life();
				semaphore5 = false;
				time4.restart();
			}
			if(((sam->collision1(sam->getX(), sam->getY(), heart->getX(), heart->getY())) == true) && (semaphore6 == true)){
				audio_->play_vie();
				sam->more_life();
				semaphore6 = false;
				time4.restart();
			}
			if(((sam->collision1(sam->getX(), sam->getY(), croissant->getX(), croissant->getY())) == true)){
				sf:: Image screen = win_->capture();
				screen.saveToFile("Pictures/screenshot.jpg");
				audio_->play_crash();
				sf::Time elapsed7 = time.getElapsedTime();
				menu_->written_score(elapsed7.asMilliseconds());
				Play = 0;	//On sort de la gamePlay
				Loose = 1;	//On rentre dans la fenetre "Perdu"
				time3.restart();
			}
			if(((sam->collision1(sam->getX(), sam->getY(), brioche->getX(), brioche->getY())) == true) && (semaphore == true)){
				if (anti_gravity == true){
					anti_gravity = false;
					semaphore2 = true;
					sam->gravity(0, SPEED1, anti_gravity);
				}
				else
					sam->less_life();
				time4.restart();
				semaphore = false;
			}
			if((sam->collision1(sam->getX(), sam->getY(), cupcake->getX(), cupcake->getY()) == true) && (semaphore4 == true)){
				semaphore4 = false;
				audio_->play_cupcake();
				anti_gravity = true;	//Permet de savoir s'il est en anti-gravity
				semaphore2 = false;
			}
			if(bitcoin->getCOLLECTION() == 2){
				sam->more_life();
				bitcoin->restart_collection();
			}
			if (sam->is_alive() == false){
				sf:: Image screen = win_->capture();
				screen.saveToFile("Pictures/screenshot.jpg");
				audio_->play_crash();
				sf::Time elapsed7 = time.getElapsedTime();
				menu_->written_score(elapsed7.asMilliseconds());
				Play = 0;	//On sort de la gamePlay
				Loose = 1;	//On rentre dans la fenetre "Perdu"
				time3.restart();
			}
			if((sam->collision1(sam->getX(), sam->getY(), bitcoin->getX(), bitcoin->getY()) == true) && (semaphore3 == true)){
				audio_->play_bitcoin();
				bitcoin->increase_collection();
				semaphore3 = false;
				time4.restart();
			}
			sf::Time elapsed9 = time4.getElapsedTime();
				if(elapsed9.asSeconds() > 2){
					semaphore3 = true;
					semaphore5 = true;
					semaphore6 = true;
					semaphore = true;
				}
		}
		win_->display();
	}
	delete sam;
	delete french_stick;
	delete brioche;
	delete background;
	delete cupcake;
	delete heart;
	delete bitcoin;
	delete menu_;
	delete croissant;
}
