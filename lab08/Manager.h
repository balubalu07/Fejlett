//
// Created by Balazs on 2024. 11. 20..
//

#ifndef LAB8_MANAGER_H
#define LAB8_MANAGER_H

#include "Alkalmazott.h"
#include <vector>
#include <algorithm>
class Manager : public Alkalmazott {
    vector<Alkalmazott*> beosztottak;
public:
    Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor)
            : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor) {}

    void addAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazott(int id);

    int beosztottakSzama() const;

    void print(std::ostream &os) const override;

};


#endif //LAB8_MANAGER_H
