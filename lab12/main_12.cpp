#include <iostream>
#include "SimpleTextGenerator.h"
int main() {
    SimpleTextGenerator t1;
//    t1.trainFromText("Now is not the time for sleep, now is\n"
//                     "the time for party!");
t1.trainFromFile("bible.txt");
//    t1.printData();
    string generatedText;
    generatedText=t1.generate("my lord",15);
    cout<<generatedText;
    return 0;
}