#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* createNode(int new_data) {
    Node *new_node = new Node;
    if (!new_node) {
        cout << "Memory is not allocated" << endl;
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = nullptr;
    return new_node;
}

void print(Node *n) {
    while (n != nullptr) {
        cout << n->data << endl;
        n = n->next;
    }
}

Node* reverseList(Node* head) {
    Node* arr[10000];
    int top = -1;
    Node* x = head;
    while (x != nullptr) {
        arr[++top] = x;
        x = x->next;
    }
    if (top >= 0) {
        head = arr[top];
        x = head;
        while (top > 0) {
            top--;
            x->next = arr[top];
            x = x->next;
        }
        x->next = nullptr;
    }
    return head;
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    print(head);
    head = reverseList(head);
    print(head);

    return 0;
}
