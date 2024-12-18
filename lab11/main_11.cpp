#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"
int main() {
    ifstream file("telepulesek.csv");
    string line;
    getline(file,line);
    multimap<string,Settlement> holder;
    while(getline(file,line)){
        string sett;
        string county;
        string pop;
        istringstream iss(line);
        getline(iss,sett,',');
        getline(iss,county,',');
        getline(iss,pop,',');
        if(pop==""){
            pop="0";
        }
        Settlement s(sett,county,stoi(pop));
        holder.insert({county,s});
    }

    SettlementStatisticsImpl ss(holder);
    vector<Settlement> r1 = ss.findSettlementsByCounty("MS");
    cout<<"Settlements in MS"<<endl;
    for(auto s : r1){
        cout<<s;
    }
    cout<<"NumSettlements:"<<ss.numSettlements()<<endl;
    cout<<"numcounties:"<<ss.numCounties()<<endl;
    cout<<"num settlements by county CV :"<<ss.numSettlementsByCounty("CV")<<endl;
    vector<Settlement>r2 = ss.findSettlementsByName("Magina");
    try {
        Settlement found = ss.findSettlementsByNameAndCounty("Badai","AB");
        cout << "Found: " << found.getName() << ", County: " << found.getCounty() << ", Population: " << found.getPopulation() << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }




    return 0;
}