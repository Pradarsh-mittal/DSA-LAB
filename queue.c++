#include <iostream>
using namespace std;

long front = -1;
long rear = -1;
long queue[5];
long size = 5;

long is_full() {
    if (rear == size - 1) {
        return 1;
    } else {
        return 0;
    }
}

long is_empty() {
    if (front == -1 || (front > rear)) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(long val) {
    if (is_full()) {
        cout << "Overflow\n";
    } else {
        rear = rear + 1;
        queue[rear] = val;
        if (front == -1) {
            front = 0;
        }
    }
}

long dequeue() {
    if (is_empty()) {
        cout << "Underflow\n";
        return -1;
    } else {
        long ele = queue[front];
        cout << "The deleted element is: " << ele << endl;
        front = front + 1;
        return ele;
    }
}

void peek() {
    if (front == -1) {
        cout << "Queue is empty\n";
    } else {
        cout << "The peek element is: " << queue[front] << endl;
    }
}

void show() {
    cout << "The elements in queue are: \n";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << "\t";
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 5; i++) {
        enqueue(i * 3);
    }
    dequeue();
    dequeue();
    peek();
    show();

    return 0;
}
