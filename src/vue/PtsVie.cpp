/****************************
 * Définition de la classe. *
 ****************************/

#include "Presentateur.hpp"
#include "PtsVie.hpp"

/**************
 * Dimension. *
 **************/

PtsVie::PtsVie(const Glib::ustring& titre, Vue& vue):
   Gtk::Frame(titre),
   ptrVue_(&vue),
   ptsVie_(Vue::lireImage("vie")),
   labelPtsVie_() {
	   //affichage du nombre de point de vie de départ
	   labelPtsVie_.set_text(std::to_string(ptrVue_->lirePresentateur().lireJeu().lireGrenouille().lirePtsVie()));
	   
	   Gtk::VBox* gestionnaire = Gtk::manage(new Gtk::VBox());
	   //attachage de l'image et du texte à la vue
	   gestionnaire->pack_start(ptsVie_);
	   gestionnaire->pack_start(labelPtsVie_);
	   
	   add(*gestionnaire);

}

/************
 * lireVue. *
 ************/

const Vue& 
PtsVie::lireVue() const {
    return *ptrVue_;
}

/******************
 * changerPtsVie. *
 ******************/
 
void 
PtsVie::changerPtsVie() {
	const int ptsVie = ptrVue_->lirePresentateur().lireJeu().lireGrenouille().lirePtsVie();
	labelPtsVie_.set_text(std::to_string(ptsVie));
}

