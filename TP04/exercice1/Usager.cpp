#include "Usager.h"

#include <iostream>
using namespace std;
// à compléter

ostream& operator<<(ostream& os, const Usager& usager) {
    cout << "Usager :" << endl;
    cout << "Login -> " << usager.getLogin() << endl;
    cout << "Groupe -> " << usager.getGroupe() << endl;
}

