////////////////////////////////////////////////////////////////////////////////
// COMPLETEZ CE FICHIER
////////////////////////////////////////////////////////////////////////////////

#include "Parametres.h"
#include <iostream>
using namespace std;

Parametres::Parametres(const std::string &intituleTheme): m_theme(intituleTheme), m_joueur(nullptr) {
    cout << "Le singleton Parametres est construit" << endl;
}

Parametres &Parametres::getInstance() {
    static Parametres uniqueInstance; // uniqueInstance ne sera construit qu'une fois, au premier appel de getInstance
    // Ici c'est le constructeur par défaut (protected) qui est appelé implicitement
    return uniqueInstance;
}

const Joueur *Parametres::getJoueur() const {
    return this->m_joueur;
}

void Parametres::setJoueur(const Joueur &joueur) {
    this->m_joueur = & joueur;
}

const Theme &Parametres::getTheme() const {
    return this->m_theme;
}

void Parametres::setTheme(const Theme &theme) {
    this->m_theme = theme;
}

void Parametres::afficher() const {
    cout << "Paramètres: \n";
    cout << "Theme: " << m_theme.getIntitule() << endl;
    if (m_joueur != nullptr) {
        cout << "Joueur: " << m_joueur->getPseudo() << endl;
    } else {
        cout << "Joueur: Anonyme" << endl;
    }
}

Parametres::~Parametres() { // Le destructeur sera appelé lorsque le programme se termine
    cout << "Le singleton Parametres est détruit" << endl;
}


