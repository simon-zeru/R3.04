#include <iostream>
#include "Billet.h"
using namespace std;

Billet::Billet(const Trajet &unTrajet, const Tarif &unTarif): m_trajet(unTrajet), m_tarif(unTarif) {};

const Trajet &Billet::getTrajet() const {
    return m_trajet;
}

const Tarif &Billet::getTarif() const {
    return m_tarif;
}

const float Billet::getPrix() const {
    return m_tarif.getPrixAuKm() * m_trajet.getDistance();
}

ostream &operator<<(ostream & sortie, const Billet & unBillet) {
    const Trajet & traj = unBillet.getTrajet();

    cout << "Billet : \n";
    cout << "Départ : " << traj.getVilleDepart() << "\n";
    cout << "Arrivée : " << traj.getVilleArrivee() << "\n";
    cout << "Prix : " << unBillet.getPrix() << endl;

    sortie << "\n";

    return sortie;
}