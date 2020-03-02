/**
 * @mainpage 
 *
 * L'application du jeu de la grenouille.
 *
 * @author David CONDAMINET - 21306226@etu.unicaen.fr
 * @author Pierre BERNARD - 21301373@etu.unicaen.fr
 * @author Marwan LAKRADI - 21301054@etu.unicaen.fr
 * @date 14.11.2016
 */
 
#include <cstdlib>

#include "Presentateur.hpp"


/**
 * Programme principal.
 *
 * @param[in] argc - le nombre d'arguments de la ligne de commande.
 * @param[in] argv - les arguments de la ligne de commandes.
 * @return @c EXIT_FAILURE en cas d'exécution réussie o @c EXIT_FAILURE sinon.
 */
int
main(int argc, char* argv[]) {

  // La ligne de commandes est vide : l'utilisateur demande de l'aide.
  if (argc == 1) {
    std::cout << "Usage: "
	      << argv[0]
	      << "dimension_min dimension_max dimension_initiale"
	      << std::endl;
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments de la ligne de commandes est différent de quatre :
  // l'utilisateur fait n'importe quoi.
  if (argc != 4) {
    std::cerr << "Nombre d'arguments incorrect." << std::endl;
    return EXIT_FAILURE;
  }

  // Tentative d'extraction de la résolution minimum.
  int minimum;
  {
    std::istringstream entree(argv[1]);
    entree >> minimum;
    if (! entree || ! entree.eof() || minimum < 2) {
      std::cerr << "La résolution minimum doit être un entier supérieur ou égal à 2."
		<< std::endl;
      return EXIT_FAILURE;
    }
  }

  // Tentative d'extraction de la résolution maximum.
  int maximum;
  {
    std::istringstream entree(argv[2]);
    entree >> maximum;
    if (! entree || ! entree.eof() || maximum < minimum) {
      std::cerr << "La résolution maximum n'est pas un entier supérieur à "
		<< minimum
		<< "."
		<< std::endl;
      return EXIT_FAILURE;
    }    
  }

  // Tentative d'extraction de la résolution initiale.
  int initiale;
  {
    std::istringstream entree(argv[3]);
    entree >> initiale;
    if (! entree || ! entree.eof() || initiale < minimum || 
        initiale > maximum) {
      std::cerr << "La résolution initiale n'est pas un entier dans ["
		<< minimum
		<< ", "
		<< maximum
		<< "]."
		<< std::endl;
      return EXIT_FAILURE;
    }  
  }


  // Tout est ok : initialisation de Gtk. 
  Gtk::Main foo(argc, argv);

  // Initialisation de la classe Vue.
  Vue::initialiser();

  // Instanciation et démarrage du présentateur.
  Presentateur presentateur(minimum, maximum, initiale);
  presentateur.commencer();

  // Tout s'est bien passé.
  return EXIT_SUCCESS;
}
