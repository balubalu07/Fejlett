//
// Created by Balazs on 2024. 11. 05..
//

#ifndef PARCIALISGYAK2_LISTLIST_H
#define PARCIALISGYAK2_LISTLIST_H

#import <string>
#include <iostream>
using  namespace std;
class ListList {
public:
    ListList() =default;
    ListList(const string& filename);
    ~ListList();

    bool exists(int d)const;
    int size()const;
    bool empty()const;
    void insertFirst(int d);
    void instertLast(int d);
    int removeFirst();
    void print(ostream& os = cout) const;

    ListList(const ListList&);
    ListList& operator=(const ListList&);
    ListList(ListList&&) ;
    ListList& operator=(ListList&&);

    friend ListList operator+(const ListList& list1, const ListList& list2);
    friend ostream& operator<<(ostream& os, const ListList& list);

private:
    struct Node {
        int value;
        Node* next;
        Node(int v=0,Node * n = nullptr):value(v),next(n){}
    };
    Node *first{nullptr};
    int nodeCounter{0};
};


#endif //PARCIALISGYAK2_LISTLIST_H
