#ifndef PtsVie_hpp
#define PtsVie_hpp

#include <gtkmm/frame.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>


// Déclaration incomplète de la classe Vue.
class Vue;

/**
 * @class PtsVie PtsVie.hpp
 *
 * Déclaration de la classe PtsVie représentant le nombre de points de vie
 * de la grenouille.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class PtsVie: public Gtk::Frame {

public:

	/**
	 * Constructeur logique.
	 *
	 * @param[in] titre - le titre du contour.
	 * @param[in,out] vue - la valeur de @ref ptrVue_.
	*/
	PtsVie(const Glib::ustring& titre, Vue& vue);

	/**
	 * Constructeur par recopie.
	 *
	 * @param[in] autre - l'instance à recopier.
	 */
	PtsVie(const PtsVie& autre) = delete;

public:

	/**
	 * Accesseur.
	 *
	 * @return la valeur pointée par @ref _ptrVue.
	 */
	const Vue& lireVue() const;

public:
	/**
	 * Permet de mettre à jour l'affichage des points de vie
	 */
	void changerPtsVie();

public:

	/**
	 * Opérateur d'affectation.
	 *
	 * @param[in] autre - l'instance à recopier.
	 * @return cette instance après recopie.
	 */
	PtsVie& operator=(const PtsVie& autre) = delete;

protected:

	/**
	 * Unique vue propriétaire de ce controleur.
	 */
	Vue* const ptrVue_;

	/**
	 * Image du coeur.
	 */
	Gtk::Image ptsVie_;
	
	/**
	 * Label affichant les points de vie.
	 */
	Gtk::Label labelPtsVie_;
	
};

#endif
