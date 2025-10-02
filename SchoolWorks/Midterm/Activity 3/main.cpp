#include <iostream>
using namespace std;
#include "queue.h"


int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.enqueue(60);  // Queue is full

    q.display();

    cout << "Front element (peek): " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    cout << "Is the queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
