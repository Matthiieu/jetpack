#ifndef JETPACK_HPP
#define JETPACK_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "jetpack.hpp"
#include "main.hpp"
#include "menu.hpp"
#include "audio.hpp"
#include "personnage.hpp"
#include "fusee.hpp"
#include "neon.hpp"
#include "background.hpp"

class Menu;

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
