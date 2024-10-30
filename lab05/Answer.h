//
// Created by Balazs on 2024. 10. 23..
//

#ifndef CPP_2024_ANSWER_H
#define CPP_2024_ANSWER_H
#include <string>
using namespace std;

class   Answer {
private:
    string answer;
    bool isCorrect;
public:
     Answer(const string &answer, bool isCorrect):answer(answer),isCorrect(isCorrect){}
     Answer() = default;
     string getAnswer()const{
         return answer;
     }
     void setAnswer(const string &answer){
         this->answer = answer;
     }
     bool getIsCorrect()const{
         return isCorrect;
     }
     void setIsCorrect(bool isCorrect){
         this->isCorrect = isCorrect;
     }
};


#endif
