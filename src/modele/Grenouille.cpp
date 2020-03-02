/***************************************
 * Définition de la classe Grenouille. *
 ***************************************/

#include "Grenouille.hpp"


/***************
 * Grenouille. *
 ***************/

Grenouille::Grenouille(const int& x, const int& y):
	x_(x), 
	y_(y), 
	ptsVie_(1), 
	malade_(false), 
	vivante_(true), 
	gagnant_(false){
}

/***************
 * lirePtsVie. *
 ***************/

const int& Grenouille::lirePtsVie() const{
	return ptsVie_;
}

/**********
 * lireX. *
 **********/

const int& Grenouille::lireX() const{
	return x_;
}

/**********
 * lireY. *
 **********/

const int& Grenouille::lireY() const{
	return y_;
}

/****************
 * lireAncienX. *
 ****************/

const int& Grenouille::lireAncienX() const{
	return ancienX_;
}

/****************
 * lireAncienY. *
 ****************/

const int& Grenouille::lireAncienY() const{
	return ancienY_;
}

/***************
 * estVivante. *
 ***************/

const bool& Grenouille::estVivante() const{
	return vivante_;
}

/**************
 * estMalade. *
 **************/

const bool& Grenouille::estMalade() const{
	return malade_;
}

/******************
 * estVictorieux. *
 ******************/
 
const bool& Grenouille::estVictorieux() const{
	return gagnant_;
}

/******************
 * ajouterPtsVie. *
 ******************/

void Grenouille::modifierPtsVie(const int& points){
	ptsVie_ = points;
}

/************
 * mourrir. *
 ************/

void Grenouille::mourrir(){
	ptsVie_ = 0;
	vivante_ = false;
}

/*************
 * deplacer. *
 *************/

void Grenouille::deplacer(const int& x, const int& y){
	ancienX_ = x_;
	ancienY_ = y_;
	x_ = x;
	y_ = y;
}

/*************
 * infecter. *
 *************/

void Grenouille::infecter(){
	if(malade_){ //surinfection
		this->mourrir();
	}
	else{
		malade_ = true;
		//Si la grenouille n'a qu'un point de vie ont ne divise pas
		//ses points de vie par deux. Pour ne pas qu'elle meurt
		if(ptsVie_ > 1){
			ptsVie_ = ptsVie_ / 2;
		}
	}
}

/***********
 * guerir. *
 ***********/

void Grenouille::guerir(){
	malade_ = false;
}

/*************
 * victoire. *
 *************/
 
void Grenouille::victoire(){
	gagnant_ = true;
}
