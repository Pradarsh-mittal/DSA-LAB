#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node *next;
};


void push(Node** head, int ndata) {
    Node* newNode = new Node(); 
    newNode->data = ndata;       
    newNode->next = *head;       
    *head = newNode;             
}


void deleteNode(Node** head) {
    Node* temp = *head;          
    *head = (*head)->next;      
    delete temp;                 
}

void pop(Node **stack) {
    if (*stack == nullptr) {
        cout << "Underflow" << endl;
    } else {
        deleteNode(stack);
    }
}

void printStack(Node *stack) {
    Node *x = stack;
    if (x != nullptr) {
        while (x != nullptr) {
            cout << x->data << "\t";
            x = x->next;
        }
        cout << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

void peek(Node *stack) {
    if (stack != nullptr) {
        cout << "Top element: " << stack->data << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

int main() {
    Node *head = nullptr;

    for (int i = 0; i < 5; i++) {
        push(&head, i * 10);
    }
    peek(head);

    pop(&head);
    printStack(head);

    return 0;
}
