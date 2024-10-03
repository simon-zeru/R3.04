#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <ostream>
#include <string>

#include "Usager.h"

class Element {
  // à compléter
  private:
  std::string m_name;
  const Usager * m_proprietaire;

  public:
  Element(std::string name);

  std::string getName() const {
    return m_name;
  }

  void setName(const std::string &name) {
    this->m_name = name;
  }

  const Usager getProprietaire() const {
    return *m_proprietaire;
  }

  void setProprietaire(const Usager &proprietaire) {
    this->m_proprietaire = &proprietaire;
  }

  virtual void afficher() const {
    std::cout << "Nom : " << this->getName() << std::endl;
    std::cout << m_proprietaire << std::endl;
  };
  virtual void ajouter(Element* element);
};

#endif /* ELEMENT_H */

