#include "Visage.h"
#include <iostream>
using namespace std;

// A COMPLETER : IMPLEMENTER LES METHODES DE LA CLASSE VISAGE (ET L'OPERATEUR <<)


Visage::Visage(int longueurNez, const Ethnie &uneEthnie): m_unNez(longueurNez), m_uneEthnie(uneEthnie), m_unChapeau(nullptr), m_uneMoustache(nullptr) {

}

void Visage::setMoustache(int largeur) {
    m_uneMoustache = new Moustache(largeur);
}

void Visage::addBouton(int diametre) {
    m_mesBoutons.push_back(diametre);
}

void Visage::setChapeau(const Chapeau &unChapeau) {
    m_unChapeau = new Chapeau(unChapeau);
}

void Visage::addBijou(const Bijou &unBijou) {
    const Bijou *bijou = new Bijou(unBijou);
    this->m_mesBijoux.push_back(bijou);
}

const Visage &Visage::operator=(const Visage &unVisage) {
    if (this != &unVisage) {
        this->empty();
        this->m_unNez = unVisage.m_unNez;

        if (unVisage.m_unChapeau != nullptr) {
            this->setChapeau(*unVisage.m_unChapeau);
        }

        if (unVisage.m_uneMoustache != nullptr) {
            this->setMoustache(unVisage.m_uneMoustache->getLargeur());
        }

        this->m_mesBoutons = unVisage.m_mesBoutons;

    }

    return *this;
}

Visage::Visage(const Visage &unVisage): m_unNez(unVisage.m_unNez), m_uneEthnie(unVisage.m_uneEthnie), m_unChapeau(nullptr), m_uneMoustache(nullptr) {
    if (unVisage.m_unChapeau) {
        m_unChapeau = new Chapeau(*unVisage.m_unChapeau);  // Copie profonde du chapeau
    }
    if (unVisage.m_uneMoustache) {
        m_uneMoustache = new Moustache(*unVisage.m_uneMoustache);  // Copie profonde de la moustache
    }
    m_mesBoutons = unVisage.m_mesBoutons;

    // Copie des pointeurs de bijoux (pas une copie profonde)
    m_mesBijoux = unVisage.m_mesBijoux;
}

Visage::~Visage() {
    this->empty();
}

std::ostream &operator<<(std::ostream &sortie, const Visage &visage) {
    // Afficher les attributs de base du visage
    sortie << "Visage: \n";

    // Affiche le nez
    sortie << visage.m_unNez << "\n";

    // Affiche l'ethnie
    sortie << visage.m_uneEthnie << "\n";

    // Affiche le chapeau s'il y en a un
    if (visage.m_unChapeau != nullptr) {
        sortie << *visage.m_unChapeau << "\n";
    } else {
        sortie << "  Chapeau: Aucun\n";
    }

    // Affiche la moustache s'il y en a une
    if (visage.m_uneMoustache != nullptr) {
        sortie << *visage.m_uneMoustache << "\n";
    } else {
        sortie << "  Moustache: Aucune\n";
    }

    // Affiche les bijoux
    sortie << "  Bijoux: ";
    if (!visage.m_mesBijoux.empty()) {
        for (const Bijou *bijou : visage.m_mesBijoux) {
            sortie << *bijou << " ";  // Assumant que `Bijou` a un opérateur de sortie
        }
    } else {
        sortie << "Aucun";
    }
    sortie << "\n";

    // Affiche les boutons
    sortie << "  Boutons: ";
    if (!visage.m_mesBoutons.empty()) {
        for (const Bouton &bouton : visage.m_mesBoutons) {
            sortie << bouton << " ";  // Assumant que `Bouton` a un opérateur de sortie
        }
    } else {
        sortie << "Aucun";
    }
        sortie << "\n";

        return sortie;
}