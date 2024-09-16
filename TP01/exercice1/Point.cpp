// Dans le fichier d'implémentation d'une classe, on doit inclure le fichier de spécification de cette classe
#include "Point.h"
#include <iostream>
#include <utility>

using namespace std;
// Et on inclura aussi les librairies utilisées ici

const string Point::NOM_DEFAULT = "defaultPoint";
const int Point::X_DEFAULT = 0;
const int Point::Y_DEFAULT = 0;

Point::Point(const string &nom, int x, int y): m_nom(nom), m_x(x), m_y(y) {}

Point::~Point() {}


string Point::getNom() {
    return this->m_nom;
}

void Point::setNom(string nom) {
    this->m_nom = move(nom);
}

int Point::getX() const {
    return this->m_x;
}

int Point::getY() const {
    return this->m_y;
}

void Point::setX(int x) {
    this->m_x = x;
}

void Point::setY(int y) {
    this->m_y = y;
}

void Point::afficher(ostream &sortie) {
    sortie << "(" << this->m_nom << ", " << this->m_x << ", " << this->m_y << ")";
}


void Point::saisir(istream &entree) {
    cout << "Entrez le nom : " << endl;
    cin >> this->m_nom;
    cout << "Entrez le x : " << endl;
    cin >> this->m_x;
    cout << "Entrez le y : " << endl;
    cin >> this->m_y;
}


