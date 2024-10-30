#include <iostream>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "Quiz.h"
using namespace std;
int main() {
//    Question question;
//    question.setQuestion("Mi a friend szerepe");
//    vector<Answer> answers;
//    answers.push_back(Answer("baratkozas mas nyelvekkel",false));
//    answers.push_back(Answer("egy fuggveny es egy osztaly kozotti kapcsolat, a fuggveny hozzafer az osztaly peldanyainak a privat reszehez",true));
//    answers.push_back(Answer("baratok",false));
//    answers.push_back(Answer("jatszotarsak",false));
//    question.setAnswers(answers);
//    cout<<question<<endl;
    Quiz quiz("quiz1","questions.txt");
    quiz.printQuiz();
    return 0;
}