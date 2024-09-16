#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "Personne.h"
/*
Forme canonique de coplien
*/
class Groupe {
public:
    // Constructeur par défaut
    Groupe(const std::string & intitule = "Un Groupe");
    // Constructeur par recopie
    Groupe(const Groupe & other);
    // Opérateur d'affectation
    Groupe & operator=(const Groupe & other);
    // Destructeur
    ~Groupe();
    // Libération mémoire
    void empty();
    void setIntitule(const std::string & intitule);
    void addPersonne(const std::string & nom);
    void setNomPersonne(unsigned int i,
            const std::string nom);
    void affiche() const;

    // A COMPLETER POUR METTRE SOUS FORME CANONIQUE DE COPLIEN

private:
    std::string m_intitule;
    std::vector<Personne*> m_effectif;           // un Groupe est composé de Personnes
};

#endif /* GROUPE_H */

