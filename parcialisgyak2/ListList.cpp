//
// Created by Balazs on 2024. 11. 05..
//

#include "ListList.h"
#include <fstream>
ListList::ListList(const string &filename) {
    ifstream  f(filename);
    int a;
    while(f>>a){
        this->instertLast(a);
    }
}

ListList::~ListList() {
    Node * curr = this->first;
    while(curr != nullptr){
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    this->first = nullptr;
    this->nodeCounter = 0;
}

bool ListList::exists(int d) const {
    Node *curr =this->first;
    while(curr != nullptr){
        if(curr->value==d) return true;
        curr=curr->next;
    }
    return false;
}

int ListList::size() const {
    return this->nodeCounter;
}

bool ListList::empty() const {
    return this->first == nullptr;
}

void ListList::insertFirst(int d) {
    Node * newNode = new Node(d);
    newNode->next = this->first;
    this->first = newNode;
    this->nodeCounter ++;
}

void ListList::instertLast(int d) {
    if(this->first == nullptr){
        this->first = new Node(d);
    }
    else{
        Node *newNode = new Node(d);
        Node*curr = this->first;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    this->nodeCounter ++;
}

int ListList::removeFirst() {
    if(this->first != nullptr){
        Node* temp = this->first;
        int d = this->first ->value;
        this->first = this->first->next;
        delete temp;
        this->nodeCounter--;
        return d;
    }
}

void ListList::print(ostream &os) const {
    Node *curr = this->first;
    while(curr!=nullptr){
        os<<curr->value<<" ";
        curr= curr->next;
    }
}

ListList::ListList(const ListList &other) {
    if(other.first == nullptr){
        return;
    }
    Node *othercurr = other.first;
    Node *newNode = new Node(other.first->value);
    this->first = newNode;
    othercurr = othercurr->next;
    Node *thiscurr = this->first;
    while(othercurr!= nullptr){
        Node *temp = new Node(othercurr->value);
        thiscurr->next = temp;
        thiscurr = temp;
        othercurr = othercurr->next;
        this->nodeCounter++;

    }

}

ListList &ListList::operator=(const ListList &other) {
    if(this == &other ){
        return *this;
    }
    Node *curr = this->first;
    while(curr!= nullptr){
        Node *temp = curr;
        curr= curr->next;
        delete temp;
    }
    this->first = nullptr;
    this->nodeCounter = 0;

    this->first = new Node(other.first->value);
    this->nodeCounter ++;
    Node *thiscurr = this->first;
    Node *othercurr = other.first->next;
    while(othercurr!= nullptr){

        Node *temp = new Node(othercurr->value);
        thiscurr->next = temp;
        thiscurr = temp;
        othercurr = othercurr->next;
        this->nodeCounter++;
    }
    return *this;
}

ListList::ListList(ListList &&other) {
    this->first =  other.first;
    this->nodeCounter = other.nodeCounter;
    other.first = nullptr;
    other.nodeCounter = 0;
}

ListList &ListList::operator=(ListList &&other) {

    if(this == &other){
        return *this;
    }
    Node *current = this->first;
    while(current!= nullptr){
        Node*temp = current;
        current = current->next;
        delete temp;
    }
    this->first = other.first;
    this->nodeCounter = other.nodeCounter;
    other.first = nullptr;
    other.nodeCounter = 0;
    return *this;
}

ListList operator+(const ListList &list1, const ListList &list2) {
    ListList result;

    ListList::Node * curr = list1.first;
    while(curr!= nullptr){
        result.instertLast(curr->value);
        curr= curr->next;
    }
    curr = list2.first;

    while(curr!= nullptr){
        result.instertLast(curr->value);
        curr= curr->next;
    }

    return result;

}

ostream &operator<<(ostream &os, const ListList &list) {
    list.print(os);
    return os;
}

