//
// Created by Balazs on 2024. 11. 20..
//

#include "Szemely.h"

Szemely::Szemely(string vezetekNev, string keresztNev, int szuletesiEv) {
    this->vezetekNev = vezetekNev;
    this->keresztNev=keresztNev;
    this->szuletesiEv=szuletesiEv;
}

void Szemely::print(ostream &os) const {
    os<<this->vezetekNev<<" "<<this->keresztNev<<" ("<<this->szuletesiEv<<")";
}

ostream &operator<<(ostream &os, const Szemely &sz) {
    sz.print(os);
    return os;
}

