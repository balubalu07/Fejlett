//
// Created by Balazs on 2024. 12. 15..
//

#ifndef PARICALISGYAK4_EREMTABLAZAT_H
#define PARICALISGYAK4_EREMTABLAZAT_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <set>
using  namespace std;
class Eremtablazat {
private:
    map<string, vector<pair<string, int>>> medalok;
public:
    Eremtablazat(const string & filename);
    void listazas() const;
    void ujMedal(const string& nev, const string& medalTipus);
    set<string> sportolok() const;
    int medalokSzama(const string& medalTipus) const;
    string legtobbMedal();
};


#endif //PARICALISGYAK4_EREMTABLAZAT_H
