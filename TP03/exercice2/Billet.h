#ifndef BILLET_H
#define BILLET_H

#include <iostream>
#include <iomanip>

#include "Trajet.h"
#include "Tarif.h"

class Billet {
public:
    Billet(const Trajet & unTrajet, const Tarif & unTarif);
    virtual const Trajet & getTrajet() const;
    virtual const Tarif & getTarif() const;
    virtual const float getPrix() const;

    friend std::ostream &operator<<(std::ostream &sortie, const Billet & unBillet);
private:
    // Agrégation 1..1
    const Trajet & m_trajet;
    const Tarif & m_tarif;
};
#endif