#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H

#include "Billet.h"
#include "Promotion.h"

class BilletReduit : public Billet {
public:
    BilletReduit(const Trajet & unTrajet, const Tarif & unTarif, const Promotion & unePromo):
        Billet(unTrajet, unTarif), m_promotion(unePromo){};

    inline const float getPrix() const override {
        return m_promotion.calculePrixReduit(this->getTrajet().getDistance() * this->getTarif().getPrixAuKm());
    }

    friend std::ostream & operator<<(std::ostream & sortie, const BilletReduit & unBilletR);

protected:
    const Promotion & m_promotion;

};
#endif