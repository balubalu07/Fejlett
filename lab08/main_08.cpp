#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
int main() {
    Manager manager("Nagy", "Erzsebet", 1975, "vezeto");

    // Dinamikusan foglalunk alkalmazottakat
    Alkalmazott* alkalmazott1 = new Alkalmazott("Kovacs", "Janos", 1985, "programozo");
    Alkalmazott* alkalmazott2 = new Alkalmazott("Szabo", "Anna", 1990, "tesztelo");

    // Hozzáadjuk őket a managerhez
    manager.addAlkalmazott(alkalmazott1);
    manager.addAlkalmazott(alkalmazott2);

    // Kiírjuk a manager adatait
    cout << manager << endl;

    // Törlünk egy alkalmazottat
    manager.deleteAlkalmazott(2);

    // Újra kiírjuk a manager adatait
    cout << manager << endl;

    return 0;
}