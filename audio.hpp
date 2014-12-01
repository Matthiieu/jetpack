#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <SFML/Audio.hpp> 

class Audio{
	public:
	Audio () {
		music2fond_ = new sf::Music;
		music2menu_ = new sf::Music;
		music2help_ = new sf::Music;
		music2help_->openFromFile("boulanger.ogg");
		music2fond_->openFromFile("boulanger3.ogg");
		music2menu_->openFromFile("boulanger2.ogg");
	}

	~Audio(){
		delete music2fond_;
		delete music2menu_;
		delete music2help_;
	}

	void play_fond(void){
		music2fond_->play();
		music2fond_->setVolume(100);
	}

	void play_help(void){
		music2help_->play();
	}

	void stop_fond(void){
		music2fond_->stop();
	}
	
	void play_menu(void){
		music2menu_->play();
		music2menu_->setVolume(100);
	}

	void stop_menu(void){
		music2menu_->stop();
	}

	void stop_help(void){
		music2help_->stop();
	}

	private:
		sf:: Music *music2fond_;
		sf:: Music *music2menu_;
		sf:: Music *music2help_;
};

#endif
