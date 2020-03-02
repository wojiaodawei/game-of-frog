#ifndef NenupharVeneneux_hpp
#define NenupharVeneneux_hpp

#include "EltSurfaceVieillissant.hpp"

/**
 * @class NenupharVeneneux NenupharVeneneux.hpp
 *
 * Déclaration de la classe NenupharVeneneux 
 * représentant un element de surface de type NenupharVeneneux.
 *
 */
class NenupharVeneneux : public EltSurfaceVieillissant {
public:

	/**
	 * Retourne NenupharVeneneux.
	 *
	 * @return "NenupharVeneneux".
	 */
	std::string lireNom() const override;
	
	/**
     * Rend la grenouille malade et divise par deux le nombre
     * de ses points de vie.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    void appliquerEffet(Grenouille& grenouille) const override;

};

#endif
