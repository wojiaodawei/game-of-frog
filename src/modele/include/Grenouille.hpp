#ifndef Grenouille_hpp
#define Grenouille_hpp

/**
 * @class Grenouille Grenouille.hpp
 *
 * Déclaration de la classe Grenouille représentant une entité Grenouille dans la grille du jeu
 */
class Grenouille{
public:

	/**
	 * Constructeur logique.
	 *
	 * @param[in] x - la valeur de @ref x_ son numéro de ligne.
	 * @param[in] y - la valeur de @ref y_ son numéro de colonne.
	 */
	Grenouille(const int& x, const int& y);

public:

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref ptsVie_.
	 */
	const int& lirePtsVie() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref x_.
	 */
	const int& lireX() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref y_.
	 */
	const int& lireY() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref ancienX_.
	 */
	const int& lireAncienX() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref ancienY_.
	 */
	const int& lireAncienY() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref vivante_.
	 */
	const bool& estVivante() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref malade_.
	 */
	const bool& estMalade() const;

	/**
	 * Accesseur.
	 *
	 * @return la valeur de @ref gagnant_.
	 */
	const bool& estVictorieux() const;
	
	/**
	 * Modifie les points de vie de la grenouille.
	 *
	 * @param[in] points - le nombre de points à ajouter à @ref ptsVie_.
	 */	
	void modifierPtsVie(const int& points);

	/**
	 * Fait mourrir la grenouille, implique la fin du jeu.
	 */
	void mourrir();

	/**
	 * Mutateur.
	 *
	 * @note Déplace la grenouille en les nouvelles coordonnées x et y.
	 * @param[in] x - la nouvelle valeur de @ref x_.
	 * @param[in] y - la nouvelle valeur de @ref y_.
	 */
	void deplacer(const int& x, const int& y);
	
	/**
	 * Rend malade la grenouille.
	 */
	void infecter();

	
	/**
	 * Guérit la grenouille.
	 */
	void guerir();
	
	/**
	 * Rend la grenouille victorieuse.
	 */
	void victoire();

protected:

	/**
	 * Numéro de ligne de l'ancienne position de la grenouille
	 */
	int ancienX_;

	/**
	 * Numéro de colonne de l'ancienne position de la grenouille
	 */
	int ancienY_;

	/**
	 * Numéro de ligne de la position de la grenouille
	 */
	int x_;

	/**
	 * Numéro de colonne de la position de la grenouille
	 */
	int y_;
	
	/**
	 * Nombre de points de vie de la grenouille.
	 */
	int ptsVie_;
	
	/**
	 * Etat malade ou non de la grenouille.
	 */
	bool malade_;
	
	/**
	 * Etat vivant ou mort de la grenouille.
	 */
	bool vivante_;

	/**
	 * Etat gagnant lorsque la grenouille atteindra le nénuphar arrivée.
	 */
	bool gagnant_;

	

	
};

#endif
