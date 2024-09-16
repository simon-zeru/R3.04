// Les 2 directives ci-cessous permettent d'éviter les problèmes d'inclusions multiples d'une même classe
#ifndef POINT_H
#define POINT_H

// On inclut les librairies utilisées dans le fichier
#include <iostream>
#include <string>
// Attention : pas de clause "using namespace" dans un fichier ".h" !

class Point {

public:

    Point(const std::string & nom = NOM_DEFAULT, int x = X_DEFAULT, int y = Y_DEFAULT);

    ~Point();
    std::string getNom();
    int getX() const;
    int getY() const;
    void setNom(std::string nom);
    void setX(int x);
    void setY(int y);

    void saisir(std::istream &entree = std::cin);
    void afficher(std::ostream &sortie = std::cout);

private:
    // attributs d'instance, préfixés par m_ par convention
    std::string m_nom;
    int m_x{};
    int m_y{};
    // constantes de classe
    static const std::string NOM_DEFAULT;
    static const int X_DEFAULT;
    static const int Y_DEFAULT;
};

#endif /* POINT_H */

