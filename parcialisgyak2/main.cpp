#include <iostream>
using namespace std;
#include "ListList.h"
int main() {
    ListList list1("input.txt");
    cout << "list1:"<<list1<<endl;
    ListList list2;
    for (int i = 10; i <15 ; ++i) {
        list2.instertLast(i);
    }
    cout<< "list2:"<<list2<<endl;
    ListList list3 = list1+list2;
    cout<< "List list3 = list1+list2:"<<list3<<endl;
    ListList list4;
    list4 = list1;
    cout<< "List list4 = list1:"<<list4<<endl;
    ListList list5 = move(list2+list1);
    cout<< "List list5 = move(list2+list1):"<<list5<<endl;
    ListList list6;
    list6 = (list1+list1);
    cout << "List list6 = (list1+list1):" << list6 << endl;
    return 0;
}
