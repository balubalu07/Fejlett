//
// Created by Balazs on 2024. 11. 20..
//

#include "Alkalmazott.h"
int Alkalmazott::kovetkezoId = 1;
Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor)
        : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor) {
    this->id = kovetkezoId++;
}


void Alkalmazott::print(ostream& os) const {
    os << vezetekNev << " " << keresztNev << " (" << szuletesiEv << "), Munkakor: "
       << munkakor << ", ID: " << id;
}

int Alkalmazott::getId() const {
    return this->id;
}
