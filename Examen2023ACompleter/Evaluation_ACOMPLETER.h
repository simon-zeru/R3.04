// A COMPLETER

#ifndef EXAMEN2023C_EVALUATION_H
#define EXAMEN2023C_EVALUATION_H
#include <string>
#include <iostream>
#include "ObjetContraint.h"

class Evaluation {
public:
    Evaluation(const std::string & intitule = INTITULE_DEF);
    virtual ~Evaluation(){}
    virtual const std::string & getIntitule() const;
    virtual void setIntitule(const std::string & intitule);
    virtual unsigned int getCoefficient() const = 0;
    virtual void setCoefficient(unsigned int coefficient) = 0;
    virtual float getNote() const = 0;
    virtual void setNote(float note) = 0;
    virtual void addEvaluation(const Evaluation & evaluation);
    virtual void affiche() const = 0;
private:
    std::string m_intitule;
    static const std::string INTITULE_DEF;
};

#endif //EXAMEN2023C_EVALUATION_H
