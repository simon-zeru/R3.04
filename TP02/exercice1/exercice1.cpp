#include <cstdlib>
#include <iostream>
#include "EntierContraint.h"
using namespace std;

int main(int argc, char** argv) {
    
    // A Compléter
    // Il faut tester operator int, operator << et operator >> sur la classe EntierContraint

    EntierContraint entierContraint(5, 0, 100);


    int i = static_cast<int>(entierContraint);

    printf("i : %d\n", i);
    cout << "Entier un entier" << endl;
    // Lecture de la valeur d'un entier contraint
    cin >> entierContraint;
    // Ecris directement la valeur d'entierContraint
    cout << entierContraint << endl;

    entierContraint = i;

    entierContraint.afficher();

    return 0;
}

