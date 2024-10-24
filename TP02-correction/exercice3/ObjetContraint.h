#ifndef OBJETCONTRAINT_H
#define OBJETCONTRAINT_H
#include <stdexcept>

template <class T>
class ObjetContraint {
public:
    ObjetContraint(const T & val, const T & min, const T & max);

    inline const T & getMin() const {
        return m_min;
    }

    inline const T & getMax() const {
        return m_max;
    }

    inline const T & getVal() const {
        return m_val;
    }
    void setVal(const T & val);

    inline operator T() const {
        return getVal();
    }
private:
    T m_val;
    T m_min;
    T m_max;
};

// Implémentez ici les méthodes du template (pas de fichier .cpp pour un template)

template <class T>
ObjetContraint<T>::ObjetContraint(const T & val, const T & min, const T & max)
: m_min(min), m_max(max) {
    setVal(val);
}

template <class T>
void ObjetContraint<T>::setVal(const T & val) {
    if (getMax() < val || val < getMin()) // on n'utilise que l'opérateur < comme demandé
        throw std::domain_error("Valeur Hors Intervalle Min..Max"); // l'exception domain_error est pertinente dans ce cas
    this->m_val = val;
}

#endif /* OBJETCONTRAINT_H */

