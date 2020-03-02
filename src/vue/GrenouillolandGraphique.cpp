/****************************************************
 * Définition de la classe GrenouillolandGraphique. *
 ****************************************************/

#include "GrenouillolandGraphique.hpp"
#include "Presentateur.hpp"

/****************************
 * GrenouillolandGraphique. *
 ****************************/

GrenouillolandGraphique::GrenouillolandGraphique(const Glib::ustring& titre, Vue& vue):
  Gtk::AspectFrame(titre),
  vue_(vue) {

    // Ajout du gestionnaire dans le contour. 
    add(gestionnaire_);

    // Obtention du presentateur associe a la vue proprietaire.
    const Presentateur& presentateur = vue.lirePresentateur();

    // Obtention du modèle via le présentateur.
    const Jeu& modele = presentateur.lireJeu();

    // Obtention de dimension du modèle.
    const int& dimension = modele.lireDimension();
    
    // Boucle de création des cellules graphiques.
    for (int i = 0; i < dimension; i ++) {
      for (int j = 0; j < dimension; j ++) {
        CaseGraphique* caseGraphique = 
          Gtk::manage(new CaseGraphique(*this, i, j));
        gestionnaire_.attach(*caseGraphique, i, j, 1, 1);
        cases_.push_back(caseGraphique);
    }
  }

}

/************
 * lireVue. *
 ************/

const Vue& 
GrenouillolandGraphique::lireVue() const {
  return vue_;
}

/**********************
 * lireVueModifiable. *
 **********************/

Vue& 
GrenouillolandGraphique::lireVueModifiable() {
  return vue_;
}

/****************
 * mettreAJour. *
 ****************/

void 
GrenouillolandGraphique::mettreAJour(const Presentateur& presentateur) {
  for (CaseGraphique* ptrCase : cases_) {
    ptrCase->mettreAJour(presentateur);
  }
}

/********************
 * mettreAJourCase. *
 ********************/

void 
GrenouillolandGraphique::mettreAJourCase(const Presentateur& presentateur, const int& x, const int& y) {
  for (CaseGraphique* ptrCase : cases_) {
	  if(ptrCase->lireLigne() == x && ptrCase->lireColonne() == y){
		  ptrCase->mettreAJour(presentateur);
	  }
  }
}

