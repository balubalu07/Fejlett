//
// Created by Balazs on 2024. 10. 09..
//

#include "List.h"

List::List() : first(nullptr) {
    cout << "konstruktor hivas" << endl;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    if (nodeCounter == 0) {
        return false;
    }
    return true;
}

List::~List() {

    cout << endl  <<"destruktor hivas" << endl;
    while(first != nullptr){
        Node *temp = first;
        first = first->next;
        delete temp;
    }

}

void List::insertFirst(int d) {
    Node *nn = new Node(d, nullptr);
    nn->next = first;
    first = nn;
    nodeCounter++;
}

void List::print() const {
    Node* p= first;
    cout<<endl << "A lista elemei:";
    while(p!= nullptr){
        cout<<p->value<<" ";
        p=p->next;
    }
}

bool List::exists(int d) const {
    if(first->value ==d) return  true;
    Node *p=first;
    while(p!=nullptr){
        if(p->value == d){
            return true;
        }
        p=p->next;
    }
}

int List::removeFirst() {
        Node *temp = first;
        first = first->next;
        delete temp;
}

void List::remove(int d, List::DeleteFlag df) {
    if (empty()) {
        return;
    }

    Node* current = first;
    Node* previous = nullptr;

    while (current != nullptr) {
        bool conditionMet = false;

        switch (df) {
            case DeleteFlag::LESS:
                conditionMet = (current->value < d);
                break;
            case DeleteFlag::EQUAL:
                conditionMet = (current->value == d);
                break;
            case DeleteFlag::GREATER:
                conditionMet = (current->value > d);
                break;
        }

        if (conditionMet) {
            if (previous == nullptr) {
                first = current->next;
            } else {
                previous->next = current->next;
            }

            delete current;
            nodeCounter--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

Stack::Stack() {
    cout << "Stack konstruktor hívás\n";
}

Stack::~Stack() {
    cout << "Stack destruktor hívás\n";
}

void Stack::push(int e) {
    list.insertFirst(e);
}

int Stack::pop() {
    if (this->isEmpty()) {
        throw domain_error("A verem üres, nem lehet elemet kivenni!");
    }
    list.removeFirst();
}

bool Stack::isEmpty() const {
    if(list.empty() == 0) return true;
    return false
}
