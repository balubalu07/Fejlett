#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <algorithm>
#include "allmavizsga.h"
void gyakorisag(int n,int m){
    srand(time(0));
    vector<int> indextomb(m,0);
    for (int i = 0; i < n; ++i) {
        int szam = rand()%m;
        indextomb.at(szam)++;
    }
    sort(indextomb.begin(),indextomb.end(),[](const int& a,const int& b){return a>b;});
    for (int i = 0; i < m; ++i) {
        if(indextomb.at(i)>0){
            cout<<i<<":"<<indextomb.at(i)<<endl;
        }
    }
}


int main() {
    gyakorisag(15,50);
    allmavizsga a("index.txt");
    a.display();
    vector<string> szavak = a.searchKeyword("iOS application");
    cout<<"keresett elem alapjan:"<<endl;
    for(auto &i:szavak){
        cout<<i<<",";
    }
    cout<<endl<<"szukitett kereses:"<<endl;
    map<string,vector<string>> szavak2 = a.search("Android");
    for(auto &i:szavak2){
        cout<<i.first<<":";
        for(auto &j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
    return 0;
}
