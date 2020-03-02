#include "Jeu.hpp"
#include <iostream>
#include <math.h> 

/*********
 * Jeu. *
 *********/

Jeu::Jeu(const int& dimension):
	dimension_(dimension),
	grenouille_(new Grenouille(0,dimension-1)){
	
	PtrStrategie ptr(new Eau());
	base[ptr->lireNom()]=std::move(ptr);
	PtrStrategie ptr1(new NenupharDepart());
	base[ptr1->lireNom()]=std::move(ptr1);
	PtrStrategie ptr2(new NenupharArrive());
	base[ptr2->lireNom()]=std::move(ptr2);
	PtrStrategie ptr3(new NenupharDopant());
	base[ptr3->lireNom()]=std::move(ptr3);
	PtrStrategie ptr4(new NenupharNutritif());
	base[ptr4->lireNom()]=std::move(ptr4);
	PtrStrategie ptr5(new Nenuphar());
	base[ptr5->lireNom()]=std::move(ptr5);
	PtrStrategie ptr6(new NenupharVeneneux());
	base[ptr6->lireNom()]=std::move(ptr6);
	PtrStrategie ptr7(new NenupharMortel());
	base[ptr7->lireNom()]=std::move(ptr7);
	
	
	for(int ligne=0; ligne<dimension_; ligne++){
        std::vector<Case*> ligne2;
		for(int colonne=0; colonne<dimension_;colonne++){
			ligne2.push_back(new Case(*(*base.find("Eau")).second));
		}
        cases.push_back(ligne2);
	}
    cases[0][dimension_-1]->changerEltSurface(*(*base.find("NenupharDepart")).second);
    cases[dimension_-1][0]->changerEltSurface(*(*base.find("NenupharArrive")).second);
	
	tracerLigneNenuphar(0,dimension_-1);
}
	
/****************************
 * appliquerVieillissement. *
 ****************************/
	
void 
Jeu::appliquerVieillissement() const {
	for(int ligne=0; ligne<dimension_; ligne++){
		for(int colonne=0; colonne<dimension_;colonne++){
			cases[ligne][colonne]->vieillir();
		}
	}
	if(cases[grenouille_->lireX()][grenouille_->lireY()]->lireNom()=="Eau"){
		cases[grenouille_->lireX()][grenouille_->lireY()]->appliquerEffet(*grenouille_);
	}
	tracerLigneNenuphar(grenouille_->lireX(),grenouille_->lireY());
}
	

/*************
 * deplacer. *
 *************/
 
bool 
Jeu::deplacer(const int& x,const int& y) const {
	int x1=grenouille_->lireX();
	int y1=grenouille_->lireY();
	if(!(fabs(x-x1)+fabs(y-y1)==1)){
		return false;
	}
	grenouille_->deplacer(x,y);
	cases[x][y]->appliquerEffet(*grenouille_);
	return true;
	
	
}

/******************
 * ajoutNenuphar. *
 ******************/

void 
Jeu::ajoutNenuphar(const int& x,const int& y) const {
    if(cases[x][y]->lireNom()=="Eau"){
		
        int alea=rand()%5;
        switch(alea)
        {
            case 0: {
                cases[x][y]->changerEltSurface(*(*base.find("NenupharDopant")).second);
                break;
            }
            case 1: {
                cases[x][y]->changerEltSurface(*(*base.find("NenupharNutritif")).second);
                break;
            }
            case 2: {
                cases[x][y]->changerEltSurface(*(*base.find("Nenuphar")).second);
                break;
            }
            case 3: {
                cases[x][y]->changerEltSurface(*(*base.find("NenupharVeneneux")).second);
                break;
            }
            case 4: {
                cases[x][y]->changerEltSurface(*(*base.find("NenupharMortel")).second);
                break;
            }
        }
    }
           
}

/************************
 * tracerLigneNenuphar. *
 ************************/

void
Jeu::tracerLigneNenuphar(const int& x,const int& y) const {
	for(int i=dimension_-1;i>=x;i--){
		for(int j=0;j<=y;j++){
			if(!(i!=x && j!=y)){
				ajoutNenuphar(i,j);
			}
			if(!(i!=dimension_-1 && j!=0)){
				ajoutNenuphar(i,j);
			}
		}
		
	}	
}
/******************
 * lireDimension. *
 ******************/

const int& 
Jeu::lireDimension() const{
	return dimension_;
}

/*******************
 * lireGrenouille. *
 *******************/
 
const Grenouille& 
Jeu::lireGrenouille() const{
	return *grenouille_;
}

/**************
 * lireCases. *
 **************/

const std::vector<std::vector<Case*> > 
Jeu::lireCases() const{
    return cases;
}

/*****************
 * reinitialise. *
 *****************/

void 
Jeu::reinitialise(const int& dimension) {
	cases.clear();
	dimension_ = dimension;
	for(int ligne=0; ligne<dimension_; ligne++){
        std::vector<Case*> ligne2;
		for(int colonne=0; colonne<dimension_;colonne++){
			ligne2.push_back(new Case(*(*base.find("Eau")).second));
		}
        cases.push_back(ligne2);
	}
    cases[0][dimension_-1]->changerEltSurface(*(*base.find("NenupharDepart")).second);
    cases[dimension_-1][0]->changerEltSurface(*(*base.find("NenupharArrive")).second);
	grenouille_ = new Grenouille(0,dimension-1);
	tracerLigneNenuphar(0,dimension_-1);
}

