// A COMPLETER

#include <cmath>
#include "gtest/gtest.h"
#include "EvaluationSimple_ACOMPLETER.h"
#include "EvaluationComplexe_ACOMPLETER.h"
using namespace std;

TEST(EvaluationComplexeTest, Constructeur) {
    // Ecrivez ici vos assertions pour tester le constructeur
    // Pour chaque arguments
    // -- Tester que les cas incorrects lèvent une exception
    // -- Tester que les cas corrects ne lèvent pas d'exceptions
    EXPECT_NO_THROW({
                        EvaluationComplexe ec("Test");
                    }) << "Constructeur avec nom 'Test' ne lève pas d'exception";

    EXPECT_NO_THROW({
                        EvaluationComplexe ec();
                    }) << "Constructeur par défaut ne lève pas d'exception";
}

TEST(EvaluationComplexeTest, GetCoefficient) {
    // Ecrivez ici vos assertions pour tester getCoefficient
    EvaluationComplexe ec("Tests informatiques");
    EXPECT_THROW(ec.getCoefficient(), range_error) << "Evaluation complexe vide leve range_error";
    EvaluationSimple esj("Java", 2);
    EvaluationSimple esp("PHP", 3);

    ec.addEvaluation(esj);
    ec.addEvaluation(esp);

    EXPECT_NO_THROW(ec.getCoefficient()) << "Evaluation complexe ne leve pas range_error";
    EXPECT_EQ(ec.getCoefficient(), 5);
}

TEST(EvaluationComplexeTest, GetNote) {
    // Ecrivez ici vos assertions pour tester getNote
    EvaluationComplexe ec("Tests informatiques");
    EXPECT_THROW(ec.getNote(), range_error) << "getNote() lève une rangeError";
    EvaluationSimple esj("Java", 2);
    EvaluationSimple esp("PHP", 4);
    ec.addEvaluation(esj);
    ec.addEvaluation(esp);

    esj.setNote(10);

    EXPECT_THROW(ec.getNote(), range_error) << "getNote() lève une rangeError";

    esp.setNote(15);

    EXPECT_NO_THROW(ec.getNote()) << "getNote() ne lève pas de rangeError";
    EXPECT_EQ(round(ec.getNote()), round((80.0/6.0)));

}

TEST(EvaluationComplexeTest, AddEvaluation) {
    // Ecrivez ici vos assertions pour tester addEvaluation
    EvaluationComplexe ec("Tests informatiques");
    EvaluationSimple esj("Java", 2);
    EvaluationSimple esp("PHP", 4);

    EXPECT_NO_THROW( ec.addEvaluation(esj)) << "addEvaluation sur EvaluationComplexe ne lève aucune exception";

    EXPECT_THROW(esj.addEvaluation(esp), logic_error) << "addEvaluation sur EvaluationSimple lève une logic_error";
}
