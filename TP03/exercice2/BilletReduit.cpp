#include <iostream>
#include "BilletReduit.h"
using namespace std;

// A COMPLETER

ostream & operator<<(ostream & sortie, const BilletReduit & unBilletR) {
    const Trajet & traj = unBilletR.getTrajet();

    cout << "Billet Réduit : \n";
    cout << "Départ : " << traj.getVilleDepart() << "\n";
    cout << "Arrivée : " << traj.getVilleArrivee() << "\n";
    cout << "Prix : " << unBilletR.getPrix() << endl;

    sortie << "\n";

    return sortie;
}
