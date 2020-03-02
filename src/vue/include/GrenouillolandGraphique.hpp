#ifndef GrenouillolandGraphique_hpp
#define GrenouillolandGraphique_hpp

#include "CaseGraphique.hpp"

#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>
#include <vector>

// Déclaration incomplète de la classe Vue.
class Vue;

/**
 * @class GrenouillolandGraphique GrenouillolandGraphique.hpp
 *
 * Déclaration de la classe GrenouillolandGraphique représentant une génération
 * de cases graphiques.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class GrenouillolandGraphique: public Gtk::AspectFrame {
public:

  // Déclarations d'amitié envers les classes Vue et CaseGraphique.
  friend class Vue;
  friend class CaseGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   * @param[in,out] vue - la valeur de @ref vue_.
   */
  GrenouillolandGraphique(const Glib::ustring& titre, Vue& vue);

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref vue_.
   */
  const Vue& lireVue() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref vue_.
   */
  Vue& lireVueModifiable();

  /**
   * Met à jour la case graphique de position (x, y) de ce jeu de la grenouille 
   * graphique.
   *
   * @param[in] x - le numéro de ligne.
   * @param[in] y - le numéro de colonne.
   */
	void mettreAJourCase(const Presentateur& presentateur, const int& x, const int& y);

protected:

  /**
   * Met à jour l'ensemble des cases graphiques de ce jeu de la grenouille 
   * graphique.
   *
   * @param[in] presentateur - le présentateur a invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);


protected:

  /**
   * Vue propriétaire de ce jeu de la vie graphique.
   */
  Vue& vue_;

  /**
   * Gestionnaire de mise en forme de ce jeu graphique.
   */
  Gtk::Grid gestionnaire_;

  /**
   * Cellules graphiques de ce jeu de la vie graphique.
   */
  std::vector< CaseGraphique* > cases_;

};

#endif
