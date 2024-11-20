//
// Created by Balazs on 2024. 11. 20..
//

#include "Manager.h"


void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    this->beosztottak.push_back(alkalmazott);
}

void Manager::deleteAlkalmazott(int id) {
    auto it = std::find_if(beosztottak.begin(), beosztottak.end(),
                           [id](const Alkalmazott* alkalmazott) {
                               return alkalmazott->getId() == id; 
                           });

    if (it != beosztottak.end()) {
        beosztottak.erase(it);
        cout << "Alkalmazott torolve, ID: " << id << endl;
    } else {
        cout << "Nem talalhato alkalmazott a megadott ID-val: " << id << endl;
    }
}

int Manager::beosztottakSzama() const {
    return this->beosztottak.size();
}

void Manager::print(ostream &os) const {
    Alkalmazott::print(os);

    os << ", Beosztottak szama: " << beosztottakSzama() << endl;

    for (const auto &beosztott : beosztottak) {
        os << "  - ";
        if (beosztott) {
            os << *beosztott;
        } else {
            os << "nullptr";
        }
        os << endl;
    }
}