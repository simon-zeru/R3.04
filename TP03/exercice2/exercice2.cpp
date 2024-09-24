#include <iostream>
#include <string>
#include <stdexcept>
#include "Conteneur.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Promotion.h"
#include "Billet.h"
#include "BilletReduit.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Billet *newBillet(Conteneur<Trajet> &trajets, Conteneur<Tarif> &tarifs, Conteneur<Promotion> &promotions) {
    // Sélection du trajet
    cout << "Sélectionnez un trajet : " << endl;
    trajets.afficher();
    Trajet &trajetChoisi = trajets.choisir();

    // Sélection du tarif
    cout << "Sélectionnez un tarif : " << endl;
    tarifs.afficher();
    Tarif &tarifChoisi = tarifs.choisir();

    // Demande pour la promotion
    char avecPromo;
    cout << "Souhaitez-vous appliquer une promotion ? (y/n) : ";
    cin >> avecPromo;

    if (avecPromo == 'y' || avecPromo == 'Y') {
        // Sélection de la promotion
        cout << "Sélectionnez une promotion : " << endl;
        promotions.afficher();
        Promotion &promoChoisie = promotions.choisir();

        // Retourner un billet réduit
        return new BilletReduit(trajetChoisi, tarifChoisi, promoChoisie);
    }

    // Retourner un billet normal
    return new Billet(trajetChoisi, tarifChoisi);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    // Création des conteneurs de Trajets, TArifs, Promotions
    Conteneur<Trajet> trajets;
    trajets.ajouter(new Trajet("Grenoble", "Lyon", 100));
    trajets.ajouter(new Trajet("Grenoble", "Paris", 600));
    trajets.ajouter(new Trajet("Grenoble", "Marseille", 300));
    Conteneur<Tarif> tarifs;
    tarifs.ajouter(new Tarif("Normal", 2.00));
    tarifs.ajouter(new Tarif("Jeune", 1.00));
    tarifs.ajouter(new Tarif("Vermeil", 3.00));
    Conteneur<Promotion> promotions;
    promotions.ajouter(new Promotion("Noël", 0.5));
    promotions.ajouter(new Promotion("Anniversaire", 0.2));

    // Création d'un billet à partir des choix de l'utilisateur
    Billet *billet = newBillet(trajets, tarifs, promotions);

    // Affichage du billet créé
    cout << *billet;

    // Libération de la mémoire
    delete billet;

    return 0;
}

