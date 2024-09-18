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
        operator T() const;
        void afficher(std::ostream & sortie = std::cout) const;
    private:
        T m_val;
        T m_min;
        T m_max;

};

// A COMPLETER : Implémentez ici les méthodes du template ObjetContraint<T> (pas de fichier .cpp pour un template)
template<class T>
ObjetContraint<T>::ObjetContraint(T min, T max, T val): m_min(min), m_max(max), m_val(val) {
    if (!(min < val && val < max)) {
        throw std::out_of_range("valeur hors bornes");
    }
}

template<class T>
const T & ObjetContraint<T>::getMin() const {
    return this->m_min;
}

template<class T>
const T & ObjetContraint<T>::getMax() const {
    return this->m_max;
}

template<class T>
const T & ObjetContraint<T>::getVal() const {
    return this->m_val;
}
template<class T>
void ObjetContraint<T>::setVal(const T & val) {
    if (!(m_min < val && val < m_max )) {
        throw std::out_of_range("Valeur hors bornes");
    }
    this->m_val = val;
}

template<class T>
ObjetContraint<T>::operator T() const {
    return this->m_val;
}

template<class T>
void ObjetContraint<T>::afficher(std::ostream &sortie) const {
    std::cout << "Val : " << m_val << std::endl;
    std::cout << "Min : " << m_min << std::endl;
    std::cout << "Max : " << m_max << std::endl;

}

#endif /* OBJETCONTRAINT_H */

