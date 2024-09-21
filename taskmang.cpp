#include <iostream>
#include <string>

using namespace std;

struct Task {
    int id;
    string description;
    string status;
    Task* next;
};

class TaskManager {
    Task* head;
    int nextId;

public:
    TaskManager() {
        head = nullptr;
        nextId = 1;
    }

    void addTask(const string& description) {
        Task* newTask = new Task{nextId++, description, "Pending", nullptr};
        if (!head) {
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newTask;
        }
    }

    void removeTask(int id) {
        Task* temp = head;
        Task* prev = nullptr;
        while (temp && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
        }
    }

    void markTaskAsCompleted(int id) {
        Task* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->status = "Completed";
                break;
            }
            temp = temp->next;
        }
    }

    void displayTasks() {
        Task* temp = head;
        while (temp) {
            cout << "Task ID: " << temp->id << ", Description: " << temp->description << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TaskManager tm;
    tm.addTask("Task 1");
    tm.addTask("Task 2");
    tm.displayTasks();
    tm.markTaskAsCompleted(1);
    tm.displayTasks();
    tm.removeTask(1);
    tm.displayTasks();
    return 0;
}
