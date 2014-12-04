#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <SFML/Audio.hpp>

class Audio
{
	public:
	Audio () {
		music_main = new sf::Music;
		music_menu = new sf::Music;
		music_score = new sf::Music;
		music_main->openFromFile("main.ogg");
		music_menu->openFromFile("menu.ogg");
		music_score->openFromFile("score.ogg");
	}

	~Audio(){
		delete music_main;
		delete music_menu;
		delete music_score;
	}

	void play_main(void){
		music_main->play();
		music_main->setVolume(100);
	}

	void play_score(void){
		music_score->play();
		music_score->setVolume(100);
	}

	void play_menu(void){
		music_menu->play();
		music_menu->setVolume(100);
	}

	void stop_main(void){
		music_main->stop();
	}

	void stop_score(void){
		music_score->stop();
	}

	void stop_menu(void){
		music_menu->stop();
	}

	private:
		sf:: Music *music_main;
		sf:: Music *music_score;
		sf:: Music *music_menu;
};

#endif
