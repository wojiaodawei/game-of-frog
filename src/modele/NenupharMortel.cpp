/*******************************************
 * Définition de la classe NenupharMortel. *
 *******************************************/

#include "NenupharMortel.hpp"

/************
 * lireNom  *
 ************/
 
std::string NenupharMortel::lireNom() const{
	return "NenupharMortel";
}

/*******************
 * appliquerEffet  *
 *******************/
void 
NenupharMortel::appliquerEffet(Grenouille& grenouille) const {
	//Tue la grenouille.
	grenouille.mourrir();
}
