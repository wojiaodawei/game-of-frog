#ifndef Vue_hpp
#define Vue_hpp

#include "GrenouillolandGraphique.hpp"
#include "Dimension.hpp"
#include "Chronometre.hpp"
#include "PtsVie.hpp"

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/stock.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/cellrendererpixbuf.h>
#include <map>

// Déclaration incomplète de la classe Presentateur.
class Presentateur;

/**
 * @class Vue Vue.hpp
 *
 * Déclaration de la classe Vue représentant l'interface graphique de
 * l'application Grenouilloland
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class Vue: public Gtk::Window {

public:
    
    // Déclarations d'amitié envers les classes CelluleGraphique et Dimension.
    friend class CaseGraphique;
    friend class Dimension;
    
public:
    /**
     * Initialise cette classe.
     *
     * @note cette méthode doit être appelée avant toutes les autres.
     */
    static void initialiser();

public:
    
    /**
     * Accesseur.
     *
     * @return la valeur de @ref titreVue_.
     */
    static const Glib::ustring lireTitreVue();
    
    /**
     * Accesseur.
     *
     * @return la valeur de @ref titreGrenouilloland_.
     */
    static const Glib::ustring lireTitreGrenouilloland();
    
    /**
     * Accesseur.
     *
     * @return la valeur de @ref titreDimension_.
     */
    static const Glib::ustring lireTitreDimension();
    
public:
    /**
     * Retourne l'image dont le nom est fourni en argument.
     *
     * @param[in] nom - le nom de l'image.
     * @return l'image correspondante.
     */
    static const Glib::RefPtr< Gdk::Pixbuf>& lireImage(const Glib::ustring& nom);

public:
    
    /**
     * Constructeur logique.
     *
     * @param[in] presentateur - la valeur de @ref presentateur_.
     */
    Vue(Presentateur& presentateur);
    
    /**
     * Constructeur par recopie.
     *
     * @param[in] autre - l'instance à recopier.
     */
    Vue(const Vue& autre) = delete;

public:
    
    /**
     * Accesseur.
     *
     * @return la valeur de @ref presentateur_.
     */
    const Presentateur& lirePresentateur() const;
    
    /**
     * Accesseur.
     *
     * @return la valeur de @ref presentateur_.
     */
    Presentateur& lirePresentateurModifiable();
    
    void mettreAJour();
    
    void mettreAJourPtsVie();
    
    void partiePerdue();
    
    void partieGagnee();
    
    void partieTerminee();
    
    void avanceChrono(const int& temps); 

public:
    
    /**
     * Opérateur d'affectation.
     *
     * @param[in] autre - l'instance à recopier.
     * @return cette instance après recopie.
     */
    Vue& operator=(const Vue& autre) = delete;
    
protected:
    
    /**
     * Construit les barre de menus et d'outils.
     *
     * @param[in,out] gestionnaire - le gestionnaire de mise en forme associé à
     *   la fenêtre principale.
     */
    void construireBarreMenusEtOutils(Gtk::VBox& gestionnaire);
    
    /**
     * Construit la partie centrale de la fenêtre principale qui contient un jeu
     * de la grenouille.
     *
     * @param[in,out] gestionnaire - le gestionnaire de mise en forme associé à
     *   la fenêtre principale.
     */
    void construirePartieCentrale(Gtk::VBox& gestionnaire);
    
    /**
     * Construit la partie inférieure de la fenêtre principale qui contient le
     * contrôleur de dimension du jeu de la grenouille.
     *
     * @param[in,out] gestionnaire - le gestionnaire de mise en forme associé à
     *   la fenêtre principale.
     */
    void construirePartieInferieure(Gtk::VBox& gestionnaire);
    
protected:
    
    /**
	 * Callback permettant de préparer le jeu grenouilloland pour une nouvelle 
	 * partie. 
	 *
	 * @note Cette méthode est invoquée suite à un click sur l'entrée "Nouveau" du
	 * menu "Commandes" ou bien sur le bouton correspondant dans la barre 
	 * d'outils.
	 */
	void cbNouveau();
    
    /**
     * Callback permettant de changer la résolution du jeu de la grenouille.
     *
     * @note Cette méthode est invoquée par le contrôleur de la résolution du jeu
     *   de la grenouille.
     */
    void cbChangerModele();
    
    /**
     * Callback permettant de présenter l'application et ses auteurs.
     *
     * @note Cette méthode est invoquée suite à un click sur l'entrée
     *   "A propos ..." du menu "Commandes" ou bien sur le bouton correspondant
     *   dans la barre d'outils.
     */
    void cbAPropos();
    
    /**
     * Callback permettant de quitter proprement l'application.
     *
     * @note Cette méthode est invoquée suite à un click sur l'entrée "Quitter" du
     *   menu "Commandes" ou bien sur le bouton correspondant dans la barre
     *   d'outils.
     */
    void cbQuitter();
    
    

protected:
    
    /**
     * Titre de cette vue.
     */
    static const Glib::ustring titreVue_;
    
    /**
     * Titre du jeu de la grenouille graphique.
     */
    static const Glib::ustring titreGrenouilloland_;
    
    /**
     * Titre du contrôleur de la dimension du jeu de la grenouille.
     */
    static const Glib::ustring titreDimension_;
    
    /**
     * Titre du contrôleur du chronometre du jeu de la grenouille.
     */
    static const Glib::ustring titreChronometre_;
    
    /**
     * Titre du contrôleur du chronometre du jeu de la grenouille.
     */
    static const Glib::ustring titrePtsVie_;
    
    /**
     * Chemins d'accès au répertoire contenant les images.
     */
    static const Glib::ustring cheminImages_;
    
    /**
     * Map permettant de stocker les images manipulées par cette vue.
     */
    static std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > images_;
    
protected:
    
    /**
     * Présentateur associé à cette vue.
     */
    Presentateur& presentateur_;
    
    /**
     * Jeu de la grenouille graphique de cette vue.
     */
    std::unique_ptr< GrenouillolandGraphique > ptrGrenouillolandGraphique_;
    
    /**
     * Contrôleur de la dimension du jeu de la grenouille de cette vue.
     */
    Dimension dimension_;
    
    /**
     * Controleur du chronometre du jeu de la grenouille de cette vue.
     */
    Chronometre chronometre_;
    
    PtsVie ptsVie_;
        
    /**
     * Gestionnaire de mise en forme associé à la partie centrale de la
     * fenêtre principale. Cette partie contient le jeu de la grenouille graphique qui
     * change avec le modèle. C'est pour cette raison que nous la définissons en
     * tant qu'attribut de cette vue.
     */
    Gtk::HBox gestionnaireCentre_;
};

#endif
