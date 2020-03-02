#ifndef CaseGraphique_hpp
#define CaseGraphique_hpp

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <map>
#include <memory>
#include <string>


// Déclarations incomplètes des classes Presentateur et GrenouillolandGraphique.
class Presentateur;
class GrenouillolandGraphique;



/**
 * @class CaseGraphique CaseGraphique.hpp 
 *
 * Déclaration de la classe CaseGraphique représentant graphiquement une
 * case du modèle.
 *
 * @note Chaque instance de cette classe est son propre listener.
 */
class CaseGraphique: public Gtk::EventBox {
public:

	// Déclaration d'amitié envers la classe GrenouillolandGraphique.
	friend class GrenouillolandGraphique;
	// Renommage de type local.
	typedef std::unique_ptr< Gtk::Image > Pointer;
public:

	/**
	 * Constructeur logique.
    	 * 
	 * @param[in,out] grenouilloland - la valeur de @ref grenouillolandGraphique_.
	 * @param[in] ligne - la valeur de @ref ligne_.
	 * @param[in] colonne - la valeur de @ref colonne_.
	 */
	CaseGraphique(GrenouillolandGraphique& grenouillolandGraphique,
		const int& ligne,
		const int& colonne);

	/**
	 * Constructeur par recopie.
	 *
	 * @param[in] autre - l'instance a recopier.
	 */
	CaseGraphique(const CaseGraphique& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref grenouillolandGraphique_.
   */
  const GrenouillolandGraphique& lireGrenouillolandGraphique() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref ligne_.
   */
  const int& lireLigne() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref colonne_.
   */
  const int& lireColonne() const;

protected:

  /**
   * Demande à cette case graphique de se mettre à jour en fonction de l'état
   * de la case correspondante du modèle.
   * 
   * @param[in] presentateur - le présentateur à invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

  /**
   * Callback invoqué lors d'un click de souris sur cette case graphique.
   *
   * @param[in] evt - l'événement associé au click.
   * @return la valeur @c true.
   */
  bool cbClickSouris(GdkEventButton* evt);
  

protected:

  /**
   * Représentation graphique de grenouilloland propriétaire de cette case 
   * graphique.
   */
  GrenouillolandGraphique& grenouillolandGraphique_;
  
  /**
   * Numéro de ligne de cette cellule dans le modèle.
   */
  const int ligne_;

  /**
   * Numéro de colonne de cette cellule dans le modèle.
   */
  const int colonne_;

  /**
   * Pixmaps représentant tous les états possibles d'une case en fonction de leur age.
   *
   */
  std::map< std::string, Pointer[3] > etats_;
  

};

#endif
