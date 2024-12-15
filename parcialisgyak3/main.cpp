#include <iostream>
#include "EvesKiadas.h"
int main() {
    EvesKiadas evesKiadas("input.txt");
    evesKiadas.ujKiadas("januar","ital",1500);
    evesKiadas.listazas();
    set<string> kategoriak=evesKiadas.kiadasiKategoriak();

    cout<<endl<<"Kategoriak"<<endl;

    for(auto k: kategoriak){
        cout<<k<<endl;
    }

    double atlag = evesKiadas.honaponkentiAtlagKiadas("januar");
    if(atlag == 0.0){
        cout<<"Nincs ilyen hoanp"<<endl;
    }
    else{
        cout<<"A januari honapra az atlag:"<<atlag<<endl;
    }
    evesKiadas.kategoriankentiAtlagKiadas("elelmiszer");
    return 0;
}
