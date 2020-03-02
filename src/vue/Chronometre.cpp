/****************************
 * Définition de la classe. *
 ****************************/

#include "Presentateur.hpp"
#include "Chronometre.hpp"
#include <gtk/gtk.h>
/**************
 * Chronometre. *
 **************/

Chronometre::Chronometre(const Glib::ustring& titre, Vue& vue):
	Gtk::Frame(titre),
	ptrVue_(&vue){
		add(chronometre_);
	}

/************
 * lireVue. *
 ************/

const Vue& 
Chronometre::lireVue() const {
    return *ptrVue_;
}

/*****************
 * changerTemps. *
 *****************/

void 
Chronometre::changerTemps(const int& temps){
	chronometre_.set_fraction(temps/60.0);
}
