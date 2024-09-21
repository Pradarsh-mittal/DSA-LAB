#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char **stack;  
int top = -1;
int size = 0;


void createStack(int isize) {
    size = isize;
    stack = new char*[size];  
    if (!stack) {
        exit(0);
    }
}


bool isfull() {
    return (top == size - 1);
}

bool isempty() {
    return (top == -1);
}

void resizeStack() {
    size = size * 2;
    stack = (char **)realloc(stack, size * sizeof(char *));
    if (!stack) {
        exit(0);
    }
}

void push(const char val[]) {
    if (isfull()) {
        resizeStack();
    } else {
        top = top + 1;
        stack[top] = new char[strlen(val) + 1]; 
        strcpy(stack[top], val);  
        cout << "\n '" << val << "' is Successfully added \n";
    }
}


void pop() {
    if (isempty()) {
        cout << "\n Book not Found! \n";
    } else {
        cout << "\n '" << stack[top] << "' is Successfully Provided! \n";
        delete[] stack[top];  
        top = top - 1;
    }
}

void peek() {
    if (!isempty()) {
        cout << stack[top] << endl;
    } else {
        cout << "No books available!\n";
    }
}

void show() {
    if (!isempty()) {
        cout << "Books are: \n";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << endl;
        }
    } else {
        cout << "No books in the shelf!\n";
    }
}

int main() {
    createStack(4);

    cout << "****************************************************\n";
    cout << "1. Add a returned Book\n";
    cout << "2. Remove a returned Book\n";
    cout << "3. View the top returned Book\n";
    cout << "4. View all the books\n";
    cout << "5. Exit\n";

    char name[200];
    while (true) {
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter the book name: ";
                cin.getline(name, 200);
                push(name);
                break;

            case 2:
                pop();
                break;

            case 3:
                cout << "The recent book is: \n";
                peek();
                break;

            case 4:
                show();
                break;

            case 5:
                cout << "Thank you for your visit!\n";
                exit(0);

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "****************************************************\n";
    }

    return 0;
}
