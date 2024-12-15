#include <iostream>
#include "Eremtablazat.h"
int main() {
    Eremtablazat et("input.txt");
    et.ujMedal("Kovacs","arany");
    et.listazas();
    set<string> ember=et.sportolok();
    for(auto e:ember){
        cout<<e<<endl;
    }
    int aranyakszama = et.medalokSzama("");
    cout<<endl<<"aranyak szama:"<<aranyakszama<<endl;
    cout<<"legtobb eremmel rendelkezo sportolo neve:"<<et.legtobbMedal();
    return 0;
}
