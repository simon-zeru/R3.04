#ifndef ENTIERCONTRAINT_H
#define ENTIERCONTRAINT_H

#include <iostream>
#include <limits>

class EntierContraint {
public:
    
    EntierContraint(int min = MIN_DEF, int max = MAX_DEF, int value = VAL_DEF);

    int getMin() const;
    int getMax() const;
    int getVal() const;
    void setMin(int min);
    void setMax(int max);
    void setVal(int value);

    void saisir(std::istream &entree = std::cin);
    void afficher(std::ostream &entree = std::cout);

private:

    int m_min;
    int m_max;
    int m_val;

    // Constantes de Classe (static) pour définir les valeurs par défaut des attributs d'un entier contraint
    static constexpr int VAL_DEF = 0;
    static constexpr int MIN_DEF = std::numeric_limits<int>::min(); // le plus petit int possible
    static constexpr int MAX_DEF = std::numeric_limits<int>::max(); // le plus grand int possible
};

#endif /* ENTIERCONTRAINT_H */

