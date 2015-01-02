#ifndef JETPACK_HPP
#define JETPACK_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "main.hpp"
#include "menu.hpp"
#include "audio.hpp"
#include "character.hpp"
#include "brioche.hpp"
#include "french_stick.hpp"
#include "background.hpp"
#include "cupcake.hpp"
#include "heart.hpp"
#include "bitcoin.hpp"
#include "croissant.hpp"



class Jetpack
{
public: 
  Jetpack ();
  ~Jetpack ();

  void launch ();

private:
  sf::RenderWindow *win_;
  Audio *audio_;
};


#endif // MAIN_HPP
