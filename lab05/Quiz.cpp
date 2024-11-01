//
// Created by Balazs on 2024. 10. 23..
//

#include "Quiz.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

Quiz::Quiz(const string &name, const string &fname) {
    ifstream f(fname);
    if (!f.is_open()) {
        cout << "error";
        return;
    }
    vector<Answer> answers;
    string line;
    string question;
    while (getline(f, line)) {
        if (line.c_str()[0] == 'Q') {
            question = line.substr(2);
        } else if (line.c_str()[0] == 'A') {
            answers.push_back(Answer(line.substr(2), false));
        } else {
            for (int i = 0; i < answers.size(); i++) {
                if (line.length() == 1) {
                    if (i == stoi(line) - 1) {
                        answers[i].setIsCorrect(true);
                    }
                } else {
                    for (auto a: line) {
                        if (i == a - '0' - 1) {
                            answers[i].setIsCorrect(true);
                        }
                    }
                }
            }
            questions.push_back(Question(question, answers));
            answers.clear();

        }
    }
}

void Quiz::printQuiz() {
    for (auto question: questions) {
        cout << question;
    }
}
