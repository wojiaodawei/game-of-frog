/*******************************************
 * Définition de la classe NenupharArrive. *
 *******************************************/

#include "NenupharArrive.hpp"

/************
 * lireNom  *
 ************/
 
std::string NenupharArrive::lireNom() const{
	return "NenupharArrive";
}

/*******************
 * appliquerEffet  *
 *******************/
void 
NenupharArrive::appliquerEffet(Grenouille& grenouille) const {
    grenouille.victoire();
}
