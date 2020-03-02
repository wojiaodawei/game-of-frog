/*********************************************
 * Définition de la classe NenupharNutritif. *
 *********************************************/

#include "NenupharNutritif.hpp"

/************
 * lireNom  *
 ************/
 
std::string NenupharNutritif::lireNom() const{
	return "NenupharNutritif";
}

/*******************
 * appliquerEffet  *
 *******************/
void 
NenupharNutritif::appliquerEffet(Grenouille& grenouille) const {
	//Augmente la vie d'une unité
	grenouille.modifierPtsVie(grenouille.lirePtsVie() + 1);
	//On guerrit la grenouille si elle est malade
	if(grenouille.estMalade()) {
		grenouille.guerir();
	}
}
