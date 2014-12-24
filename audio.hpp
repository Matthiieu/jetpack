/*****************************************************/
/*  [EI-SE4] Polytech Paris UPMC                     */
/*---------------------------------------------------*/
/* BOULANGER MATTHIEU : matthieu.blngr@gmail.com     */
/*---------------------------------------------------*/
/*                  FILE : AUDIO.HPP                 */
/*****************************************************/

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
		music_vie = new sf::Music;
		music_cupcake = new sf::Music;
		music_crash = new sf::Music;
		music_main->openFromFile("main.ogg");
		music_menu->openFromFile("menu.ogg");
		music_score->openFromFile("score.ogg");
		music_vie->openFromFile("gagner_vie.ogg");
		music_cupcake->openFromFile("manger_cupcake.ogg");
		music_crash->openFromFile("crash.ogg");
	}

	~Audio(){
		delete music_main;
		delete music_menu;
		delete music_score;
		delete music_vie;
		delete music_cupcake;
		delete music_crash;
	}

	void play_main(void){
		music_main->play();
		music_main->setVolume(70);
	}

	void play_score(void){
		music_score->play();
		music_score->setVolume(70);
	}

	void play_menu(void){
		music_menu->play();
		music_menu->setVolume(100);
	}

	void play_vie(void){
		music_vie->play();
		music_vie->setVolume(100);
	}

	void play_cupcake(void){
		music_cupcake->play();
		music_cupcake->setVolume(100);
	}

	void play_crash(void){
		music_crash->play();
		music_crash->setVolume(100);
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
		sf:: Music *music_vie;
		sf:: Music *music_cupcake;
		sf:: Music *music_crash;
};

#endif
