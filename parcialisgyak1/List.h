//
// Created by Balazs on 2024. 11. 04..
//

#ifndef PARCIALISGYAK1_LIST_H
#define PARCIALISGYAK1_LIST_H
#import <string>
#include <iostream>
using  namespace std;
class List {
public:
    List() =default;
    List(const string& filename);
    ~List();

    bool exists(int d)const;
    int size()const;
    bool empty()const;
    void insertFirst(int d);
    void instertLast(int d);
    int removeFirst();
    void print(ostream& os = cout) const;

    List(const List&);
    List& operator=(const List&);
    List(List&&) ;
    List& operator=(List&&);

    friend List operator+(const List& list1, const List& list2);
    friend ostream& operator<<(ostream& os, const List& list);

private:
    struct Node {
        int value;
        Node* next;
        Node(int v=0,Node * n = nullptr):value(v),next(n){}
};
    Node *first{nullptr};
    int nodeCounter{0};
};


#endif //PARCIALISGYAK1_LIST_H
