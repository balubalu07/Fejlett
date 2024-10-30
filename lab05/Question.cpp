//
// Created by Balazs on 2024. 10. 23..
//

#include "Question.h"

ostream &operator<<(ostream &os, const Question &question) {
    os << "Question: " << question.question<<endl;
    int sorszam =1 ;
    for(auto answer: question.answers) {
        os<<"\t"<<sorszam<<":"<<answer.getAnswer()<<endl;
        sorszam++;
    }
    return os;
}
