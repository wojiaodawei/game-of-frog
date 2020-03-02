#ifndef EltSurfaceImmortel_hpp
#define EltSurfaceImmortel_hpp

#include "EltSurface.hpp"

/**
 * @class EltSurfaceImmortel EltSurfaceImmortel.hpp
 *
 * Déclaration de la classe EltSurfaceImmortel 
 * représentant un element de surface ne pouvant pas vieillir.
 */
class EltSurfaceImmortel : public EltSurface {
public:

	/**
	 * Retourne le nom de l'EltSurfaceImmortel.
	 *
	 * @return le nom de l'EltSurfaceImmortel.
	 */
	virtual std::string lireNom() const override = 0;
	
	/**
	 * Accesseur.
	 *
	 * @return la valeur @c false.
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
