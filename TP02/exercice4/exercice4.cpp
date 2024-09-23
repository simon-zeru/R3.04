#include "Conteneur.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {

    // Tester le template Conteneur<T>
    Conteneur<string> c1;

    // Demander à l'utilisateur d'entrer des chaînes de caractères
    int n;
    cout << "Combien de chaînes de caractères voulez-vous ajouter ? ";
    cin >> n;
    cin.ignore();  // Pour ignorer le retour à la ligne laissé dans le buffer

    for (int i = 0; i < n; ++i) {
        cout << "Entrez la chaîne #" << i + 1 << ": ";
        string* arg = new string();
        getline(cin, *arg);  // Lire la chaîne de caractères entrée par l'utilisateur
        c1.ajouter(arg);
    }

    // Afficher les éléments ajoutés par l'utilisateur
    c1.afficher();

    // Copier le conteneur
    Conteneur<string> c2 = c1;
    cout << "Conteneur copié :" << endl;
    c2.afficher();

    return 0;
}
