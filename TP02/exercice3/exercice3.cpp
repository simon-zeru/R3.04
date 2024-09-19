#include <iostream>
#include <stdexcept>
#include "ObjetContraint.h"
#include "Point.h"

using namespace std;

void testConstructeurValide() {
    try {
        ObjetContraint<int> obj(0, 10, 5);
        if (obj.getVal() == 5 && obj.getMin() == 0 && obj.getMax() == 10) {
            cout << "testConstructeurValide: PASS\n";
        } else {
            cout << "testConstructeurValide: FAIL\n";
        }
    } catch (...) {
        cout << "testConstructeurValide: FAIL (exception levée)\n";

    }
}

void testConstructeurHorsBornes() {
    try {
        ObjetContraint<int> obj(0, 10, 15);  // Devrait lever une exception
        cout << "testConstructeurHorsBornes: FAIL\n";
    } catch (const out_of_range&) {
        cout << "testConstructeurHorsBornes: PASS\n";
    } catch (...) {
        cout << "testConstructeurHorsBornes: FAIL (autre exception levée)\n";
    }
}

void testSetValValide() {
    try {
        ObjetContraint<int> obj (0, 10, 7);
        if (obj.getVal() == 7) {
            cout << "testSetValValide: PASS\n";
        } else {
            cout << "testSetValValide: FAIL\n";
        }
    } catch (...) {
        cout << "testSetValValide: FAIL (exception levée)\n";
    }
}

void testSetValHorsBornes() {
    try {
        ObjetContraint<int> obj(0, 10, 7);
        obj.setVal(15);  // Devrait lever une exception
        cout << "testSetValHorsBornes: FAIL\n";
    } catch (const out_of_range&) {
        cout << "testSetValHorsBornes: PASS\n";
    } catch (...) {
        cout << "testSetValHorsBornes: FAIL (autre exception levée)\n";
    }
}

int main() {

//    testConstructeurValide();
//    testConstructeurHorsBornes();
//    testSetValValide();
//    testSetValHorsBornes();

    Point p1;
    Point p2;
    Point p3;

    cout << "Saisir un point p1 : " << endl;
    p1.saisir();
    p1.afficher();
    do {
        cout << "Saisir un point p2 >= p1 : " << endl;
        p2.saisir();
        p2.afficher();

        if (p2<p1) {
            cout << "Le point p2 est inférieur au point p1, réessayer..." << endl;
        }
    } while (p2<p1);

    cout << "Saisir un point p3 : " << endl;
    p3.saisir();
    try {
        ObjetContraint<Point> o1 (p1, p2, p3);
        cout << "p3 se trouve dans le rectangle délimité par p1 et p2" << endl;
    } catch (const out_of_range&) {
        cout << "Point p3 hors du rectangle délimité par p1 et p2" << endl;
    }

    return 0;
}
