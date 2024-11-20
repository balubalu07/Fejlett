//
// Created by Balazs on 2024. 11. 20..
//

#ifndef LAB8_SZEMELY_H
#define LAB8_SZEMELY_H
#include <string>
#include<iostream>
using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(string vezetekNev, string keresztNev, int szuletesiEv);
    virtual void print(ostream& os) const;
    friend ostream &operator<<(ostream& os,const Szemely& sz);
};


#endif //LAB8_SZEMELY_H
