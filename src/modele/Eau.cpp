/********************************
 * Définition de la classe Eau. *
 ********************************/

#include "Eau.hpp"

/************
 * lireNom  *
 ************/
 
std::string Eau::lireNom() const{
	return "Eau";
}

/*******************
 * appliquerEffet  *
 *******************/
void 
Eau::appliquerEffet(Grenouille& grenouille) const {
	//Tue la grenouille.
	grenouille.mourrir();
}
