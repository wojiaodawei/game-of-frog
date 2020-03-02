#ifndef NenupharDepart_hpp
#define NenupharDepart_hpp

#include "EltSurfaceImmortel.hpp"

/**
 * @class NenupharDepart NenupharDepart.hpp
 *
 * Déclaration de la classe NenupharDepart 
 * représentant le nénuphar de départ de la grenouille.
 *
 */
class NenupharDepart : public EltSurfaceImmortel {
public:

	/**
	 * Retourne NenupharDepart.
	 *
	 * @return "NenupharDepart".
	 */
	std::string lireNom() const override;
	
	/**
     * N'a aucun effet sur la grenouille.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    void appliquerEffet(Grenouille& grenouille) const override;
};

#endif
