/*********************************
 * Définition de la classe Case. *
 *********************************/

#include <memory>

#include "Case.hpp"


/*********
 * Case. *
 *********/

Case::Case(const EltSurface& elt):
	elementSurface_(&elt), elementInitial_(&elt), age_(3){}

/*******************
 * lireEltSurface. *
 *******************/

const std::string Case::lireNom() const{
	return elementSurface_->lireNom();
}

/************
 * lireAge. *
 ************/

const int& Case::lireAge() const{
	return age_;
}

/**********************
 * changerEltSurface. *
 **********************/

void Case::changerEltSurface(const EltSurface& elt){
	elementSurface_ = &elt;
	age_ = 3;
}
	    
/*******************
 * appliquerEffet. *
 *******************/

void Case::appliquerEffet(Grenouille& grenouille) const{
	elementSurface_->appliquerEffet(grenouille);
}

/*************
 * vieillir. *
 *************/

void Case::vieillir(){
	if(elementSurface_->estVieillissante()){
		age_ -= 1;
	}
	if(age_ == 0){
		this->changerEltSurface(*std::move(elementInitial_));
	}
}
