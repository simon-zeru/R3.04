#ifndef OBJETCONTRAINT_H
#define OBJETCONTRAINT_H
#include <stdexcept>

template <class T>
class ObjetContraint {

    // A COMPLETER : Spécifiez ici le template de classe ObjetContraint<T>
    public:
        ObjetContraint(T val, T min, T max);
        const T & getMin() const;
        const T & getMax() const;
        const T & getVal() const;
        void setVal(const T & val);
        const operator T() const;
    private:
        T m_val;
        T m_min;
        T m_max;

};

// A COMPLETER : Implémentez ici les méthodes du template ObjetContraint<T> (pas de fichier .cpp pour un template)
template<class T>
ObjetContraint<T>::ObjetContraint(T min, T max, T val): m_min(min), m_max(max), m_val(val) {}

template<class T> int ObjetContraint<T>::getMin() const {
    return this->m_min;
}

template<class T> int ObjetContraint<T>::getMax() const {
    return this->m_max;
}

template<class T> int ObjetContraint<T>::getVal() const {
    return this->m_val;
}
#endif /* OBJETCONTRAINT_H */

