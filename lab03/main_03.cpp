#include <iostream>
#include "List.h"
using namespace  std;
int main() {
    List l1;
    cout<<l1.size();
    for (int i = 0; i < 10; ++i) {
        l1.insertFirst(i);
    }
    l1.print();
    l1.size();
    l1.remove();
    return 0;
}
