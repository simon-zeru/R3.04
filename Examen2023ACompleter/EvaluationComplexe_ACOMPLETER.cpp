// A COMPLETER

#include "EvaluationComplexe_ACOMPLETER.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

EvaluationComplexe::EvaluationComplexe(const string &intitule): Evaluation(intitule) {}

EvaluationComplexe::~EvaluationComplexe()  {
    for(auto * evaluation : m_contenu) delete evaluation;
}

const std::string &EvaluationComplexe::getIntitule() const {
    return Evaluation::getIntitule();
}

void EvaluationComplexe::setIntitule(const string &intitule) {
    Evaluation::setIntitule(intitule);
}

unsigned int EvaluationComplexe::getCoefficient() const {
    if (m_contenu.size() == 0) throw range_error("Evaluation complexe vide");
    unsigned int coeff = 0;
    for (int i = 0; i < m_contenu.size(); i++) {
        coeff += m_contenu[i]->getCoefficient();
    }
    return coeff;
}

void EvaluationComplexe::setCoefficient(unsigned int coefficient) {
    throw logic_error("Opération impossible sur evaluation complexe");
}

float EvaluationComplexe::getNote() const {
    try {
        float moyenne = 0.0f;

        for (int i = 0; i < m_contenu.size(); i++) {
            moyenne += m_contenu[i]->getNote() * m_contenu[i]->getCoefficient();
        }

        return round((moyenne / this->getCoefficient())*100)/100;
    } catch (range_error & e) {
        cout << " évaluation complexe vide ou qui contient au moins une évaluation sans note." << endl;
        throw;
    }
}

void EvaluationComplexe::setNote(float note) {
    throw logic_error("Opération impossible sur evaluation complexe");
}


void EvaluationComplexe::addEvaluation(const Evaluation &evaluation) {
    try {
        m_contenu.push_back(&evaluation);
    } catch (bad_alloc & exception) { // Exception levée si plus de place dans le tas
        // on affiche une trace sur le flux d'erreur standard, cerr
        cerr << "EvaluationComplexe::addEvaluation : échec ajout, plus de mémoire disponible dans le tas";
        // on propage l'exception
        throw;
    }
}

void EvaluationComplexe::affiche() const {
    cout << "Evaluation Complexe :  ";
    cout << this->getIntitule() << " - ";
    try {
        cout << "Coefficient : " << this->getCoefficient() << " - ";
    } catch (range_error & r) {
        cout << "Coefficient: ND - ";
    }
    try {
        cout << "Note : " << this->getNote() << "\n";
    } catch (range_error & e) {
        cout << "Note: ND\n";
    }
}
