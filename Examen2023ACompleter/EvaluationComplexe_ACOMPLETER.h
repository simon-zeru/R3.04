#ifndef EXAMEN2023C_EVALUATIONCOMPLEXE_H
#define EXAMEN2023C_EVALUATIONCOMPLEXE_H

// A COMPLETER

#include <string>
#include <vector>
#include "Evaluation_ACOMPLETER.h"
#include "ObjetContraint.h"

class EvaluationComplexe : public Evaluation {
public:
    EvaluationComplexe(const std::string & intitule);
    ~EvaluationComplexe() override;
    const std::string & getIntitule() const override;
    void setIntitule(const std::string & intitule) override;
    unsigned int getCoefficient() const override;
    void setCoefficient(unsigned int coefficient) override;
    float getNote() const override;
    void setNote(float note) override;
    void addEvaluation(const Evaluation & evaluation) override;
    void affiche() const override;
private:
    std::vector<const Evaluation*> m_contenu;

};


#endif //EXAMEN2023C_EVALUATIONCOMPLEXE_H
