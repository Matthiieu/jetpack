#include "menu.hpp"

using namespace std;

Menu:: Menu(){
	texture_first.loadFromFile("Pictures/foreground.png");
	logo_first = new sf::Sprite;
	logo_first->setTexture(texture_first);
	logo_first->setPosition(0, 0);
	bouton_play_ = new Button(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y2 - 80, "Play");
	bouton_score_ = new Button(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y2 - 80, "Score");
	bouton_quitter_ = new Button(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y2 + 40, "Exit");
	bouton_aide_ = new Button(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y2 + 40, "Help");
	logo_screenshot = new sf::Sprite;

	font_2 = new sf::Font;
	if(!font_2->loadFromFile("Font/font_help.ttf")){
		cout << "erreur"<< endl;
	}

	font_ = new sf::Font;
	if(!font_->loadFromFile("Font/font2.ttf")){
		cout << "erreur"<< endl;
	}

	sprite_bitcoin_ = new sf::Sprite;
	if(!bitcoin_.loadFromFile("Pictures/bitcoin1.png")){
		exit(1);
	}

	sprite_blesse = new sf::Sprite;
	if(!blesse_.loadFromFile("Pictures/blesse.png")){
		exit(1);
	}

	logo_score = new sf::Sprite;
	if(!texture_score.loadFromFile("Pictures/fond_score.png")){
		exit(1);
	}
	logo_score->setTexture(texture_score);

	sprite_vie_ = new sf::Sprite;
	if(!vie_.loadFromFile("Pictures/vie.png")){
		exit(1);
	}
}
	
Menu:: ~Menu(){
 	delete logo_first;
	delete logo_screenshot;
	delete font_;
	delete bouton_play_;
	delete bouton_aide_;
	delete bouton_quitter_;
	delete bouton_score_;
	delete sprite_bitcoin_;
	delete sprite_vie_;
	delete logo_score;
}

void
Menu:: display_bouton(sf::RenderTarget *rt){
	bouton_score_->display(rt);
	bouton_play_->display(rt);
	bouton_quitter_->display(rt);
	bouton_aide_->display(rt);
}

void 
Menu:: display_texte(sf::RenderTarget *rt){
	sf:: Text texte_;
	sf:: Text texte2_;
	texte_.setFont(*font_);
	texte_.setRotation(-15);
	texte_.setCharacterSize(70);
	texte_.setColor(sf::Color::Black);
	texte_.setStyle(sf::Text::Bold);
	texte_.setPosition(50, 80 );
	texte_.setString("Welcome to the\n");
	texte2_.setFont(*font_);
	texte2_.setCharacterSize(100);
	texte2_.setColor(sf::Color::Black);
	texte2_.setPosition(140, 110);
	texte2_.setStyle(sf::Text::Bold);
	texte2_.setString("Jetpack Joyride\n   At the bakery!\n");
	rt->draw(texte_);
	rt->draw(texte2_);
}

void
Menu:: written_score(int number){
	char buffer[6];
	gcvt(number, 6, buffer);
	ifstream fichier("score.txt");
	if (fichier){
		stringstream buffer2;
		buffer2 << fichier.rdbuf();
		string timeString = buffer2.str();
		ofstream fichier2("score.txt");
		fichier2 << number << endl;
		fichier2 << timeString << endl;
		fichier2.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier en lecture" << endl;
	fichier.close();
}


void
Menu:: reading_score(sf::RenderTarget *rt){
	string string1, string2;
	int number;
	char buffer[6];
	char buffer2[6];
	int i = 1;
	sf:: Text texte3_;
	sf:: Text texte4_;
	sf:: Text texte5_;
	texte4_.setFont(*font_2);
	texte4_.setCharacterSize(40);
	texte4_.setColor(sf::Color::Red);
	texte4_.setString("Last Score:");
	texte4_.setPosition(30, 2);
	rt->draw(*logo_score);
	rt->draw(texte4_);
	ifstream fichier ("score.txt", ios::in);
	if (fichier){
		while((!fichier.eof()) && i <= 10){
			fichier >> number;
			gcvt(number, 6, buffer);
			gcvt(i, 2, buffer2);
			texte5_.setFont(*font_2);
			texte5_.setCharacterSize(40);
			texte5_.setColor(sf::Color::Red);
			texte5_.setString(buffer2);
			texte5_.setPosition(10, 50 * i);
			texte3_.setFont(*font_2);
			texte3_.setCharacterSize(40);
			texte3_.setColor(sf::Color::White);
			texte3_.setPosition(70, 50 * i);
			texte3_.setString(buffer);
			rt->draw(texte3_);
			rt->draw(texte5_);
			i++;
		}
		fichier.clear();
		fichier.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier en lecture" << endl;
	}
}

void
Menu:: screenshot(sf::RenderTarget *rt){
	texture_screenshot.loadFromFile("Pictures/screenshot.jpg");
	logo_screenshot->setTexture(texture_screenshot);
	logo_screenshot->setRotation(10);
	logo_screenshot->setPosition(POSITION_SCREENSHOT_MENU_X, POSITION_SCREENSHOT_MENU_Y);
	logo_screenshot->setScale(ECHELLE_SCREENSHOT_MENU_X, ECHELLE_SCREENSHOT_MENU_Y);
	rt->draw(*logo_screenshot);

}

void 
Menu:: distance(sf::RenderTarget *rt, int number){
		char buffer[6];
		gcvt(number, 6, buffer);
		sf:: Text texte6_;
		sf:: Text texte7_;
		texte7_.setFont(*font_2);
		texte6_.setFont(*font_2);
		texte7_.setCharacterSize(20);
		texte6_.setCharacterSize(20);
		texte7_.setColor(sf::Color::Red);
		texte6_.setColor(sf::Color::Red);
		texte7_.setString("metres");
		texte6_.setString(buffer);
		texte6_.setPosition(0, 5);
		texte7_.setPosition(80, 5);
		rt->draw(texte6_);
		rt->draw(texte7_);
}

void 
Menu:: display_bitcoin(sf::RenderTarget *rt, int number){
	sprite_bitcoin_->setTexture(bitcoin_);
	sprite_bitcoin_->setPosition(380, 5);
	sprite_bitcoin_->setScale(0.03f, 0.03f);
	char buffer[6];
	gcvt(number, 6, buffer);
	sf:: Text texte8_;
	texte8_.setFont(*font_2);
	texte8_.setCharacterSize(20);
	texte8_.setColor(sf::Color::Red);
	texte8_.setString(buffer);
	texte8_.setPosition(420, 10);
	rt->draw(texte8_);
	rt->draw(*sprite_bitcoin_);
}

void 
Menu:: display_vie(sf::RenderTarget *rt, int number){
	sprite_vie_->setTexture(vie_);
	sprite_vie_->setPosition(600, 5);
	sprite_vie_->setScale(0.15f, 0.15f);
	char buffer[6];
	gcvt(number, 6, buffer);
	sf:: Text texte9_;
	texte9_.setFont(*font_2);
	texte9_.setCharacterSize(20);
	texte9_.setColor(sf::Color::Red);
	texte9_.setString(buffer);
	texte9_.setPosition(650, 10);
	rt->draw(texte9_);
	rt->draw(*sprite_vie_);
}


void 
Menu:: display_chrono(sf::RenderTarget *rt, int number){
		char buffer[7];
		gcvt(number, 7, buffer);
		sf:: Text texte10_;
		texte10_.setFont(*font_2);
		texte10_.setCharacterSize(80);
		texte10_.setColor(sf::Color::White);
		texte10_.setString(buffer);
		texte10_.setPosition(630, 475);
		rt->draw(texte10_);
}

void 
Menu:: display_looser(sf::RenderTarget *rt){
		sf:: Text texte_11;
		sprite_blesse->setTexture(blesse_);
		sprite_blesse->setPosition(20, 100);
		sprite_blesse->setScale(0.5f, 0.5f);
		texte_11.setFont(*font_2);
		texte_11.setCharacterSize(90);
		texte_11.setColor(sf::Color::White);
		texte_11.setPosition(330, 180);
		texte_11.setString("Tu t'es pris\n  un pain!");
		rt->draw(texte_11);
		rt->draw(*sprite_blesse);
}

void 
Menu:: display(sf::RenderTarget *rt){
	rt->draw(*logo_first);
	display_bouton(rt);
}

void
Menu:: display_presentation(sf::RenderTarget *rt){
	sf:: Text texte_12;
	texte_12.setFont(*font_2);
	texte_12.setCharacterSize(30);
	texte_12.setColor(sf::Color::Black);
	texte_12.setStyle(sf::Text::Bold);
	texte_12.setPosition(0, 20);
	texte_12.setString("Le boulanger n'arrive plus a joindre les deux bouts: il est\nau bord de la faillite!!\nAide Sam a raisonner le boulanger en evitant ses\nprojectiles.\n\nSituation: Vous vous situez dans les rues de Paris a\nla poursuite du boulanger. Ce dernier tres enerve a decide\nde vous lancer sa fournee.\n\nLes brioches, baguettes et croissants sont vos ennemis.\n\nVous disposez d'une touche qui permet de surelever votre\npersonnage.\n\nBon courage et surtout.. Bonne chance!");
	rt->draw(*logo_first);
	rt->draw(texte_12);
}

void
Menu:: display_aide(sf::RenderTarget *rt){
	sf:: Text texte_13;
	texte_13.setFont(*font_2);
	texte_13.setCharacterSize(50);
	texte_13.setColor(sf::Color::Black);
	texte_13.setStyle(sf::Text::Bold);
	texte_13.setPosition(0, 20);
	texte_13.setString("Vous avez a votre disposition une seule touche\n(fleche du haut) pour surelever votre\npersonnage. Lorsque celui-ci a\nmange le cupcake, vous avez la touche\n directionnelle 'Down'.\n La gravite a change. Si vous tapez\ncontre une baguette, c est moins 1 vie.\nSi c est contre une brioche c est moins 1 vie.\nSi c est le coeur c est plus 1 vie.\nSi c est un croissant, vous perdez\ntous vos vies. Si c est une piece,\nau bout de 10, c es plus une vie.");
	rt->draw(*logo_first);
	rt->draw(texte_13);
}

int
Menu:: setCurrentAction(sf::Vector2i localPosition){
	cout << localPosition.x << endl << localPosition.y << endl;
	if(localPosition.y >= ZONE1 && localPosition.y <= ZONE2){
		if (localPosition.x >= ZONE5 && localPosition.x <= ZONE6){
			cout << "Play" << endl;
			return 0;
		}
		else if (localPosition.x >= ZONE7 && localPosition.x <= ZONE8){
			cout << "Score" << endl;
			return 1;
		}
	}
	else if (localPosition.y >= ZONE3 && localPosition.y <= ZONE4){
		if (localPosition.x >= ZONE5 && localPosition.x <= ZONE6){
			cout << "Help" << endl;
			return 2;
		}
		else if (localPosition.x >= ZONE7 && localPosition.x <= ZONE8){
			cout << "Exit" << endl;
			return 3;
		}
	}
	return 4;	//Rien de spécial
}
