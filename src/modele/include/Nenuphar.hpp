#ifndef Nenuphar_hpp
#define Nenuphar_hpp

#include "EltSurfaceVieillissant.hpp"

/**
 * @class Nenuphar Nenuphar.hpp
 *
 * Déclaration de la classe Nenuphar 
 * représentant un element de surface de type Nenuphar.
 *
 */
class Nenuphar : public EltSurfaceVieillissant {
public:

	/**
	 * Retourne Nenuphar.
	 *
	 * @return "Nenuphar".
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
