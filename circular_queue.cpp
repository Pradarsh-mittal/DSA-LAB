#include <iostream>
using namespace std;

int front = -1;
int rear = -1;
int queue[10];
int size = sizeof(queue) / sizeof(queue[0]);

void enqueue(int val) {
    if ((rear + 1) % size == front) {
        cout << "Overflow" << endl;
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = val;
    } else {
        rear = (rear + 1) % size;
        queue[rear] = val;
    }
}


int dequeue() {
    int ele;

    if (front == -1 && rear == -1) {
        cout << "Underflow!!!!!" << endl;
        return -1;
    }
    if (front == rear) {
        ele = queue[front];
        front = -1;
        rear = -1;
        cout << "The deleted element is: " << ele << endl;
        return ele;
    } else {
        ele = queue[front];
        cout << "The deleted element is: " << ele << endl;
        front = (front + 1) % size;
        return ele;
    }
}

void show() {
    cout << "The elements in the queue are: \n";

    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << "\t";
        } else {
            for (int i = front; i < size; i++)
                cout << queue[i] << "\t";
 
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << "\t";
        }
        cout << endl;
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        enqueue(i * 3);
    }
    show();
    cout << "Front = " << front << endl;
    cout << "Rear = " << rear << endl;

    for (int i = 1; i <= 10; i++) {
        cout << i << ": ";
        dequeue();
    }

    enqueue(6);
    cout << "Front = " << front << endl;
    cout << "Rear = " << rear << endl;
    show();
    cout << "Front = " << front << endl;
    cout << "Rear = " << rear << endl;

    dequeue();
    cout << "Front = " << front << endl;
    cout << "Rear = " << rear << endl;
    show();

    return 0;
}
