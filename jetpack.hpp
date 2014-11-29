#ifndef JETPACK_HPP
#define JETPACK_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "menu.hpp"
#include "audio.hpp"
#include "personnage.hpp"

class Jetpack
{
public: 
  Jetpack ();
  ~Jetpack ();

  void launch ();

private:
  Menu *menu_;
  sf::RenderWindow *win_;
  Audio *audio_;
};


#endif // MAIN_HPP
