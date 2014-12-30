#include "jetpack.hpp"

using namespace std;

/*******************************************************************
Liste des choses à faire:
-> Fonction qui dès que le personnage meurt, se penche.	XXX
-> Invincibilité du personnage avec le Cupcake.	XXX
-> Classe Croissant, ce croissant vous tue avec n'importe quel nombre de vie.	XXX
-> Ajouter pleins de sémaphore.
-> Trouver moyen pour que le personnage puisse pivoter (*2). Presque fait, manque le cas PERDU	XXX
-> Nettoyer les fichiers, rassembler les codes redondants.
-> Effacer les printfs, commenter.
-> Classe Bitcoin à implémenter.	XXX
-> Ajouter l'indicateur du nombre de pièce récoltée. XXX
-> Page aide? Surement... :/	XXX
-> Changer la musique du menu.	XXX
-> Ajouter donc 2 boutons. Bouton quitter et bouton aide. XXX
-> Implémenter la page aide. (Nouvelle musique, choix du fond, style, etc..).
-> Recommencer la page d'acceuil.	XXX
-> Problème lors de la relance du jeu. Créer une fonction initialisation..
-> Changer musique score.
-> Penser à une meilleure presentation de la page aide 
-> S occuper des fuites de mémoire. La classe Menu pose probleme. Sans doute la reconstruire.. XXX Reconstruite mais tjrs pb memoire
-> Changer le fond d'écran High Score..
-> Creer 3 types de collision (collision1, 2 et 3)..
-> Ameliorer page tu t'es pris un pain..
-> Ralentir vitesse bitcoin
-> Ajouter animation
*******************************************************************/

Jetpack::Jetpack()
{
	win_ = new sf::RenderWindow(sf::VideoMode(LONGUEUR_FENETRE, LARGEUR_FENETRE), "Jetpack Joyride", sf::Style::Close); 
	//win_->setPosition(sf::Vector2i(POSITION_FENETRE_X, POSITION_FENETRE_Y));
	win_->setFramerateLimit(80);
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
  bool launch_heart;
  bool semaphore = true;
  bool semaphore3 = true;	//verouillage changer de touche!	// En fait, le cupcake est un allié puisque tu es invincible :(
  bool semaphore4 = true;	//bloque une fois la collision avec le cupcake.	//A faire pour tous :(
  bool semaphore45 = true;
 // bool semaphore5 = true;	//semaphore collision baguette
  bool anti_gravity = false;
  int High_Score = 0;
  Personnage *sam = NULL;
  Fusee *fusee = NULL;
  Bitcoin *bitcoin = NULL;
  Neon *neon = NULL;
  Cupcake *cupcake = NULL;
  Menu *menu_ = NULL;
  Heart *heart = NULL;
  Croissant *croissant = NULL;
  menu_ = new Menu();
  Background *background = NULL;
  background = new Background("essaic.png", 0, 0);
  neon = new Neon;
  bitcoin = new Bitcoin;
  heart = new Heart;
  sam = new Personnage;
  cupcake = new Cupcake;
  fusee = new Fusee;
  croissant = new Croissant;
  sf:: Clock time;	//Compteur score
  sf:: Clock time2;	//Decompteur avant lancement jeu
  sf:: Clock time3;	//Decompteur avant lancement menu
  sf:: Clock time4;	//semaphore45
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
					background->parade(BACKGROUND0, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(BACKGROUND0, 0);
					}
					sam->gravity(0, SPEED0, anti_gravity);
					sam->run();
					cupcake->move(CUPCAKE0, 0);
					bitcoin->move(BITCOIN0, 0);
					croissant->move(BITCOIN0,0);
					neon->move(FRENCH_STICK0, 0);
					if (neon->from_scratch(neon->far_away(neon->getX()))){
						neon->setPosition(neon->getX(), neon->generator_number());
						neon->move(FRENCH_STICK0, 0);
					}
					sf::Time elapsed1 = time.getElapsedTime();

					if (elapsed1.asMilliseconds() > SOSO)
						Level = 1;
					if(((sam->collision2(sam->getX(), sam->getY(), neon->getX(), neon->getY() + 70)) == true)){
						if (anti_gravity == true){
							anti_gravity = false;
							semaphore3 = true;
							sam->run();
						}
						else
							sam->less_life();
						//semaphore5 = true;
					}
					if(((sam->collision4(sam->getX(), sam->getY(), heart->getX(), heart->getY())) == true)){
						audio_->play_vie();
						cout << "Sam a gagné une vie supplémentaire!" << endl;
						sam->more_life();
						cout << sam->getLIFE() << endl;
					}
					if(((sam->collision5(sam->getX(), sam->getY(), croissant->getX(), croissant->getY())) == true)){
						Play = 0;
						Loose = 1;
						time3.restart();
					}
					win_->clear();
					background->display(win_);
					sam->display(win_);
					neon->display(win_);
					bitcoin->display(win_);
					cupcake->display(win_);
					croissant->rotate();
					croissant->display(win_);
					menu_->distance(win_, elapsed1.asMilliseconds());
					if (launch_heart == true)
						heart->move(HEART0, 0);
						heart->display(win_);
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
					fusee->launch(BRIOCHE1, 0);
					neon->move(FRENCH_STICK1, 0);
					if (fusee->from_scratch(fusee->far_away(fusee->getX()))){
						fusee->setPosition(fusee->getX(), fusee->generator_number());
						fusee->launch(BRIOCHE1, 0);
					}
					if (neon->from_scratch(neon->far_away(neon->getX()))){
						neon->setPosition(neon->getX(), neon->generator_number());
						neon->move(FRENCH_STICK1, 0);
					}
						if(((sam->collision4(sam->getX(), sam->getY(), heart->getX(), heart->getY())) == true) && (semaphore == true)){
							semaphore = false;
							audio_->play_vie();
							sam->more_life();
						}
						semaphore = true;	// permet de reprendre un coeur
					sf::Time elapsed2 = time.getElapsedTime();
					if (elapsed2.asMilliseconds() > HARD)
						Level = 2;
					if(((sam->collision1(sam->getX(), sam->getY(), fusee->getX(), fusee->getY())) == true)){
						if (anti_gravity == true){
							anti_gravity = false;
							semaphore3 = true;
							sam->gravity(0, SPEED1, anti_gravity);
						}
						else
							sam->less_life();
					}
					if(((sam->collision2(sam->getX(), sam->getY(), neon->getX(), neon->getY() + 70)) == true)){
						if (anti_gravity == true){
							anti_gravity = false;
							semaphore3 = true;
							sam->gravity(0, SPEED1, anti_gravity);
						}
						else
							sam->less_life();
					}
					win_->clear();
					background->display(win_);
					sam->display(win_);
					bitcoin->display(win_);
					fusee->display(win_);
					neon->display(win_);
					menu_->distance(win_, elapsed2.asMilliseconds());
					if (launch_heart == true)
						heart->move(HEART0, 0);
						heart->display(win_);
				}
				break;
			case 2:
				if (Play == 1){
					background->parade(BACKGROUND2, 0);
					if (background->from_scratch(background->far_away(background->getX()))){
						background->setPosition(background->getX(), background->getY());
						background->parade(BACKGROUND2, 0);
					}
					//menu_->display_vie(win_);
					sam->gravity(0, SPEED2, anti_gravity);
					sam->run();
					bitcoin->move(BITCOIN0, 0);
					fusee->launch(BRIOCHE2, 0);
					neon->move(FRENCH_STICK2, 0);
					if (fusee->from_scratch(fusee->far_away(fusee->getX()))){
						fusee->setPosition(fusee->getX(), fusee->generator_number());
						fusee->launch(BRIOCHE2, 0);
					}
					if (neon->from_scratch(neon->far_away(neon->getX()))){
						neon->setPosition(neon->getX(), neon->generator_number());
						neon->move(FRENCH_STICK2, 0);
					}
					sf::Time elapsed3 = time.getElapsedTime();
					if(((sam->collision1(sam->getX(), sam->getY(), fusee->getX(), fusee->getY())) == true)){
						if (anti_gravity == true){
							anti_gravity = false;
							semaphore3 = true;
							sam->gravity(0, SPEED1, anti_gravity);
						}
						else
							sam->less_life();
					}
					if(((sam->collision2(sam->getX(), sam->getY(), neon->getX(), neon->getY() + 70)) == true)){
						if (anti_gravity == true){
							anti_gravity = false;
							semaphore3 = true;
							sam->gravity(0, SPEED1, true);
						}
						else
							sam->less_life();
					}
					neon->rotate();
					win_->clear();
					background->display(win_);
					sam->display(win_);
					bitcoin->display(win_);
					fusee->display(win_);
					neon->display(win_);
					menu_->distance(win_, elapsed3.asMilliseconds());
					if (launch_heart == true)
						heart->move(HEART0, 0);
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
			int number = 10 - elapsed4.asSeconds();
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
			int number = 10 - elapsed4.asSeconds();
			if (number < 1){
				Aide = 0;
				Round = 0;
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
			menu_->reading_score(win_);
			menu_->display_chrono(win_, number);	
			menu_->screenshot(win_);
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
			//Obtenir le kilometrage et l'inscrire dans le fichier
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
			sf::Time elapsed8 = time2.getElapsedTime();
			if(elapsed8.asSeconds() > 13)
				launch_heart = true;
			else
				launch_heart = false;
			menu_->display_vie(win_, sam->getLIFE());
			menu_->display_bitcoin(win_, bitcoin->getCOLLECTION());
			if (bitcoin->from_scratch(bitcoin->far_away(bitcoin->getX()))){
				bitcoin->setPosition(bitcoin->getX(), bitcoin->generator_number());
				bitcoin->move(10, 0);
			}
			if((sam->collision3(sam->getX(), sam->getY(), cupcake->getX(), cupcake->getY()) == true) && (semaphore4 == true)){
				semaphore4 = false;
				cout << "Sam a mangé le cupcake" << endl;
				audio_->play_cupcake();
				anti_gravity = true;	//Permet de savoir s'il est en anti-gravity
				semaphore3 = false;
			}
			if(bitcoin->getCOLLECTION() == 2){
				sam->more_life();
				bitcoin->restart_collection();
			}
			if (sam->is_alive() == false){
				audio_->play_crash();
				sam->bend();
				sam->display(win_);
				sf::Time elapsed7 = time.getElapsedTime();
				menu_->written_score(elapsed7.asMilliseconds());
				sf:: Image screen = win_->capture();
				screen.saveToFile("screenshot.jpg");	//Maybe le mettre plus tot!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				Play = 0;	//On sort de la gamePlay
				Loose = 1;	//On rentre dans la fenetre "Perdu"
			}
			if((sam->collision3(sam->getX(), sam->getY(), bitcoin->getX(), bitcoin->getY()) == true) && (semaphore45 == true)){
				cout << "Sam a attrapé une piece" << endl;
				audio_->play_cupcake();
				bitcoin->increase_collection();
				semaphore45 = false;
				time4.restart();
			}
			sf::Time elapsed9 = time4.getElapsedTime();		// mettre un timer pour remettre le semaphore a true
				if(elapsed9.asSeconds() > 2){
					semaphore45 = true;
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
	delete bitcoin;
	delete menu_;
	delete croissant;
}
