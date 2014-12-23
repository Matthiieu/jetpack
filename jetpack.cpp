#include "jetpack.hpp"

using namespace std;

Jetpack::Jetpack()
{
	win_ = new sf::RenderWindow(sf::VideoMode(LONGUEUR_FENETRE, LARGEUR_FENETRE), "Jetpack Joyride", sf::Style::Close); 
	//win_->setPosition(sf::Vector2i(POSITION_FENETRE_X, POSITION_FENETRE_Y));
	//win_->setFramerateLimit(80);
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
  int Aide = 0;
  bool launch_heart;
  bool semaphore = true;
  bool semaphore2 = true;
  bool semaphore3 = true;
  int High_Score = 0;
  Personnage *sam = NULL;
  Fusee *fusee = NULL;
  Neon *neon = NULL;
  Cupcake *cupcake = NULL;
  Menu *menu_ = NULL;
  Heart *heart = NULL;
  menu_ = new Menu();
  Background *background = NULL;
  background = new Background("essaic.png", 0, 0);
  neon = new Neon;
  heart = new Heart;
  sam = new Personnage;
  cupcake = new Cupcake;
  fusee = new Fusee;
  sf:: Clock time;	//Compteur score
  sf:: Clock time2;	//Decompteur avant lancement jeu
  sf:: Clock time3;	//Decompteur avant lancement menu
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
        					  case 0:	//Play
							 Round = 1;
							 Aide = 1;
           					 	 audio_->stop_menu();
							 audio_->play_main();
						 	 time2.restart();
         					 	 break;
        				 	  case 1:	//Score
							Round = 1;
							High_Score = 1;
							audio_->stop_menu();
							audio_->play_score();
							time3.restart();
							break;
         				  	  default: break;
         					 }
					}
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Up){
						if ((Play == 1) && (semaphore3 == true)){
							sam->setPosition(sam->getX(), sam->getY());	
							sam->deplacer(0, SPEED);		
						}					
					}
					else if (event.key.code == sf::Keyboard::Down){
						if ((Play == 1) && (semaphore3 == false)){
							sam->setPosition(sam->getX(), sam->getY());	
							sam->deplacer(0, -SPEED);		
						}					
					}
					break;
				//ajouter un case event escape
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
					background->parade(NEON0, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(NEON0, 0);
					}
					sam->gravity(0, SPEED02, semaphore2);
					sam->run();
					neon->move(NEON0, 0);
					if (neon->from_scratch(neon->far_away(neon->getX()))){
						neon->setPosition(neon->getX(), neon->generator_number());
						neon->move(NEON0, 0);
					}
					sf::Time elapsed1 = time.getElapsedTime();

					if (elapsed1.asMilliseconds() > SOSO)
						Level = 1;
					if(((sam->collision2(sam->getX(), sam->getY(), neon->getX(), neon->getY())) == true)){
						sam->less_life();
					}
					if(((sam->collision4(sam->getX(), sam->getY(), heart->getX(), heart->getY())) == true)){
						cout << "Sam a gagné une vie supplémentaire!" << endl;
						sam->more_life();
						cout << sam->getLIFE() << endl;
					}
					win_->clear();
					background->display(win_);
					sam->display(win_);
					neon->display(win_);
					menu_->distance(win_, elapsed1.asMilliseconds());
					if (launch_heart == true)
						heart->move(NEON0, 0);
						heart->display(win_);
				}				
				break;
			case 1:
				if (Play == 1){
					background->parade(NEON1, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(NEON1, 0);
					}
					sam->gravity(0, SPEED12, semaphore2);
					sam->run();
					fusee->launch(ROCKET1, 0);
					neon->move(NEON1, 0);
					cupcake->move(NEON1, 0);
					if (fusee->from_scratch(fusee->far_away(fusee->getX()))){
						fusee->setPosition(fusee->getX(), fusee->generator_number());
						fusee->launch(ROCKET1, 0);
					}
					if (neon->from_scratch(neon->far_away(neon->getX()))){
						neon->setPosition(neon->getX(), neon->generator_number());
						neon->move(NEON1, 0);
					}
					if (semaphore == true){
						if(((sam->collision4(sam->getX(), sam->getY(), heart->getX(), heart->getY())) == true)){
							cout << "Sam a gagné une vie supplémentaire!" << endl;
							sam->more_life();
							cout << sam->getLIFE() << endl;
							semaphore = false;
						}
					}
					sf::Time elapsed2 = time.getElapsedTime();
					if (elapsed2.asMilliseconds() > HARD)
						Level = 2;
					if(((sam->collision1(sam->getX(), sam->getY(), fusee->getX(), fusee->getY())) == true)){
						sam->less_life();
					}
					if(((sam->collision2(sam->getX(), sam->getY(), neon->getX(), neon->getY())) == true)){
						sam->less_life();
					}
					win_->clear();
					background->display(win_);
					sam->display(win_);
					fusee->display(win_);
					neon->display(win_);
					cupcake->display(win_);
					menu_->distance(win_, elapsed2.asMilliseconds());
					if (launch_heart == true)
						heart->move(NEON0, 0);
						heart->display(win_);
				}
				break;
			case 2:
				if (Play == 1){
					background->parade(NEON1, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(NEON1, 0);
					}
					//menu_->display_vie(win_);
					sam->gravity(0, SPEED22, semaphore2);
					sam->run();
					fusee->launch(ROCKET2, 0);
					neon->move(NEON2, 0);
					if (fusee->from_scratch(fusee->far_away(fusee->getX()))){
						fusee->setPosition(fusee->getX(), fusee->generator_number());
						fusee->launch(ROCKET2, 0);
					}
					if (neon->from_scratch(neon->far_away(neon->getX()))){
						neon->setPosition(neon->getX(), neon->generator_number());
						neon->move(NEON2, 0);
					}
					sf::Time elapsed3 = time.getElapsedTime();
					if(((sam->collision1(sam->getX(), sam->getY(), fusee->getX(), fusee->getY())) == true)){
						sam->less_life();
					}
					if(((sam->collision2(sam->getX(), sam->getY(), neon->getX(), neon->getY())) == true)){
						sam->less_life();
					}
					neon->rotate();
					win_->clear();
					background->display(win_);
					sam->display(win_);
					fusee->display(win_);
					neon->display(win_);
					menu_->distance(win_, elapsed3.asMilliseconds());
					if (launch_heart == true)
						heart->move(NEON0, 0);
						heart->display(win_);
				}
				break;
			default:
				break;
		}
	/*********************************************************************************/ 
		if (Aide == 1){
			win_->clear();
			menu_->display_aide(win_);
			sf::Time elapsed4 = time2.getElapsedTime();
			int number = 10 - elapsed4.asSeconds();
			if (number < 1){
				Aide = 0;
				Level = 0;
				Play = 1;
				time.restart();
			}
			menu_->display_chrono(win_, number);
		}
	/*********************************************************************************/ 
		if(High_Score == 1){
			sf::Time elapsed5 = time3.getElapsedTime();
			int number = 6 - elapsed5.asSeconds();
			if (number < 1){
				Round = 0;
				High_Score = 0;
				audio_->stop_score();
			}
			win_->clear();
			menu_->display_chrono(win_, number);	
			menu_->reading_score(win_);
		}
	/*********************************************************************************/ //
		if (Loose == 1){
			sf::Time elapsed6 = time3.getElapsedTime();
			int number = 5 - elapsed6.asSeconds();
			if (number < 1){
				High_Score = 1;
				Loose = 0;
				time3.restart();
				audio_->stop_main();
				audio_->stop_menu();
				audio_->play_score();
			}
			Play = 0;
			win_->clear();
			menu_->display_looser(win_);
			sf::Time elapsed7 = time.getElapsedTime();
			//Obtenir le kilometrage et l'inscrire dans le fichier
			menu_->written_score(elapsed7.asMilliseconds());
			neon->from_scratch(true);
			fusee->from_scratch(true);
			background->from_scratch(true);
		}
	/*********************************************************************************/ // Menu!
		if (Round == 0){
			win_->clear();
			menu_->display(win_);
			menu_->display_texte(win_);
		}
	/*********************************************************************************/ //
		if (Play == 1){
			sf::Time elapsed7 = time2.getElapsedTime();
			if(elapsed7.asSeconds() > 13)
				launch_heart = true;
			else
				launch_heart = false;
			menu_->display_vie(win_, sam->getLIFE());
			if(((sam->collision3(sam->getX(), sam->getY(), cupcake->getX(), cupcake->getY())) == true)){
				cout << "Sam a mangé le cupcake" << endl;
				semaphore2 = false;
				semaphore3 = false;
			}
			if (sam->is_alive() == false){
				Play = 0;	//On sort de la gamePlay
				Loose = 1;	//On rentre dans la fenetre "Perdu"
			}
			
		}
		win_->display();			
	}
	delete sam;
	delete fusee;
	delete neon;
	delete background;
	delete cupcake;
	delete heart;
}
