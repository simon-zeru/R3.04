// A COMPLETER

#include "EvaluationSimple_ACOMPLETER.h"
#include <stdexcept>
using namespace std;

const unsigned int EvaluationSimple::COEFF_DEF = 1;
const float EvaluationSimple::MIN_DEF = 0.0;
const float EvaluationSimple::MAX_DEF = 20.0;


EvaluationSimple::EvaluationSimple(const string &intitule, unsigned int coefficient)
: Evaluation(intitule), m_coefficient(coefficient), m_note(nullptr) {}

EvaluationSimple::~EvaluationSimple() {
    if (m_note!= nullptr) delete m_note;
}

const std::string &EvaluationSimple::getIntitule() const {
    return Evaluation::getIntitule();
}

void EvaluationSimple::setIntitule(const string &intitule) {
    Evaluation::setIntitule(intitule);
}

unsigned int EvaluationSimple::getCoefficient() const {
    return m_coefficient;
}

void EvaluationSimple::setCoefficient(unsigned int coefficient) {
    this->m_coefficient = coefficient;
}

float EvaluationSimple::getNote() const {
    if (m_note == nullptr) throw range_error("Aucune note");
    return m_note->getVal();
}

void EvaluationSimple::setNote(float note) {
    if (m_note == nullptr) {
        this->m_note = new ObjetContraint<float>(note, MIN_DEF, MAX_DEF);
    } else {

        this->m_note->setVal(note);
    }
}

void EvaluationSimple::addEvaluation(const Evaluation &evaluation) {
    Evaluation::addEvaluation(evaluation);
}

void EvaluationSimple::affiche() const {
    cout << "Evaluation Simple :   ";
    cout << this->getIntitule() << " - ";

    if (m_coefficient == 1) {
        cout << "Coefficient : ND - ";
    } else {
        cout << "Coefficient : " << m_coefficient << " - ";
    }
    if (m_note == nullptr) {
        cout << "Note : ND\n";
    } else {
        cout << "Note : " << m_note->getVal() << "\n";
    }
}
