#ifndef EltSurfaceVieillissant_hpp
#define EltSurfaceVieillissant_hpp

#include "EltSurface.hpp"

/**
 * @class EltSurfaceVieillissant EltSurfaceVieillissant.hpp
 *
 * Déclaration de la classe EltSurfaceVieillissant 
 * représentant un element de surface vieillissant.
 */
class EltSurfaceVieillissant : public EltSurface {
public:

	/**
	 * Retourne le nom de l'EltSurfaceVieillissant.
	 *
	 * @return le nom de l'EltSurfaceVieillissant.
	 */
	virtual std::string lireNom() const override = 0;
	
	/**
     * Accesseur.
     *
     * @return la valeur de @c true.
     */
	bool estVieillissante() const override;

    /**
     * Applique l'effet de l'élément sur lequel est positionné la grenouille.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    virtual void appliquerEffet(Grenouille& grenouille) const override = 0;
};

#endif
