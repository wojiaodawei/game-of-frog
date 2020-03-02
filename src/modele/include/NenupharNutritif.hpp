#ifndef NenupharNutritif_hpp
#define NenupharNutritif_hpp

#include "EltSurfaceVieillissant.hpp"

/**
 * @class NenupharNutritif NenupharNutritif.hpp
 *
 * Déclaration de la classe NenupharNutritif 
 * représentant un element de surface de type NenupharNutritif.
 *
 */
class NenupharNutritif : public EltSurfaceVieillissant {
public:

	/**
	 * Retourne NenupharNutritif.
	 *
	 * @return "NenupharNutritif".
	 */
	std::string lireNom() const override;
	
	/**
     * Augmente les points de vie la grenouille de une unité
     * et la guérrit si elle est malade.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    void appliquerEffet(Grenouille& grenouille) const override;
};

#endif
