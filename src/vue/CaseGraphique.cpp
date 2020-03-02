/******************************************
 * Définition de la classe CaseGraphique. *
 ******************************************/

#include "CaseGraphique.hpp"
#include "Presentateur.hpp"

/******************
 * CaseGraphique. *
 ******************/

CaseGraphique::CaseGraphique(GrenouillolandGraphique& grenouillolandGraphique,
				const int& ligne,
				const int& colonne):
	grenouillolandGraphique_(grenouillolandGraphique),
	ligne_(ligne),
	colonne_(colonne) {

	// Obtention de la vue.
	const Vue& vue = grenouillolandGraphique_.lireVue();

	// Obtention du présentateur.
	const Presentateur& presentateur = vue.lirePresentateur();

	// Création des pixmaps représentants les états d'une cellule.
	{
	
    etats_["GrenouilleVerte"][0] = Pointer(new Gtk::Image(vue.lireImage("grenouille-verte")));
    etats_["GrenouilleRouge"][0] = Pointer(new Gtk::Image(vue.lireImage("grenouille-rouge")));
    
    etats_["Eau"][2] = Pointer(new Gtk::Image(vue.lireImage("eau")));
    etats_["NenupharDepart"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-vert")));
    etats_["NenupharArrive"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-vert")));
    
    etats_["NenupharDopant"][0] = Pointer(new Gtk::Image(vue.lireImage("petit-nenuphar-rouge")));
	etats_["NenupharDopant"][1] = Pointer(new Gtk::Image(vue.lireImage("moyen-nenuphar-rouge")));
	etats_["NenupharDopant"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-rouge")));

	
	etats_["NenupharVeneneux"][0] = Pointer(new Gtk::Image(vue.lireImage("petit-nenuphar-jaune")));
	etats_["NenupharVeneneux"][1] = Pointer(new Gtk::Image(vue.lireImage("moyen-nenuphar-jaune")));
	etats_["NenupharVeneneux"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-jaune")));
	
	etats_["NenupharNutritif"][0] = Pointer(new Gtk::Image(vue.lireImage("petit-nenuphar-rose")));
	etats_["NenupharNutritif"][1] = Pointer(new Gtk::Image(vue.lireImage("moyen-nenuphar-rose")));
	etats_["NenupharNutritif"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-rose")));

	
	etats_["NenupharMortel"][0] = Pointer(new Gtk::Image(vue.lireImage("petit-nenuphar-rouge")));
	etats_["NenupharMortel"][1] = Pointer(new Gtk::Image(vue.lireImage("moyen-nenuphar-rouge")));
	etats_["NenupharMortel"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-rouge")));
	
	etats_["Nenuphar"][0] = Pointer(new Gtk::Image(vue.lireImage("petit-nenuphar-vert")));
	etats_["Nenuphar"][1] = Pointer(new Gtk::Image(vue.lireImage("moyen-nenuphar-vert")));
	etats_["Nenuphar"][2] = Pointer(new Gtk::Image(vue.lireImage("grand-nenuphar-vert")));

	}

	// Connection du callback associé au click de souris.
	{
	  auto crochet = sigc::mem_fun(*this, &CaseGraphique::cbClickSouris);
	  signal_button_press_event().connect(crochet);
	}
	
	// Mise à jour de cette case graphique.
	mettreAJour(presentateur);

}

/********************************
 * liregrenouillolandGraphique. *
 ********************************/

const GrenouillolandGraphique& 
CaseGraphique::lireGrenouillolandGraphique() const {
  return grenouillolandGraphique_;
}

/**************
 * lireLigne. *
 **************/

const int& 
CaseGraphique::lireLigne() const {
  return ligne_;
}

/****************
 * lireColonne. *
 ****************/

const int& 
CaseGraphique::lireColonne() const {
  return colonne_;
}

/****************
 * mettreAJour. *
 ****************/

void 
CaseGraphique::mettreAJour(const Presentateur& presentateur) {
	
	std::string etat = "";
	int age = 1;
	
	
	
	if(presentateur.grenouilleEn(ligne_, colonne_)){
		
		//Mise à jour de la case ou etait la grenouille precedemment
		std::array<int, 2> pos = presentateur.grenouilleAnciennementEn();

		grenouillolandGraphique_.mettreAJourCase(presentateur, pos.front(), pos.back());
		
		if(presentateur.grenouilleMalade()){
			etat = "GrenouilleRouge";
		}
		else{
			etat = "GrenouilleVerte";
		}
	}
	else{
		// Obtention du nouvel état de la case du modèle correspondante via le 
		// présentateur.
		etat = presentateur.lireNomEltSurface(ligne_, colonne_);
		age = presentateur.lireAgeCase(ligne_, colonne_);		
	}
	
	// Obtention du pixmap correspondant.
	Gtk::Image& image = *etats_[etat][age-1];
	
	// Si l'état de cette case n'a pas changé, il n'y a rien à faire.
	if (&image == get_child()) {
		return;
	}

	// Sinon, suppression de l'ancien pixmap et affichage du nouveau.
	remove();
	add(image);
	image.show();
	
}

/******************
 * cbClickSouris. *
 ******************/

bool 
CaseGraphique::cbClickSouris(GdkEventButton* evt) {

  // Obtention de la vue modifiable.
  Vue& vue = grenouillolandGraphique_.lireVueModifiable();

  // Obtention du présentateur modifiable associé à la vue.
  Presentateur& presentateur = vue.lirePresentateurModifiable();

  /****************
   * A compléter. *
   ****************/
  presentateur.deplacerGrenouille(ligne_,colonne_);

  // Mise à jour de cette case graphique.
  mettreAJour(presentateur);

  // Systématiquement retourner la valeur vrai.
  return true;

}


