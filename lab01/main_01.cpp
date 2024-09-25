#include <iostream>
#include <cmath>
#include <utility>
#include "functions.h"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ///First

//    for (int i = 0; i <=127 ; ++i) {
//        cout << "The number: " << i << ",the count of the bits: " << countBits(i) << endl;
//    }

    ///Second

//    for (int i = 0; i < 35; ++i) {
//        int n = 0;
//        if(setBit(n, i)){
//            cout<<i<<" ---> " << n <<endl;
//        }else{
//            cout<<"Impossible operation!" << endl;
//        }
//    }
    ///Third

//    double a[15];
//    int numElements=15;
//    for (int i = 0; i < numElements; ++i) {
//        a[i] = i;
//    }
//    cout << mean(a,numElements);

    ///Forth

//    double array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
//    int numElements = sizeof(array) / sizeof(array[0]);
//
//    double result = stddev(array, numElements);
//
//    if (isnan(result)) {
//        cout << "Empty array" << endl;
//    } else {
//        cout << "Standard deviation: " << result << endl;
//    }

    ///Fifth

//    double array1[] = {3.5, 1.2, 4.6, 2.3, 5.1};
//    double array2[] = {7.2};
//    double array3[] = {};
//
//    int numElements1 = sizeof(array1) / sizeof(array1[0]);
//    int numElements2 = sizeof(array2) / sizeof(array2[0]);
//    int numElements3 = sizeof(array3) / sizeof(array3[0]);
//
//    auto result1 = max2(array1, numElements1);
//    cout << "The two biggest element: (" << result1.first << ", " << result1.second << ")" << endl;
//
//    auto result2 = max2(array2, numElements2);
//    cout << "The two biggest element: (" << result2.first << ", " << result2.second << ")" << endl;
//
//    auto result3 = max2(array3, numElements3);
//    cout << "The two biggest element: (" << result3.first << ", " << result3.second << ")" << endl;

    ///String First

//    double sum = 0.0;
//    for (int i = 1; i < argc; i++) {
//        istringstream inputstream(argv[i]);
//        double number;
//
//        if (inputstream >> number) {
//            sum += number;
//        } else {
//            cout << argv[i] << ": TEXTUAL" << endl;
//        }
//    }
//
//    cout << "The sum: " << sum << endl;

    ///String second

//    string text = "Ez egy példa szöveg, amelyben szavakat számolunk.";
//    int wordCount = countWords(text);
//
//    cout << "The count of words int the text: " << wordCount << endl;

    ///String third

//    string originalText = "Hello, World! zZz";
//    string encoded = code(originalText);
//    string decoded = decode(encoded);
//
//    cout << "Original text: " << originalText << endl;
//    cout << "Coded text: " << encoded << endl;
//    cout << "Encoded text: " << decoded << endl;

    ///String forth
//
//    string line;
//
//    cout << "Give me a text:" << endl;
//
//    while (getline(cin, line)) {
//        string capitalizedLine = capitalizeWords(line);
//        cout << capitalizedLine << endl;
//    }

    ///String Bonus


    return 0;
}
