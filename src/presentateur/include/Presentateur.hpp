#ifndef Presentateur_hpp
#define Presentateur_hpp

#include <string>
#include <iostream>
#include <array>
#include <glibmm/main.h>

#include "Jeu.hpp"
#include "Vue.hpp"

/**
 * @class Presentateur Presentateur.hpp
 *
 * Déclaration de la classe Presentateur
 */
 
class Presentateur{
	
public:
	/**
	 * Constructeur logique.
	 *
	 * @param[in] dimensionMin - la valeur de @ref dimensionMin_.
	 * @param[in] dimensionMax - la valeur de @ref dimensionMax_.
	 * @param[in] dimension - la valeur de @ref dimension_.
	 */
	 Presentateur(const int& dimensionMin, const int& dimensionMax, const int& dimension);
	 
public:
	
	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref dimensionMin_.
	 */
	const int& lireDimensionMin() const;
	
	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref dimensionMax_.
	 */
	const int& lireDimensionMax() const;
	
	/**
	 * Retourne la dimension du modèle associé à ce presentateur.
	 *
	 * @return la dimension du modèle associé à ce présentateur.
	 */
	const int& lireDimension() const;
    
    /**
     * Retourne le modèle associé à ce presentateur.
     *
     * @return la valeur pointée par @ref jeu_
     */
    const Jeu& lireJeu() const;

public:

	/**
	 * Renvoie le nom de l'élément surface en position (x, y).
	 */
	const std::string lireNomEltSurface(const int& x, const int& y) const;
	
	/**
	 * Renvoie l'age de la case en position (x, y).
	 */
	const int& lireAgeCase(const int& x, const int& y) const;
	
	/**
	 * Déplace la grenouille en position (x, y).
	 */
	void deplacerGrenouille(const int& x, const int& y);
	
	/**
	 * Teste si la grenouille est en case de position (x, y).
	 */
	bool grenouilleEn(const int& x, const int& y) const;
	
	/**
	 * Retourne l'ancienne position [x, y] de la grenouille.
	 */
	std::array<int, 2> grenouilleAnciennementEn() const;

	/**
	 * Teste si la grenouille est malade.
	 */
	bool grenouilleMalade() const;
	
	/**
	 * Réinitialise le jeu avec la nouvelle dimension.
	 */
	void reinitialiser(const int& nouvelle);
	
	/**
	 * Démarre la partie.
	 */
	void commencer();
	
private:

	/**
	 * Appelée toutes les secondes, cb du signal.
	 */
	bool tour();
	

public:

	/**
	* Opérateur d'affectation.
	*
	* @param[in] autre - l'instance à recopier.
	* @return cette instance après recopie.
	*/
	Presentateur& operator=(const Presentateur& autre) = delete;
	
protected:

	/**
	 * Dimension minimale de la grille de jeu.
	 */
	const int dimensionMin_;
	
	/**
	 * Dimension maximale de la grille de jeu.
	 */
	const int dimensionMax_;
	
	/**
	 * Pointeur vers le modele de notre application.
	 */
	Jeu* jeu;
	
	/**
	 * Pointeur vers la vue de notre application.
	 */
	Vue* vue;
	
	/**
	 * Temps écoulé de la partie en cours.
	 */
	int temps;
	/**
	 * Indique l'état de la partie.
	 */
	bool partieFinie;
};

#endif
