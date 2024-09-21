#include <iostream>
using namespace std;

int top = -1;
int top1 = 10;
const int max = 10;

void push(int arr[], int n, int s) {
    if (top1 - top > 1) {
        top = top + 1;
        arr[top] = n;
    } else {
        cout << "Overflow" << endl;
    }
}

void push1(int arr[], int n, int s) {
    if (top1 - top > 1) {
        top1 = top1 - 1;
        arr[top1] = n;
    } else {
        cout << "Underflow" << endl;
    }
}

int main() {
    int arr[10] = {0};  

    push(arr, 1, 10);
    push(arr, 23, 10);
    push(arr, 13, 10);
    push(arr, 33, 10);
    push(arr, 43, 10);

    push1(arr, 2, 10);
    push1(arr, 22, 10);
    push1(arr, 25, 10);
    push1(arr, 21, 10);
    push1(arr, 211, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
