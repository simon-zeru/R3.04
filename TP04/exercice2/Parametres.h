#ifndef PARAMETRES_H
#define PARAMETRES_H
#include <string>
#include "Theme.h"
#include "Joueur.h"

class Parametres {

    // à compléter
public:
    const Theme & getTheme() const;
    void setTheme(const Theme & theme);
    const Joueur * getJoueur() const;
    void setJoueur(const Joueur & joueur);
    void afficher() const;
    static Parametres & getInstance();             // Accèder à l'unique instance
    Parametres(Parametres const &) = delete;       // =delete => supprime le constructeur de recopie par défaut
    void operator=(Parametres const &) = delete;   // =delete => supprime l'opérateur = par défaut
    virtual ~Parametres();

protected:
    Parametres(const std::string & intituleTheme = "Par défaut");
private:
    Theme m_theme; // Composition 1..1
    const Joueur * m_joueur; // Agrégation 0..1
};

#endif /* PARAMETRES_H */
