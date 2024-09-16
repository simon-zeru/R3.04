#include <cstdlib>
#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

int main(int argc, char** argv) {

    Point p1; // Utilise le constructeur Point::Point(string, int, int)
    // avec arguments constr. par défaut
    Point p2("p1",10, 20); // Crée un nouveau Point avec nom="p1" x=10 et y=20
    // Déclaration d'un pointeur sur objet Point
    Point *p3;
    p3 = new Point("p3",20, 30); // Instanciation de l'objet dynamique
    // avec arguments explicites
    auto * p4 = new Point; // Instanciation de l'objet dynamique
    // avec arguments constr. par défaut

    p4->saisir();

    p1.afficher();
    p2.afficher();
    p3->afficher();
    p4->afficher();

    delete p3; // On n'oublie pas de libérer la mémoire !
    delete p4; // Idem
    return 0;
}

