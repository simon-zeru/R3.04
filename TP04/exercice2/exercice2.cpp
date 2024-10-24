#include "Parametres.h"

int main() {
    // Afficher les paramètres initiaux
    Parametres & parametres = Parametres::getInstance();
    parametres.afficher();
    // Instancier un thème intitulé "Urbain" et l'associer aux paramètres
    parametres.setTheme(Theme("Urbain"));
    // Instancier un joueur nommé "Yoloutre" et l'associer aux paramètres
    Joueur unJoueur("Yoloutre");
    parametres.setJoueur(unJoueur);
    // Afficher les nouveaux paramètres
    parametres.afficher();
    return 0;
}

/////// TRACE ATTENDUE //////////////////////////////////
//
// Paramètres { Theme: 'Par Défaut', Joueur: 'Anonyme' }
// Paramètres { Theme: 'Urbain', Joueur: 'Yoloutre' }
//
/////////////////////////////////////////////////////////