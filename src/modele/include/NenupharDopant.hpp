#ifndef NenupharDopant_hpp
#define NenupharDopant_hpp

#include "EltSurfaceVieillissant.hpp"

/**
 * @class NenupharDopant NenupharDopant.hpp
 *
 * Déclaration de la classe NenupharDopant 
 * représentant un element de surface de type NenupharDopant.
 *
 */
class NenupharDopant : public EltSurfaceVieillissant {
public:

	/**
	 * Retourne NenupharDopant.
	 *
	 * @return "NenupharDopant".
	 */
	std::string lireNom() const override;
	
	/**
     * Double les points de vie de la grenouille
 	 * et la guérrit si elle est malade.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    void appliquerEffet(Grenouille& grenouille) const override;
};

#endif
