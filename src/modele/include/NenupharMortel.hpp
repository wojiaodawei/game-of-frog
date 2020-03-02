#ifndef NenupharMortel_hpp
#define NenupharMortel_hpp

#include "EltSurfaceVieillissant.hpp"

/**
 * @class NenupharMortel NenupharMortel.hpp
 *
 * Déclaration de la classe NenupharMortel 
 * représentant un element de surface de type NenupharMortel.
 *
 */
class NenupharMortel : public EltSurfaceVieillissant {
public:

	/**
	 * Retourne NenupharMortel.
	 *
	 * @return "NenupharMortel".
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
