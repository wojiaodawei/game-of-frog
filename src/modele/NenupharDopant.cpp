/*******************************************
 * Définition de la classe NenupharDopant. *
 *******************************************/

#include "NenupharDopant.hpp"

/************
 * lireNom  *
 ************/
 
std::string NenupharDopant::lireNom() const{
	return "NenupharDopant";
}

/*******************
 * appliquerEffet  *
 *******************/
void 
NenupharDopant::appliquerEffet(Grenouille& grenouille) const {
	//Double les points de vie
	grenouille.modifierPtsVie(grenouille.lirePtsVie() * 2);
	//On guerrit la grenouille si elle est malade
	if(grenouille.estMalade()) {
		grenouille.guerir();
	}
}
