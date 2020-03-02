/*****************************************
 * Définition de la classe Presentateur. *
 *****************************************/
#include <chrono>
#include <iostream>

#include "Presentateur.hpp"


/*****************
 * Presentateur. *
 *****************/
 
Presentateur::Presentateur(const int& dimensionMin, const int& dimensionMax, const int& dimension):
	dimensionMin_(dimensionMin), 
	dimensionMax_(dimensionMax), 
	jeu(new Jeu(dimension)),
	vue(new Vue(*this)) {
}

/*********************
 * lireDimensionMin. *
 *********************/
 
const int& Presentateur::lireDimensionMin() const{
	return dimensionMin_;
}

/*********************
 * lireDimensionMax. *
 *********************/
 
const int& Presentateur::lireDimensionMax() const{
	return dimensionMax_;
}

/******************
 * lireDimension. *
 ******************/
 
const int& Presentateur::lireDimension() const{
	return jeu->lireDimension();
}

/************
 * lireJeu. *
 ************/

const Jeu&
Presentateur::lireJeu() const {
    return *jeu;
}

/**********************
 * lireNomEltSurface. *
 **********************/
 
const std::string Presentateur::lireNomEltSurface(const int& x, const int& y) const {
	return jeu->lireCases()[x][y]->lireNom();
}

/****************
 * lireAgeCase. *
 ****************/
 
const int& Presentateur::lireAgeCase(const int& x, const int& y) const {
	return jeu->lireCases()[x][y]->lireAge();
}
	
/***********************
 * deplacerGrenouille. *
 ***********************/
 
void Presentateur::deplacerGrenouille(const int& x, const int& y){
	if(jeu->deplacer(x, y)){
		vue->mettreAJour();
		vue->mettreAJourPtsVie();
	
		if(!jeu->lireGrenouille().estVivante()){ //La grenouille est morte
			partieFinie=true;		
			vue->partiePerdue();
		}

		else if(jeu->lireGrenouille().estVictorieux()){ //La grenouille a gagné
			partieFinie=true;
			vue->partieGagnee();
		}
	}
}

/*****************
 * grenouilleEn. *
 *****************/
 
bool Presentateur::grenouilleEn(const int& x, const int& y) const{
	return jeu->lireGrenouille().lireX() == x && jeu->lireGrenouille().lireY() == y;
}

/*****************************
 * grenouilleAnciennementEn. *
 *****************************/

std::array<int, 2> Presentateur::grenouilleAnciennementEn() const{
	const int x = jeu->lireGrenouille().lireAncienX();
	const int y = jeu->lireGrenouille().lireAncienY();
	return {x, y};
}

/*********************
 * grenouilleMalade. *
 *********************/
 
bool Presentateur::grenouilleMalade() const{
	return jeu->lireGrenouille().estMalade();
}

/******************
 * reinitialiser. *
 ******************/
 
void Presentateur::reinitialiser(const int& nouvelle){
	vue->mettreAJour();
	vue->mettreAJourPtsVie();
	jeu->reinitialise(nouvelle);

	temps = 0;
	partieFinie=false;
}

/*********
 * tour. *
 *********/

bool Presentateur::tour(){
	if(!partieFinie){
		jeu->appliquerVieillissement();
		vue->avanceChrono(temps);
		vue->mettreAJourPtsVie();
		temps++;
	}
	if(!jeu->lireGrenouille().estVivante()&&!partieFinie){ //La grenouille est morte		
		partieFinie=true;
		vue->partiePerdue();
		return true;
	}else if(temps >= 61){ //Le temps est écoulé
		vue->partieTerminee();
		partieFinie=true;
		return true;
	}

	
	return true;
}
/**************
 * commencer. *
 **************/
 
void Presentateur::commencer(){
	temps = 1;
	partieFinie=false;
	sigc::slot<bool> tslot = sigc::mem_fun(*this, &Presentateur::tour);
    	Glib::signal_timeout().connect(tslot, 1000);
	Gtk::Main::run(*vue);
}







