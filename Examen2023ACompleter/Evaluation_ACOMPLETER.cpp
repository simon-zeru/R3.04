// A COMPLETER

#include "Evaluation_ACOMPLETER.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

const string Evaluation::INTITULE_DEF = "ND";

Evaluation::Evaluation(const string &intitule)
: m_intitule(intitule) {}

const string &Evaluation::getIntitule() const {
    return m_intitule;
}

void Evaluation::setIntitule(const string &intitule) {
    this->m_intitule = intitule;
}

void Evaluation::addEvaluation(const Evaluation &evaluation) {
    throw logic_error("Opération impossible sur une evaluation simple");
}



