//
// Created by Balazs on 2024. 10. 23..
//

#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H
#include "Answer.h"
#include <string>
#include <vector>
#include <ostream>
#include <iomanip>

using namespace  std;
class Question {
    string question;
    vector<Answer> answers;
public:
    Question(const string &question, const vector<Answer> &answers) : question(question), answers(answers) {}
    Question() = default;
    string getQuestion() const {
        return question;
    }
    vector<Answer> getAnswers() const {
        return answers;
    }
    void setQuestion(const string &question) {
        this->question = question;
    }
    void setAnswers(const vector<Answer> &answers) {
        this->answers = answers;
    }

    friend ostream &operator<<(ostream &os, const Question &question);
};


#endif //LAB5_QUESTION_H
