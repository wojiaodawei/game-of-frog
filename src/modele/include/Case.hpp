#ifndef Case_hpp
#define Case_hpp

#include "EltSurface.hpp"
#include "Eau.hpp"

/**
 * @class Case Case.hpp
 *
 * Déclaration de la classe Case représentant une Case de la grille du jeu des grenouilles
 *
 * @note Cette classe implémente le behavorial design pattern Strategy.
 */
class Case{
public: 

	/**
	 * Constructeur logique.
	 *
	 * @param[in] elt - la valeur pointée par @ref elementSurface_ son élément qui la compose.
	 */
	Case(const EltSurface& elt);

public:

	/**
	 * Accesseur.
	 *
	 * @return le nom de l'élément surface courant (stratégie courante) de la case.
	 */
	const std::string lireNom() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref age_.
	 */
	const int& lireAge() const;

	/**
	 * Mutateur.
	 *
	 * @param[in] elt - la nouvelle valeur de @ref elementSurface_.
	 */
	void changerEltSurface(const EltSurface& elt);
	    
public:

	/**
	 * Applique l'effet de l'élément surface composant la case sur la grenouille
	 */
	void appliquerEffet(Grenouille& grenouille) const;
	
	/**
	 * Vieillit la case si elle est vieillissante.
	 */
	void vieillir();

protected:

	/**
	 * Pointeur vers l'element surface courant de la case
	 */
	const EltSurface* elementSurface_;
	
	/**
	 * Pointeur vers l'element de base de la case (à sa naissance)
	 */
	const EltSurface* elementInitial_;
	
	/**
	 * Age courant de la case
	 */
	int age_;

};

#endif
