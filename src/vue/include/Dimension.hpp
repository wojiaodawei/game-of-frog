#ifndef Dimension_hpp
#define Dimension_hpp

#include <gtkmm/frame.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/spinbutton.h>

// Déclaration incomplète de la classe Vue.
class Vue;

/**
 * @class Dimension Dimension.hpp
 *
 * Déclaration de la classe Dimension représentant un contrôleur de la dimension
 * du jeu de la vie. Le Widget utilisé est une barre de défilement.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 * @note Chaque instance de cette classe est son propre listener.
 */
class Dimension: public Gtk::Frame {
public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   * @param[in,out] vue - la valeur de @ref ptrVue_.
   */
  Dimension(const Glib::ustring& titre, Vue& vue);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance à recopier.
   */
  Dimension(const Dimension& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur pointée par @ref _ptrVue.
   */
  const Vue& lireVue() const;

public:

	/**
	 * Retourne la dimension actuelle.
	 *
	 * @return la dimension actuelle.
	 */
	int lireValeur() const;

protected:

	/**
	 * Callback associé au changement de valeur.
	 */
	void cbChangementDeValeur();

public:

	/**
	 * Opérateur d'affectation.
	 *
	 * @param[in] autre - l'instance à recopier.
	 * @return cette instance après recopie.
	 */
	Dimension& operator=(const Dimension& autre) = delete;

protected:

	/**
	 * Unique vue propriétaire de ce controleur.
	 */
	Vue* const ptrVue_;

	/**
	 * Barre de défilement.
	 */
	Gtk::SpinButton boutonDefilement_;

};

#endif
