// A COMPLETER

#ifndef EXAMEN2023C_EVALUATIONSIMPLE_H
#define EXAMEN2023C_EVALUATIONSIMPLE_H
#include <string>
#include "ObjetContraint.h"
#include "Evaluation_ACOMPLETER.h"

class EvaluationSimple : public Evaluation {
public:
    explicit EvaluationSimple(const std::string & intitule, unsigned int coefficient = COEFF_DEF);
    ~EvaluationSimple() override;
    const std::string & getIntitule() const override;
    void setIntitule(const std::string & intitule) override;
    unsigned int getCoefficient() const override;
    void setCoefficient(unsigned int coefficient) override;
    float getNote() const override;
    void setNote(float note) override;
    void addEvaluation(const Evaluation & evaluation) override;
    void affiche() const override;
private:
    ObjetContraint<float> * m_note;
    unsigned int m_coefficient;
    static const unsigned int COEFF_DEF;
    static const float MAX_DEF;
    static const float MIN_DEF;
};

#endif //EXAMEN2023C_EVALUATIONSIMPLE_H
