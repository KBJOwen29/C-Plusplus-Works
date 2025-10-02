#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.display();
    list.reverse();
    list.display();




    return 0;
}
