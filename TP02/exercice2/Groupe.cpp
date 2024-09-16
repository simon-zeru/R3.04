#include "Groupe.h"

#include <cstring>

#include "Personne.h"
#include <string>
#include <iostream>

using namespace std;

// A COMPLETER
// Implémenter les méthodes nécessaires pour la forme canonique de COPLIEN

Groupe::Groupe(const std::string &intitule)
        : m_intitule(intitule) {
}

Groupe::Groupe(const Groupe &other): m_intitule(other.m_intitule) {
    // deepcopy du vecteur d'objet Personne
    for (const auto &personne: other.m_effectif) {
        m_effectif.push_back(new Personne(*personne)); // duplique chaque personne
    }
}

Groupe &Groupe::operator=(const Groupe &other) {
    if (this != &other) {
        // Vider l'actuel
        this->empty();

        // Copier le nouvel intitule
        m_intitule = other.m_intitule;

        // Faire une copie profonde du vecteur de personnes
        for (const auto &personne: other.m_effectif) {
            m_effectif.push_back(new Personne(*personne));
        }
    }
    return *this;
}

Groupe::~Groupe() {
    this->empty();
}

void Groupe::empty() {
    for (auto &personne : m_effectif) {
        delete personne; // Libérer la mémoire de chaque Personne
    }
    m_effectif.clear(); // Vider le vecteur
}




///////////////////////////////////////////////////
void Groupe::setIntitule(const std::string &intitule) {
    this->m_intitule = intitule;
}

///////////////////////////////////////////////////
void Groupe::addPersonne(const std::string &nom) {
    this->m_effectif.push_back(new Personne(nom));
}

///////////////////////////////////////////////////
void Groupe::setNomPersonne(unsigned int i,
                            const std::string nom) {
    if (i < this->m_effectif.size())
        this->m_effectif[i]->setNom(nom);
}

///////////////////////////////////////////////////
void Groupe::affiche() const {
    cout << "Groupe " << this->m_intitule << " = { ";
    for (Personne *personne: this->m_effectif)
        cout << personne->getNom() << " ";
    cout << "}" << endl;
}
