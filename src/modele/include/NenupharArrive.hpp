#ifndef NenupharArrive_hpp
#define NenupharArrive_hpp

#include "EltSurfaceImmortel.hpp"

/**
 * @class NenupharArrive NenupharArrive.hpp
 *
 * Déclaration de la classe NenupharArrive 
 * représentant le nénuphar d'arrivé de la grenouille.
 *
 */
class NenupharArrive : public EltSurfaceImmortel {
public:

	/**
	 * Retourne NenupharArrive.
	 *
	 * @return "NenupharArrive".
	 */
	std::string lireNom() const override;
	
	/**
     * Rend la grenouille victorieuse, appel la méthode de victoire
     * de la grenouille.
     *
     * @param[in] grenouille - la grenouille à qui on applique l'effet.
     */
    void appliquerEffet(Grenouille& grenouille) const override;
};

#endif
