#include <iostream>
#include <cmath>
#include "Stack.h"
using namespace std;

void printMove(int disk, char fromRod, char toRod) {
    cout << "Move disk " << disk << " from " << fromRod << " to " << toRod << endl;
}

void moveDisk(Stack& fromRod, Stack& toRod, char from, char to) {
    if (fromRod.isEmpty()) {
        int disk = toRod.pop();
        fromRod.push(disk);
        printMove(disk, to, from);
    } else if (toRod.isEmpty()) {
        int disk = fromRod.pop();
        toRod.push(disk);
        printMove(disk, from, to);
    } else if (fromRod.peek() > toRod.peek()) {
        int disk = toRod.pop();
        fromRod.push(disk);
        printMove(disk, to, from);
    } else {
        int disk = fromRod.pop();
        toRod.push(disk);
        printMove(disk, from, to);
    }
}

void showTowers(Stack& source, Stack& aux, Stack& des , int num) {
    int s, a, d;
    for (int i = num; i > 0; i--) {
        s = source.showIdex(i-1) == -1 ? 0 : source.showIdex(i-1);
        a = aux.showIdex(i-1) == -1 ? 0 : aux.showIdex(i-1);
        d = des.showIdex(i-1) == -1 ? 0 : des.showIdex(i-1);

        if (num % 2 == 0) {
            cout << "   "<< i << "|\t" << s << "\t" << d << "\t   " << a << endl;
        } else {
            cout << "   "<< i << "|\t" << s << "\t" << a << "\t   " << d << endl;
        }

    }
    cout << "Stack|\t"<< "Source\t" << "Auxiliary  " << "Destination\n" << endl;
}

int main() {
    int numDisks ;  // Number of disks

    cout << "Enter the number of disks: ";
    cin >> numDisks;

    Stack source(numDisks), auxiliary(numDisks), destination(numDisks);
    char s = 'S', a = 'A', d = 'D';
    int totalMoves = (1 << numDisks) - 1;  // Total moves: 2^n - 1

    if (numDisks % 2 == 0) swap(a, d);

    for (int i = numDisks; i >= 1; i--)
        source.push(i);

    cout << "The sequence of moves involved in the Tower of Hanoi are: " << endl;

    for (int i = 1; i <= totalMoves; i++) {
        showTowers(source, auxiliary, destination, numDisks);
        if (i % 3 == 1) 
            moveDisk(source, destination, s, d);
        else if (i % 3 == 2) 
            moveDisk(source, auxiliary, s, a);
        else 
            moveDisk(auxiliary, destination, a, d);
    }
    showTowers(source, auxiliary, destination, numDisks);

    return 0;
}
