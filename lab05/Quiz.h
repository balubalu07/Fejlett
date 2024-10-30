//
// Created by Balazs on 2024. 10. 23..
//

#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H
#include "Question.h"
using namespace std;
#include <iomanip>
#include "Answer.h"
class Quiz {
private:
    string name;
    vector<Question> questions;
public:
    Quiz(const string &name):name(name){};
    Quiz(const string &name,const string &fname);
    string getName()const{
        return this->name;
    }
    void printQuiz();


};


#endif //LAB5_QUIZ_H
