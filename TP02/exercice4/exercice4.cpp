#include "Conteneur.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main(int argc, char** argv) {

    // A COMPLETER : tester le template Conteneur<T>
    Conteneur<string> c1;

    // Si des arguments sont passés, on les ajoute au conteneur
    for (int i = 1; i < argc; ++i) {
        c1.ajouter(new string(argv[i]));  // Ajouter chaque argument au conteneur
    }

    // Afficher les éléments ajoutés depuis les arguments
    c1.afficher();

    // Copier le conteneur
    Conteneur<string> c2 = c1;
    cout << "Conteneur copié :" << endl;
    c2.afficher();

    // Demander à l'utilisateur de choisir un index
    cout << "Choisissez un index (entre 0 et " << argc - 2 << ") : ";
    int index;
    cin >> index;

    if (index >= 0 && index < argc - 1) {
        cout << "Vous avez choisi: " << *c1.contenu.at(index) << endl;
    } else {
        cout << "Index invalide!" << endl;
    }

    return 0;;
}