#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp1;
    int exp2;
    Term* next;
};

class Polynomial {
    Term* head;

public:
    Polynomial() {
        head = new Term;
        head->next = nullptr;
    }

    void insertTerm(int c, int e1, int e2) {
        Term* newTerm = new Term{c, e1, e2, nullptr};
        Term* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }

    void add(Polynomial& p) {
        Term* p1 = head->next;
        Term* p2 = p.head->next;
        Polynomial result;
        while (p1 && p2) {
            if (p1->exp1 == p2->exp1 && p1->exp2 == p2->exp2) {
                result.insertTerm(p1->coeff + p2->coeff, p1->exp1, p1->exp2);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exp1 > p2->exp1 || (p1->exp1 == p2->exp1 && p1->exp2 > p2->exp2)) {
                result.insertTerm(p1->coeff, p1->exp1, p1->exp2);
                p1 = p1->next;
            } else {
                result.insertTerm(p2->coeff, p2->exp1, p2->exp2);
                p2 = p2->next;
            }
        }
        while (p1) {
            result.insertTerm(p1->coeff, p1->exp1, p1->exp2);
            p1 = p1->next;
        }
        while (p2) {
            result.insertTerm(p2->coeff, p2->exp1, p2->exp2);
            p2 = p2->next;
        }
        display();
        result.display();
    }

    void display() {
        Term* temp = head->next;
        while (temp) {
            cout << temp->coeff << "x^" << temp->exp1 << "y^" << temp->exp2;
            if (temp->next) {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1, p2;
    p1.insertTerm(3, 2, 1);
    p1.insertTerm(4, 1, 0);
    p2.insertTerm(5, 2, 1);
    p2.insertTerm(2, 1, 0);
    p1.add(p2);
    return 0;
}
