#ifndef CONTENEUR_H
#define CONTENEUR_H

#include <vector>
#include <iostream>
#include <stdexcept>

template<class T>
class Conteneur {

// A COMPLETER : Spécifiez ici le template Conteneur<T>
    public:
        Conteneur();
        ~Conteneur();
        Conteneur(const Conteneur<T> & unConteneur);
        Conteneur<T> & operator=(const Conteneur<T> & unConteneur);
        void empty();
        void ajouter(T* element);
        void afficher(std::ostream & out = std::cout) const;
    private:
    std::vector<T*> contenu;
};

// A COMPLETER : Implémentez ici les méthodes du template Conteneur<T> (pas de fichier .cpp pour un template)
template<class T>
Conteneur<T>::Conteneur() {
    // les classe standards de c++ s'initialise par défaut,
    // on aurait pu faire : contenu() avant l'accolade
}

template<class T>
Conteneur<T> &Conteneur<T>::operator=(const Conteneur<T> &unConteneur) {
    if (this != &unConteneur) {
        this->empty();
        for (T* element : unConteneur.contenu) {
            contenu->push_back(element);
        }
    }
    return *this;
}

template<class T>
Conteneur<T>::Conteneur(const Conteneur<T> &unConteneur) {
    for (T* element : unConteneur.contenu) {
        contenu.push_back(element);
    }
}

template<class T>
Conteneur<T>::~Conteneur() {
    this->empty();
}

template<class T>
void Conteneur<T>::empty() {
    for (T* element : contenu) {
        delete element;
    }
    contenu.clear();
}

template<class T>
void Conteneur<T>::ajouter(T *element) {
    contenu->push_back(element);
}

template<class T>
void Conteneur<T>::afficher(std::ostream &out) const {

    out << "Conteneur:\n";
    for (T* element : contenu) {
        out << *element << " ";
    }
    out << std::endl;

}







#endif /* CONTENEUR_H */

