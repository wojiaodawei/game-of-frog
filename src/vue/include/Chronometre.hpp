#ifndef Chronometre_hpp
#define Chronometre_hpp

#include <gtkmm/frame.h>
#include <gtkmm/progressbar.h>


// Déclaration incomplète de la classe Vue.
class Vue;

/**
 * @class Chronometre Chronometre.hpp
 *
 * Déclaration de la classe Chronometre représentant un contrôleur de la barre
 * de progression du timer.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class Chronometre: public Gtk::Frame {
public:

	/**
	 * Constructeur logique.
	 *
	 * @param[in] titre - le titre du contour.
	 * @param[in,out] vue - la valeur de @ref ptrVue_.
	 */
	Chronometre(const Glib::ustring& titre, Vue& vue);

	/**
	 * Constructeur par recopie.
	 *
	 * @param[in] autre - l'instance à recopier.
	 */
	Chronometre(const Chronometre& autre) = delete;

public:

	/**
	 * Accesseur.
	 *
	 * @return la valeur pointée par @ref _ptrVue.
	 */
	const Vue& lireVue() const;

	void changerTemps(const int& temps);
	
public:

	/**
	 * Opérateur d'affectation.
	 *
	 * @param[in] autre - l'instance à recopier.
	 * @return cette instance après recopie.
 	 */
	Chronometre& operator=(const Chronometre& autre) = delete;

protected:

	/**
	 * Unique vue propriétaire de ce controleur.
	 */
	Vue* const ptrVue_;

	/**
	 * Barre de progression.
	 */
	Gtk::ProgressBar chronometre_;

};

#endif
