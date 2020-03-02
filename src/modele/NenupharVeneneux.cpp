/*********************************************
 * Définition de la classe NenupharVeneneux. *
 *********************************************/

#include "NenupharVeneneux.hpp"

/************
 * lireNom  *
 ************/
 
std::string NenupharVeneneux::lireNom() const{
	return "NenupharVeneneux";
}

/*******************
 * appliquerEffet  *
 *******************/
void 
NenupharVeneneux::appliquerEffet(Grenouille& grenouille) const {
	grenouille.infecter();
}
