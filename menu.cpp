#include "menu.hpp"

using namespace std;

Menu:: Menu(){
	if(!texture_first.loadFromFile("foreground.png")){
		exit(1);
	}
	logo_first.setTexture(texture_first);
	logo_first.setPosition(0, 5);
}
	
Menu:: ~Menu(){
 //
}

void
Menu:: display_bouton(sf::RenderTarget *rt){
	//Bouton bouton_play_(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y1, "Play");
	//Bouton bouton_option_(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y1, "Score");
	Bouton bouton_aide_(BOUTON_RECTANGLE_MENU_X1, BOUTON_RECTANGLE_MENU_Y2, "Play");
	Bouton bouton_score_(BOUTON_RECTANGLE_MENU_X2, BOUTON_RECTANGLE_MENU_Y2, "Score");
	bouton_score_.display(rt);
	//bouton_option_.display(rt);
	bouton_aide_.display(rt);
	//bouton_play_.display(rt);
}

void 
Menu:: display_texte(sf::RenderTarget *rt){
	sf:: Text texte_;
	sf:: Text texte2_;
	sf:: Font font_;
	if(!font_.loadFromFile("font2.ttf")){
		exit(1);
	}
	texte_.setFont(font_);
	texte_.setRotation(-15);
	texte_.setCharacterSize(90);
	texte_.setColor(sf::Color::Black);
	texte_.setStyle(sf::Text::Bold);
	texte_.setPosition(50, 100 );
	texte_.setString("Welcome to the\n");
	texte2_.setFont(font_);
	//texte2_.setRotation(ROTATE);
	texte2_.setCharacterSize(120);
	texte2_.setColor(sf::Color::Black);
	texte2_.setPosition(180, 150);
	texte2_.setStyle(sf::Text::Bold);
	texte2_.setString("Jetpack Joyride\nAt the bakery!\n");
	rt->draw(texte_);
	rt->draw(texte2_);
}

void 
Menu:: written_score(int number){
	char buffer[6];
	gcvt(number, 6, buffer);
	ofstream fichier ("aide.txt", ios::app);
	if (fichier){
		//fichier << number << endl;
		fichier.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier en ecriture" << endl;
	}

}

void
Menu:: reading_score(sf::RenderTarget *rt){
	string string1, string2;
	//int number1, number2;
	int number;
	char buffer[6];
	char buffer2[6];
	int i = 1;
	sf:: Text texte_;
	sf:: Text texte2_;
	sf:: Text texte3_;
	sf:: Font font_;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	texte2_.setFont(font_);
	texte2_.setCharacterSize(40);
	texte2_.setColor(sf::Color::Red);
	texte2_.setString("Last Score:");
	texte2_.setPosition(30, 2);
	rt->draw(texte2_);
	ifstream fichier ("aide.txt", ios::in);
	if (fichier){
		// Changer la position du while-do! car le dernier chiffre s'écrit en 2 fois!!
		do{
			fichier >> number;
			//cout << number << endl;
			gcvt(number, 6, buffer);
			gcvt(i, 2, buffer2);
			texte3_.setFont(font_);
			texte3_.setCharacterSize(40);
			texte3_.setColor(sf::Color::Red);
			texte3_.setString(buffer2);
			texte3_.setPosition(10, 30 * i);
			texte_.setFont(font_);
			texte_.setCharacterSize(40);
			texte_.setColor(sf::Color::White);
			texte_.setPosition(70, 30 * i);
			texte_.setString(buffer);
			rt->draw(texte_);
			rt->draw(texte3_);
			i++;
		}while(!fichier.eof());
		fichier.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier en lecture" << endl;
	}
	//cout << string1 << string2 << endl;	
}

void
Menu:: screenshot(sf::RenderTarget *rt){
	if(!texture_screenshot.loadFromFile("screenshot.jpg")){
		exit(1);
	}
	logo_screenshot.setTexture(texture_screenshot);
	logo_screenshot.setRotation(10);
	logo_screenshot.setPosition(POSITION_SCREENSHOT_MENU_X, POSITION_SCREENSHOT_MENU_Y);
	logo_screenshot.setScale(ECHELLE_SCREENSHOT_MENU_X, ECHELLE_SCREENSHOT_MENU_Y);
	rt->draw(logo_screenshot);

}

void 
Menu:: distance(sf::RenderTarget *rt, int number){
		char buffer[6];
		gcvt(number, 6, buffer);
		sf:: Text texte_;
		sf:: Text texte2_;
		sf:: Font font_;
		if(!font_.loadFromFile("police.ttf")){
			exit(1);
		}
		texte_.setFont(font_);
		texte2_.setFont(font_);
		texte_.setCharacterSize(20);
		texte2_.setCharacterSize(20);
		texte_.setColor(sf::Color::White);
		texte2_.setColor(sf::Color::White);
		texte2_.setString("metres");
		texte_.setString(buffer);
		texte2_.setPosition(80, 0);
		rt->draw(texte_);
		rt->draw(texte2_);
}

void 
Menu:: display_vie(sf::RenderTarget *rt, int number){
	sf:: Texture vie_;
	sf:: Sprite sprite_vie_;
	if(!vie_.loadFromFile("vie.png")){
		exit(1);
	}
	sprite_vie_.setTexture(vie_);
	sprite_vie_.setPosition(600, 10);
	sprite_vie_.setScale(0.15f, 0.15f);
	char buffer[6];
	gcvt(number, 6, buffer);
	sf:: Text texte3_;
	//sf:: Text texte4_;
	sf:: Font font_;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	texte3_.setFont(font_);
	//texte4_.setFont(font_);
	texte3_.setCharacterSize(20);
	//texte4_.setCharacterSize(20);
	texte3_.setColor(sf::Color::White);
	//texte4_.setColor(sf::Color::White);
	//texte4_.setString("X");
	texte3_.setString(buffer);
	//texte4_.setPosition(630, 0);
	texte3_.setPosition(650, 10);
	rt->draw(texte3_);
	//rt->draw(texte4_);
	rt->draw(sprite_vie_);
}


void 
Menu:: display_chrono(sf::RenderTarget *rt, int number){
		char buffer[7];
		gcvt(number, 7, buffer);
		sf:: Text texte3_;
		sf:: Font font_;
		if(!font_.loadFromFile("police.ttf")){
			exit(1);
		}
		texte3_.setFont(font_);
		texte3_.setCharacterSize(60);
		texte3_.setColor(sf::Color::White);
		texte3_.setString(buffer);
		texte3_.setPosition(400, 400);
		rt->draw(texte3_);
}

void 
Menu:: display_looser(sf::RenderTarget *rt){
		sf:: Text texte_;
		sf:: Font font_;
		if(!font_.loadFromFile("police.ttf")){
			exit(1);
		}
		texte_.setFont(font_);
		texte_.setCharacterSize(100);
		texte_.setColor(sf::Color::White);
		texte_.setPosition(50, 100);
		texte_.setString("Tu t'es pris\n\t un pain!");
		rt->draw(texte_);
}

void 
Menu:: display(sf::RenderTarget *rt){
	rt->draw(logo_first);
	display_bouton(rt);
}

void
Menu:: display_aide(sf::RenderTarget *rt){
	sf:: Text texte_;
	sf:: Font font_;
	if(!font_.loadFromFile("police.ttf")){
		exit(1);
	}
	texte_.setFont(font_);
	texte_.setCharacterSize(30);
	texte_.setColor(sf::Color::White);
	texte_.setPosition(0, 20);
	texte_.setString("Aide Sam a eviter les projectiles lances par\n le boulanger.\n\n\n Pour cela, vous disposez d'une seule touche\n qui permet de surelever\n votre personnage.\n Attention aux cupcakes qui inversent\n la gravite et donc de touche!\n\n\nBon courage et surtout.. Bonne chance!");
	rt->draw(texte_);
}

int
Menu:: setCurrentAction(sf::Vector2i localPosition){
	cout << localPosition.x << endl << localPosition.y << endl;
	if(localPosition.y >= ZONE1 && localPosition.y <= ZONE2){
		if (localPosition.x >= ZONE3 && localPosition.x <= ZONE4){
			cout << "Play" << endl;
			return 0;
		}
		else if (localPosition.x >= ZONE5 && localPosition.x <= ZONE6){
			cout << "Score" << endl;
			return 1;
		}
	}
	return 2;
}
