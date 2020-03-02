# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin du répertoire contenant les binaires.
SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Modules nécessaires.
FIND_PACKAGE( PkgConfig REQUIRED )
PKG_CHECK_MODULES( GTKMM gtkmm-3.0 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/modele/include 
					 src/presentateur/include
					 src/vue/include
					 ${GTKMM_INCLUDE_DIRS}
)

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Librairies nécessaires à l'édition de liens.
LINK_DIRECTORIES( ${GTKMM_LIBRARY_DIRS} )

# Création des exécutables.
ADD_EXECUTABLE( jeudelagrenouille
		src/client/jeudelagrenouille.cpp
		src/presentateur/Presentateur.cpp
		src/modele/Case.cpp
		src/modele/Eau.cpp
		src/modele/EltSurfaceImmortel.cpp
		src/modele/EltSurfaceVieillissant.cpp
		src/modele/Grenouille.cpp
		src/modele/Jeu.cpp
		src/modele/Nenuphar.cpp
		src/modele/NenupharArrive.cpp
		src/modele/NenupharDepart.cpp
		src/modele/NenupharDopant.cpp
		src/modele/NenupharMortel.cpp
		src/modele/NenupharNutritif.cpp
		src/modele/NenupharVeneneux.cpp
		src/vue/Vue.cpp
		src/vue/Dimension.cpp
		src/vue/CaseGraphique.cpp
		src/vue/GrenouillolandGraphique.cpp
		src/vue/Chronometre.cpp
		src/vue/PtsVie.cpp
)

TARGET_LINK_LIBRARIES( jeudelagrenouille ${GTKMM_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

