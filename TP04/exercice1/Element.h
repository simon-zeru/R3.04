#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <iostream>
#include "Usager.h"

class Element {
private:
    std::string m_nom; // Chaque élément du système de fichiers a un nom
    unsigned int m_taille;
    std::string m_dateModif;
    Usager m_proprietaire;
public:
    Element(const std::string & nom, const std::string & date, const unsigned int taille, const Usager & proprietaire): m_nom(nom), m_taille(taille), m_dateModif(date),
                                                                                                                        m_proprietaire(proprietaire){}
    const std::string & getNom() const {return this->m_nom;} // virtual inutile
    virtual void afficher() const {
// Les opérations communes sont visibles dans le composant
// Si possible, on factorise déjà ici le code commun à tous les éléments
        std::cout << "Nom : " << this->getNom() << std::endl;
        std::cout << "Taille : " << this->getTaille() << std::endl;
        std::cout << "Date de modification : " << this->getDateModification() << std::endl;
        std::cout << this->getProprietaire() << std::endl;
    }
    virtual void ajouter (Element * element);
// Les opérations propres aux non-terminaux doivent aussi être visibles ici// Mais on ne les implémente réellement que dans les non-terminaux
    virtual ~Element() {}
    const Usager & getProprietaire() const {return this->m_proprietaire;}
    void setProprietaire(const Usager & proprietaire);
    unsigned int getTaille() const {return this->m_taille;}
    const std::string & getDateModification() const {return this->m_dateModif;}
    void setDateModification (const std::string & date);

};

#endif /* ELEMENT_H */

