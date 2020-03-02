#ifndef EltSurface_hpp
#define EltSurface_hpp

#include <string>

#include "Grenouille.hpp"

/**
 * @class EltSurface EltSurface.hpp
 *
 * Déclaration de la classe interface EltSurface 
 * représentant un element de surface.
 *
 * @note Cette classe implémente le comportemental design pattern Strategy.
 */
class EltSurface {
public:

	/**
	 * Destructeur redéfinissable.
	 */
	virtual ~EltSurface() = default;
  
public:

	/**
	 * Retourne le nom de l'EltSurface.
	 *
	 * @return le nom de l'EltSurface.
	 */
	virtual std::string lireNom() const = 0;
  
	/**
     * Applique l'effet de l'élément sur lequel est positionné la grenouille.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    virtual void appliquerEffet(Grenouille& grenouille) const = 0;

    /**
     * Accesseur.
     *
     * @return @c true si cet élément est vieillissant, @c false sinon.
     */
    virtual bool estVieillissante() const = 0;
};


#endif
