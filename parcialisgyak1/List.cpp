//
// Created by Balazs on 2024. 11. 04..
//

#include "List.h"
#include <fstream>
List::List(const string &filename) {
    ifstream  f(filename);
   while(!f.eof()){
       int a;
       f>>a;
       instertLast(a);
   }
}

List::~List() {
    this->first=nullptr;
}

bool List::exists(int d) const {
    Node *curr = this->first;
    while(curr!= nullptr){
        if(curr->value ==d){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    return this->first == nullptr;
}

void List::insertFirst(int d) {
    Node *newNode = new Node(d);
    newNode->next = this->first;
    this->first =newNode;
    this->nodeCounter++;
}

void List::instertLast(int d) {
    Node *newNode = new Node(d);
    newNode->next = nullptr;
   if(this->first == nullptr){
       this->first = newNode;
   }
   else{
       Node *curr = this->first;
       while(curr->next!=nullptr){
           curr = curr->next;
       }
       curr->next = newNode;
   }
   this->nodeCounter++;
}

int List::removeFirst() {
    if(this->first !=nullptr){
        Node*temp = this->first;
        this->first = this->first->next;
        int d = temp->value;
        delete temp;
        this->nodeCounter--;
        return d;
    }
}

void List::print(ostream &os) const {
    Node *curr = this->first;
    while(curr!= nullptr){
        os<<curr->value<<" ";
        curr = curr->next;
    }
}

List::List(const List &other) {
    if(other.first == nullptr){
        return;
    }
    Node*currentOther = other.first;
    Node *newNode = new Node(currentOther->value);
    this->first = newNode;
    this->nodeCounter ++;
    Node *currentThis = this->first;
    currentOther = currentOther->next;
    while(currentOther!= nullptr){
        Node*temp = new Node(currentOther->value);
        currentThis->next = temp;
        currentThis = temp;
        currentOther = currentOther->next;
        this->nodeCounter++;
    }
}

List &List::operator=(const List &other) {
    if(this == &other){
        return *this;
    }
    Node *current = this->first;
    while(current!= nullptr){
        Node*temp = current;
        current = current->next;
        delete temp;
    }
    this->first = nullptr;
    this->nodeCounter = 0;

    this->first = new Node(other.first->value);
  this->nodeCounter ++;
    Node *currentThis = this->first;
    Node *currentOther = other.first->next;
    while(currentOther!= nullptr){
        Node*temp = new Node(currentOther->value);
        currentThis->next = temp;
        currentThis = temp;
        currentOther = currentOther->next;
        this->nodeCounter++;
    }
    return *this;
}

List::List(List &&other) {
    this->first = other.first;
    this->nodeCounter = other.nodeCounter;
    other.first = nullptr;
other.nodeCounter = 0;
}

List &List::operator=(List &&other) {
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

List operator+(const List &list1, const List &list2) {
    List result;

    List::Node* current = list1.first;
    while(current != nullptr){
        result.instertLast(current->value);
        current=current->next;
    }

    current = list2.first;
    while(current != nullptr){
        result.instertLast(current->value);
        current=current->next;
    }
    return result;
}

ostream &operator<<(ostream &os, const List &list) {
    list.print(os);
    return os;
}


