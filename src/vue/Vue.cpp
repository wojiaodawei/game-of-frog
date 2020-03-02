#include "Vue.hpp"
#include "Presentateur.hpp"

/****************
 * initialiser. *
 ****************/
void
Vue::initialiser() {
    
    // Créations des pixbufs.
    images_["grenouille-verte"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "grenouille-verte-96x96.png");
    images_["grenouille-rouge"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "grenouille-rouge-96x96.png");
    images_["vie"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "coeur-96x91.png");
    
    images_["eau"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "eau-96x96.png");
    
    images_["grand-nenuphar-vert"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-vert-96x96.png");
    images_["grand-nenuphar-jaune"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-jaune-96x96.png");
    images_["grand-nenuphar-rose"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-rose-96x96.png");
    images_["grand-nenuphar-rouge"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-rouge-96x96.png");
    
    images_["moyen-nenuphar-vert"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "moyen-nenuphare-vert-96x96.png");
    images_["moyen-nenuphar-jaune"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "moyen-nenuphare-jaune-96x96.png");
    images_["moyen-nenuphar-rose"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "moyen-nenuphare-rose-96x96.png");
    images_["moyen-nenuphar-rouge"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "moyen-nenuphare-rouge-96x96.png");
    
    images_["petit-nenuphar-vert"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "petit-nenuphare-vert-96x96.png");
    images_["petit-nenuphar-jaune"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "petit-nenuphare-jaune-96x96.png");
    images_["petit-nenuphar-rose"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "petit-nenuphare-rose-96x96.png");
    images_["petit-nenuphar-rouge"] = Gdk::Pixbuf::create_from_file(cheminImages_ + "petit-nenuphare-rouge-96x96.png");

}

/********
 * Vue. *
 ********/
Vue::Vue(Presentateur& presentateur):
    presentateur_(presentateur),
	ptrGrenouillolandGraphique_(new GrenouillolandGraphique(titreGrenouilloland_, *this)),
	dimension_(titreDimension_, *this),
	chronometre_(titreChronometre_, *this),
	ptsVie_(titrePtsVie_, *this) {
		
    // Titre de la vue.
    set_title(titreVue_);
    
    // Gestionnaire de mise en forme associé à la fenêtre principale.
    Gtk::VBox* gestionnaire = Gtk::manage(new Gtk::VBox());
    add(*gestionnaire);
    
    // Construction de la barre de menus et d'outils.
    construireBarreMenusEtOutils(*gestionnaire);

    // Construction de la partie centrale de la fenêtre principale.
    construirePartieCentrale(*gestionnaire);
    
    // Construction de la partie inférieure de la fenêtre principale.
    construirePartieInferieure(*gestionnaire);
    
    // La fenêtre principale est rendue non redimensionnable. Cela permettra de
    // forcer le recalcul des dimensions lorsque la dimension du jeu de la grenouille
    // sera modifiée.
    set_resizable(false);
    
    // Affichage de tous les composants graphiques.
    show_all_children();  
}

/*****************
 * lireTitreVue. *
 *****************/
const Glib::ustring
Vue::lireTitreVue() {
    return titreVue_;
}

/************************
 * lireTitreJeuDeLaVie. *
 ************************/
const Glib::ustring
Vue::lireTitreGrenouilloland() {
    return titreGrenouilloland_;
}

/***********************
 * lireTitreDimension. *
 ***********************/
const Glib::ustring
Vue::lireTitreDimension() {
    return titreDimension_;
}

/**************
 * lireImage. *
 **************/
const Glib::RefPtr< Gdk::Pixbuf>&
Vue::lireImage(const Glib::ustring& nom) {
    return images_[nom];
}

/****************
 * mettreAJour. *
 ****************/
void 
Vue::mettreAJour(){
	ptrGrenouillolandGraphique_->mettreAJour(presentateur_);
}

/**********************
 * mettreAJourPtsVie. *
 **********************/
void
Vue::mettreAJourPtsVie() {
	ptsVie_.changerPtsVie();
}

/*****************
 * partiePerdue. *
 *****************/
void
Vue::partiePerdue() {
	// Construction du dialogue.
    Gtk::MessageDialog dialogue(*this, "PERDU !!!", false);
    
    dialogue.set_title("Vous avez perdu");
    
    // Affichage du dialogue.
    dialogue.run();
    //On recommence la partie
    presentateur_.reinitialiser(dimension_.lireValeur());
}

/*****************
 * partieGagnee. *
 *****************/
void 
Vue::partieGagnee() {
	// Construction du dialogue.
    Gtk::MessageDialog dialogue(*this, "VICTOIRE !!!", true);
    
    dialogue.set_title("Vous avez gagné");
    
    // Affichage du dialogue.
    dialogue.run();
    //On recommence la partie
    presentateur_.reinitialiser(dimension_.lireValeur());
}

/*****************
 * partieGagnee. *
 *****************/
void 
Vue::partieTerminee() {
	// Construction du dialogue.
    Gtk::MessageDialog dialogue(*this, "PERDU !!! La partie est terminée...", true);
    
    dialogue.set_title("Temps écoulé.");
    
    // Affichage du dialogue.
    dialogue.run();
    //On recommence la partie
    presentateur_.reinitialiser(dimension_.lireValeur());
}

/*********************
 * lirePresentateur. *
 *********************/
const Presentateur&
Vue::lirePresentateur() const {
    return presentateur_;
}

/*******************************
 * lirePresentateurModifiable. *
 *******************************/
Presentateur& 
Vue::lirePresentateurModifiable() {
	return presentateur_;
}

/*********************************
 * construireBarreMenusEtOutils. *
 *********************************/
void
Vue::construireBarreMenusEtOutils(Gtk::VBox& gestionnaire) {
    
    // Groupe d'actions.
    Glib::RefPtr< Gtk::ActionGroup > groupe = Gtk::ActionGroup::create();
    groupe->add(Gtk::Action::create("CommandesMenu",
                                    "Commandes"));
    
    // Action "Nouveau".
	{
		Glib::RefPtr< Gtk::Action > action = 
		Gtk::Action::create("CommandesNouveau", 
				Gtk::Stock::NEW,
				"Nouvelle partie",
				"Préparer une nouvelle partie.");
		auto crochet = sigc::mem_fun(*this, &Vue::cbNouveau);
		groupe->add(action, crochet); 
  }
    
    // Action "A propos ...".
    {
        Glib::RefPtr< Gtk::Action > action =
        Gtk::Action::create("CommandesAPropos",
                            Gtk::Stock::ABOUT,
                            "À propos ...",
                            "Présenter l'application.");
        auto crochet = sigc::mem_fun(*this, &Vue::cbAPropos);
        groupe->add(action, crochet);
    }
    
    // Action "Quitter".
    {
        Glib::RefPtr< Gtk::Action > action =
        Gtk::Action::create("CommandesQuitter",
                            Gtk::Stock::QUIT,
                            "Quitter",
                            "Quitter l'application.");
        auto crochet = sigc::mem_fun(*this, &Vue::cbQuitter);
        groupe->add(action, crochet);
    }
    
    // Manager des groupes d'actions.
    Glib::RefPtr< Gtk::UIManager > manager = Gtk::UIManager::create();
    manager->insert_action_group(groupe);
    add_accel_group(manager->get_accel_group());
    
    // Structures XML des barres de menus et d'outils.
    const Glib::ustring structures =
    "<ui>"
    "  <menubar name='BarreMenus'>"
    "    <menu action='CommandesMenu'>"
    "      <menuitem action='CommandesNouveau'/>"
    "      <menuitem action='CommandesAPropos'/>"
    "      <separator/>"
    "      <menuitem action='CommandesQuitter'/>"
    "    </menu>"
    "  </menubar>"
    "  <toolbar  name='BarreOutils'>"
    "    <toolitem action='CommandesNouveau'/>"
    "    <toolitem action='CommandesAPropos'/>"
    "    <toolitem action='CommandesQuitter'/>"
    "  </toolbar>"
    "</ui>";
    manager->add_ui_from_string(structures);
    
    // Ajout des barres de menus et d'outils dans le gestionnaire. Chacun
    // occupe une ligne complète de la grille.
    Gtk::Widget* ptrBarreMenus = manager->get_widget("/BarreMenus");
    if (ptrBarreMenus != nullptr) {
        gestionnaire.pack_start(*ptrBarreMenus, Gtk::PACK_SHRINK);
    }
    Gtk::Widget* ptrBarreOutils = manager->get_widget("/BarreOutils");
    if(ptrBarreOutils != nullptr) {
        gestionnaire.pack_start(*ptrBarreOutils, Gtk::PACK_SHRINK);
    }
}

/*****************************
 * construirePartieCentrale. *
 *****************************/
void
Vue::construirePartieCentrale(Gtk::VBox& gestionnaire) {
	//gestionnaire.add(ptsVie_);
	
	// Ajout du gestionnaire de mise en forme pour la partie centrale.
    gestionnaire.add(gestionnaireCentre_);
	
    gestionnaireCentre_.pack_start(ptsVie_);
	
    // Ajout du jeu de la vie graphique dans le gestionnaire de la partie
    // centrale.
    gestionnaireCentre_.pack_start(*ptrGrenouillolandGraphique_);
}

/*******************************
 * construirePartieInferieure. *
 *******************************/
void
Vue::construirePartieInferieure(Gtk::VBox& gestionnaire) {
    gestionnaire.add(dimension_);
    gestionnaire.add(chronometre_);
}


/********************
 * cbChangerModele. *
 ********************/
void
Vue::cbChangerModele() {
    // Création, via le présentateur, d'un nouveau modèle avec la dimension
    // souhaitée.
    presentateur_.reinitialiser(dimension_.lireValeur());
    
    // Suppression de l'ancien jeu de la vie graphique et remplacement par le
    // nouveau.
    gestionnaireCentre_.remove(*ptrGrenouillolandGraphique_); 
    ptrGrenouillolandGraphique_.reset(new GrenouillolandGraphique(titreGrenouilloland_,
                                                                  *this));
                                                                                                                               
    gestionnaireCentre_.pack_start(*ptrGrenouillolandGraphique_);
        
    // Réaffichage de tous les composants de la fenêtre principale. Le fait que
    // cette dernière soit non redimensionnable entraîne le recalcul des
    // dimensions de tous ses composants.
    show_all_children();
}

/****************
 * cbNouveau(). *
 ****************/
void
Vue::cbNouveau() {
	// Réinitialisation du modèle via le présentateur associé à cette vue.
	presentateur_.reinitialiser(dimension_.lireValeur());

	// Demander au jeu de la grenouille graphique de bien vouloir se mettre à jour.
	ptrGrenouillolandGraphique_->mettreAJour(presentateur_);
}

/****************
 * cbAPropos(). *
 ****************/
void
Vue::cbAPropos() {
    // Construction du dialogue.
    Gtk::AboutDialog apropos;
    apropos.set_transient_for(*this);
    apropos.set_program_name("Grenouilloland");
    apropos.set_version("0.1");
    apropos.set_copyright("David Condaminet - 21306226@etu.unicaen.fr \n Pierre Bernard - 21301373@etu.unicaen.fr \n Marwan Lakradi - 21301054@etu.unicaen.fr" );
    apropos.set_comments("Contrôle continu C++/Gtkmm du M1 Info.");
    apropos.set_authors({ "David Condaminet, Pierre Bernard, Marwan Lakradi" });

    // Affichage du dialogue.
    apropos.run();
    
    // Effacement du dialogue.
    apropos.hide();
}

/**************
 * cbQuitter. *
 **************/
void
Vue::cbQuitter() {
    hide();
}

void 
Vue::avanceChrono(const int& temps){
	chronometre_.changerTemps(temps);
	
	// Demander au jeu de la grenouille graphique de bien vouloir se mettre à jour.
	ptrGrenouillolandGraphique_->mettreAJour(presentateur_);
}

/**************
 * titreVue_. *
 **************/
const Glib::ustring Vue::titreVue_("Grenouilloland");

/*********************
 * titreGeneration_. *
 *********************/
const Glib::ustring Vue::titreGrenouilloland_("Mare aux grenouilles");

/********************
 * titreDimension_. *
 ********************/
const Glib::ustring Vue::titreDimension_("Résolution");

/**********************
 * titreChronometre_. *
 **********************/
const Glib::ustring Vue::titreChronometre_("Chronomètre");

/*****************
 * titrePtsVie_. *
 *****************/
const Glib::ustring Vue::titrePtsVie_("Points de vie");

/******************
 * cheminImages_. *
 ******************/
const Glib::ustring Vue::cheminImages_("src/ressources/");

/************
 * images_. *
 ************/
std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > Vue::images_;
