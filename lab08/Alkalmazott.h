//
// Created by Balazs on 2024. 11. 20..
//

#ifndef LAB8_ALKALMAZOTT_H
#define LAB8_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely {
protected:
    string munkakor;
    static int kovetkezoId;
    int id;
public:
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor);

    void print(std::ostream &os) const override;

    bool operator==(const Alkalmazott &other) const {
        return vezetekNev == other.vezetekNev &&
               keresztNev == other.keresztNev &&
               szuletesiEv == other.szuletesiEv &&
               munkakor == other.munkakor;
    }
    int getId() const;

};


#endif //LAB8_ALKALMAZOTT_H
