#ifndef Eau_hpp
#define Eau_hpp

#include "EltSurfaceImmortel.hpp"

/**
 * @class Eau Eau.hpp
 *
 * Déclaration de la classe Eau 
 * représentant un element de surface de type Eau.
 *
 */
class Eau : public EltSurfaceImmortel {
public:

	/**
	 * Retourne Eau.
	 *
	 * @return "Eau".
	 */
	std::string lireNom() const override;
	
	/**
     * Fait mourrir la grenouille.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    void appliquerEffet(Grenouille& grenouille) const override;
};

#endif
