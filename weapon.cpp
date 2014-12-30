#include "weapon.hpp"

using namespace std;

Weapon:: Weapon() {}

Weapon:: ~Weapon() {}



bool
Weapon:: far_away(int x){
	// Verifie si notre neon est partie bien loin...
	if (x < (-10))
		return true;
	else
		return false;
}
