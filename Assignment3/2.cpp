#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* head) {
    Node* trav = head;
    int count = 0;

    while (trav != NULL) {
        trav = trav->next;
        count++;
    }

    return count;
}

void insertNode(Node** head, int val) {
    Node* trav = *head;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (trav == NULL) {
        *head = newNode;
        return;
    }

    while (trav->next != NULL) {
        trav = trav->next;
    }

    trav->next = newNode;
}

void display(Node* head) {
    Node* trav = head;

    while (trav != NULL) {
        cout << trav->data << " ";
        trav = trav->next;
    }

    cout << endl;
}


Node* add(Node* a, Node* b) {
    int n1 = countNodes(a);
    int n2 = countNodes(b);

    Node* larger = n1 > n2 ? a : b;
    Node* smaller = n1 <= n2 ? a : b;
    
    Node* travL = larger;
    Node* travS = smaller;

    Node* c = new Node();
    c->data = travL->data;
    travL = travL->next;
    

    while (travL != NULL) {
        insertNode(&c, travL->data);
        travL = travL->next;
    }

    Node* travC = c;

    while (travS != NULL) {
        travC->data = travC->data + travS->data;
        travS = travS->next;
        travC = travC->next;
    }

    return c;

}


Node* subtract(Node* a, Node* b) {
    Node* negB = b;
    Node* travB = negB;

    while (travB != NULL) {
        travB->data = -(travB->data);
        travB = travB->next;
    }

    return add(a, negB);
}

int main() {
    int d1, d2;
    Node* A = new Node();
    Node* B = new Node();

    cout << "Polynomial 1" << endl;
    cout << "Enter degree of first polynomial: ";
    cin >> d1;

    int coef;
    cout << "Enter constant (x^0) value: ";
    cin >> coef;

    A->data = coef;

    for (int i = 1; i < d1+1; i++) {
        int coef;
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coef;

        insertNode(&A, coef);
    }

    cout << endl << "Polynomial 2" << endl;
    cout << "Enter degree of second polynomial: ";
    cin >> d2;

    cout << "Enter constant (x^0) value: ";
    cin >> coef;

    B->data = coef;

    for (int i = 1; i < d2+1; i++) {
        int coef;
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coef;

        insertNode(&B, coef);
    }

    display(A);
    display(B);
    Node* C = add(A, B);
    display(C);

    Node* D = subtract(A, B);
    display(D);
}

