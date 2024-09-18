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

    testConstructeurValide();
    testConstructeurHorsBornes();
    testSetValValide();
    testSetValHorsBornes();

    return 0;
}
