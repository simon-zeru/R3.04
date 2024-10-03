#ifndef FICHIER_H
#define FICHIER_H
#include "Element.h"

class Fichier : public Element { // C'est une classe « feuille »
private:
    std::string m_dateCreation;
public:
    Fichier(const std::string & nom,
    const std::string & dateCreation)
    : Element(nom),
    m_dateCreation(dateCreation)
    {}
    void afficher() const override {
        std::cout << "Fichier : ";
        this->Element::afficher(); // réutilise l’op. afficher d’Element
        std::cout << "Date creation : "
        << m_dateCreation << std::endl;
    }
    void ajouter (Element * element) override {
        throw "Opération Interdite sur un Fichier";
    }
    virtual ~Fichier() {}
};

#endif /* FICHIER_H */

