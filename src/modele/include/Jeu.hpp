#ifndef Jeu_hpp
#define Jeu_hpp

#include <vector>
#include <stdlib.h>
#include <memory>
#include <map>
#include <string>
#include <memory>

#include "NenupharDepart.hpp"
#include "NenupharArrive.hpp"
#include "NenupharDopant.hpp"
#include "NenupharNutritif.hpp"
#include "Nenuphar.hpp"
#include "NenupharVeneneux.hpp"
#include "NenupharMortel.hpp"
#include "Eau.hpp"
#include "Case.hpp"
#include "Grenouille.hpp"
#include "EltSurface.hpp"

/**
 * @class Jeu Jeu.hpp
 *
 * Déclaration de la classe Jeu représentant la grille du jeu ainsi que l'interface entre le modele et l'exterieur.
 */

class Jeu{
protected:
	
	typedef std::unique_ptr< EltSurface > PtrStrategie;
	
	typedef std::map< std::string, PtrStrategie > BaseStrategies;
	
public:
	/**
	 * Constructeur logique.
	 *
	 * @param[in] dimension - la valeur de @ref dimension la taille de la grille.
	 */
	Jeu(const int& dimension);
	
	/**
	 * Applique le vieillissement à toutes les cases de la grille.
	 */
	void appliquerVieillissement() const;
	
	/**
	 * Deplace la grenouille si possible.
	 *
	 * @param[in] x - la valeur du numéro de ligne du déplacement.
	 * @param[in] y - la valeur du numéro de colonne du déplacement.
	 * @return vrai si le déplacement est valide, faux sinon.
	 */
	bool deplacer(const int& x,const int& y) const;
	
	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref dimension_.
	 */
	const int& lireDimension() const;
	
	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref grenouille_.
	 */
	const Grenouille& lireGrenouille() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref cases.
	 */
	const std::vector<std::vector<Case*> > lireCases() const;

	/**
	 * Reinitialise le modèle.
	 *
	 * @param[in] dimension - la valeur de @ref dimension_ la taille de la grille.
	 */
	void reinitialise(const int& dimension);

protected:

	/**
	 * Ajoute un nénuphar aléatoire si la case est de l'eau.
	 *
 	 * @param[in] x - la valeur du numéro de ligne.
	 * @param[in] y - la valeur du numéro de colonne.
	 */
	void ajoutNenuphar(const int& x,const int& y) const;
    
	/**
	 * Ajoute un chemin de nenuphar des coordonnées d'entrées jusqu'à l'arrivée.
	 *
 	 * @param[in] x - la valeur du numéro de ligne.
	 * @param[in] y - la valeur du numéro de colonne.
	 */
	void tracerLigneNenuphar(const int& x,const int& y) const;
    
protected:

	/**
	 * Taille de la grille.
	 */
	int dimension_;
	
	/**
	 * Pointeur vers Grenouille.
	 */
	Grenouille* grenouille_;
	
	/**
	 * Map contenant toutes les strategies.
	 */
	BaseStrategies base;
	
	/**
	 * Vector de pointeur vers les cases de la grille.
	 */
	std::vector<std::vector<Case*> > cases;
};
#endif
