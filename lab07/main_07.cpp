#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
using namespace std;

bool customCompare(const string& a, const string& b, const string& alphabet) {
    size_t minLength = min(a.size(), b.size());
    for (size_t i = 0; i < minLength; ++i) {
        size_t indexA = alphabet.find(tolower(a[i])); // Kisbetűre konvertálva
        size_t indexB = alphabet.find(tolower(b[i])); // Kisbetűre konvertálva
        if (indexA != indexB) {
            return indexA < indexB; // Az első eltérésnél eldöntjük a sorrendet
        }
    }
    return a.size() < b.size(); // Ha az elemek azonosak, akkor a rövidebb jöjjön először
}


int main() {
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    string what = "berry";
     auto result  = find_if(fruits.begin(),fruits.end(),[what](const string& e){
         return e.find(what) != string::npos;
     });

    if(result != fruits.end()){
        cout<<*result;
    }else{
        cout<<"Not found "<<what<<endl;
    }

    int a[20] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
    auto result2 = all_of(a,a+20,[](int e){
        return e%2 == 0;
    });
    if(result2){
        cout<<endl<<"All even"<<endl;
    }
    else{
        cout<<endl<<"Not all even"<<endl;
    }


    int b[15] = {1,8,5,2,9,6,3,10,7,4,11,8,5,12,9};
    for_each(b,b+15,[](int& e){
        e *= 2;
    });
    for (int i = 0; i < 15; ++i) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    vector<string> result3;  // This will store the matching months

    // Use copy_if to find all months with exactly 5 characters and insert them into result3
    copy_if(months.begin(), months.end(), back_inserter(result3), [](const string& e) {
        return e.length() == 5;
    });

    // If we found any results, print them
    if (!result3.empty()) {
        for (const auto& month : result3) {
            cout << month << " ";
        }
        cout << endl;
    } else {
        cout << "No such element" << endl;
    }
    vector<double> arr = {5.4, 2.1, 9.3, 4.7, 6.5, 1.8};
    sort(arr.begin(),arr.end(),[](double a, double b){
        return a > b;
    });
    for(auto e:arr){
        cout<<e<<" ";
    }
    cout<<endl;
    vector<double> arr2 = {5.4, 2.1, 9.3, 4.7, 6.5, 1.8};

    sort(arr2.begin(),arr2.end(),greater<double>());

    for(auto e:arr2){
        cout<<e<<" ";
    }
    cout<<endl;

    vector<pair<string, double>> weather = {
            {"January", 0.5},
            {"February", 2.0},
            {"March", 5.0},
            {"April", 9.0},
            {"May", 14.0},
            {"June", 18.0},
            {"July", 21.5},
            {"August", 20.5},
            {"September", 15.0},
            {"October", 10.0},
            {"November", 4.5},
            {"December", 1.0}
    };
    sort(weather.begin(), weather.end(), [](const pair<string,double>&a, const pair<string,double>& b){
        return a.second>b.second;
    } );

    for(auto e:weather){
        cout<<e.first<<" "<<e.second<<endl;
    }

    vector<double> arr3 = { -5.4, 2.1, -9.3, 4.7, 6.5, -1.8 };

    // Rendezés abszolút értékek szerint növekvő sorrendben
    sort(arr3.begin(), arr3.end(), [](double a, double b) {
        return abs(a) < abs(b);  // Az abszolút értékek összehasonlítása
    });

    // Eredmény kiíratása
    cout << "Rendezett tomb (abszolut ertek szerint): ";
    for (double num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    for_each(months.begin(), months.end(), [](string& month) {
        if (!month.empty()) {
            month[0] = tolower(month[0]);  // Az első karakter kisbetűssé alakítása
        }
    });

    // Eredmény kiíratása
    cout << "Honapok kisbetuvel kezdodve: ";
    for (const auto& month : months) {
        cout << month << " ";
    }
    cout << endl;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Véletlenszerűen összekeverjük az ábécét
    random_device rd;
    mt19937 g(rd());
    shuffle(alphabet.begin(), alphabet.end(), g);

    sort(months.begin(), months.end(), [&alphabet](const string& a, const string& b) {
        return customCompare(a, b, alphabet);
    });

    // Eredmény kiíratása
    cout << "Honapok a furcsa abece szerint rendezve: ";
    for (const auto& month : months) {
        cout << month << " ";
    }
    cout << endl;
    return 0;
}