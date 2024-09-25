//
// Created by Balazs on 2024. 09. 25..
//

#include "functions.h"
#include <cmath>
int countBits(int number) {
    int count = 0;
    while (number > 0) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number |= (1 << order);
    return true;
}

double mean(double *array, int numElements) {
    double count = 0.0 ;
    if(numElements == 0){
        return NAN;
    }
    for (int i = 0; i < numElements; ++i) {
        count += array[i];
    }

    return count/numElements;
}

double stddev(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double sum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    double mean = sum / numElements;

    double varianceSum = 0.0;
    for (int i = 0; i < numElements; i++) {
        varianceSum += (array[i] - mean) * (array[i] - mean);
    }
    double variance = varianceSum / numElements;

    return sqrt(variance);
}

pair<double, double> max2(double array[], int numElements) {
    pair<double, double> result(NAN, NAN);

    if (numElements == 0) {
        return result;
    }

    double max1 = -INFINITY;
    double max2 = -INFINITY;

    for (int i = 0; i < numElements; i++) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2 && array[i] < max1) {
            max2 = array[i];
        }
    }

    if (max2 == -INFINITY) {
        max2 = NAN;
    }

    if (max1 < max2) {
        result = make_pair(max1, max2);
    } else {
        result = make_pair(max2, max1);
    }

    return result;
}

int countWords(string text) {
    istringstream stream(text);
    string word;
    int count = 0;

    while (stream >> word) {
        count++;
    }

    return count;
}

string code(string text) {
    string encodedText = "";

    for (char c : text) {
        if (isalpha(c)) {
            char nextChar;
            if (c == 'z') {
                nextChar = 'a';
            } else if (c == 'Z') {
                nextChar = 'A';
            } else {
                nextChar = c + 1;
            }
            encodedText += nextChar;
        } else {
            encodedText += c;
        }
    }
    return encodedText;
}

string decode(string text) {
    string decodedText = "";

    for (char c : text) {
        if (isalpha(c)) {
            char prevChar;
            if (c == 'a') {
                prevChar = 'z';
            } else if (c == 'A') {
                prevChar = 'Z';
            } else {
                prevChar = c - 1;
            }
            decodedText += prevChar;
        } else {
            decodedText += c;
        }
    }

    return decodedText;
}

string capitalizeWords(string text) {
    bool newWord = true;
    for (char& c : text) {
        if (isspace(c)) {
            newWord = true;
        } else if (newWord) {
            c = toupper(c);
            newWord = false;
        } else {
            c = tolower(c);
        }
    }
    return text;
}

