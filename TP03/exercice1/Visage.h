#ifndef VISAGE_H
#define VISAGE_H

#include "AttributsVisage.h"
#include <vector>

// A COMPLETER (spécifiez les attributs)

class Visage {
public:
    Visage(int longueurNez, const Ethnie &uneEthnie);
    void setMoustache(int largeur);
    void addBouton(int diametre);
    void setChapeau(const Chapeau &unChapeau);
    void addBijou(const Bijou &unBijou);
    const Visage &operator=(const Visage &unVisage);
    // Constructeur de copie
    Visage(const Visage &unVisage);
    ~Visage();
    inline void empty() {
        delete m_unChapeau;
        m_unChapeau = nullptr;
        delete m_uneMoustache;
        m_uneMoustache = nullptr;
        m_mesBijoux.clear();
        m_mesBoutons.clear();
    }

    // fonction amie : aura accès aux attributs "private"  de la classe Visage (pour éviter d'écrire les getters)
    // attention ce n'est pas une méthode !
    friend std::ostream &operator<<(std::ostream &sortie, const Visage &visage);

private:

    // A COMPLETER : CODEZ CORRECTEMENT LES COMPOSITIONS ET AGREGATIONS
    Nez m_unNez;
    const Ethnie & m_uneEthnie;
    const Chapeau * m_unChapeau;
    Moustache * m_uneMoustache;
    std::vector<const Bijou> m_mesBijoux;
    std::vector<Bouton> m_mesBoutons;

};

#endif /* VISAGE_H */

