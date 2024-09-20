#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};


Node* head;


Node* getNewNode(int val) {
    Node* node = new Node();
    node->data = val;
    return node;
}

void InsertAtHead(int val) {
    Node* newNode = getNewNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int val) {
    Node* newNode = getNewNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* trav = head;
    while (trav->next != NULL) {
        trav = trav->next;
    }

    trav->next = newNode;
    newNode->prev = trav;
}

void InsertAfter(int searchVal, int insertVal) {
    Node* trav = head;

    while (trav != NULL) {
        if (trav->data == searchVal) {
            if (trav->next == NULL) {
                InsertAtTail(insertVal);
                return;
            }

            Node* newNode = getNewNode(insertVal);
            Node* nextNode = trav->next;
            nextNode->prev = newNode;
            newNode->next = nextNode;
            trav->next = newNode;
            newNode->prev = trav;
            return;
        }

        trav = trav->next;
    }

    cout << "Node not found" << endl; 

}

int search(int val) {
    Node* trav = head;
    int idx = 0;

    while (trav != NULL && trav->data != val) {
        trav = trav->next;
        idx++;
    }

    if (trav->next == NULL && trav->data != val) {
        return -1;
    }
    
    return idx;
}

int countNodes() {
    Node* trav = head;
    int count = 0;

    while (trav != NULL) {
        trav = trav->next;
        count++;
    }

    return count;
}

float average() {
    Node* trav = head;
    int sum = 0, count = countNodes();

    while (trav != NULL) {
        sum += trav->data;
        trav = trav->next;
    }

    return sum / count;
}

void display() {
    Node* trav = head;

    while (trav != NULL) {
        cout << trav->data << " ";
        trav = trav->next;
    }

    cout << endl;
}

void displayReversed() {
    Node* trav = head;

    while (trav != NULL) {
        trav = trav->next;
    }

    while (trav != NULL) {
        cout << trav->data << ' ';
        trav = trav->prev;
    }

    cout << endl;
}

Node* reverseList() {
    Node* trav = head;
    Node* prev;

    while (trav != NULL) {
        prev = trav->prev;
        trav->prev = trav->next;
        trav->next = prev;
        trav = trav->prev; 
    }

    return prev->prev;
}

void deleteAtHead() {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* newHead = head->next;
    newHead->prev = NULL;
    head = newHead;
}

void deleteAtTail() {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* trav = head;

    while (trav->next != NULL) {
        trav = trav->next;
    }

    trav->prev->next = NULL;
}

void deleteNode(int val) {
    if (head == NULL) {
        cout << "Empty list" << endl;
    }

    Node* trav = head;

    while (trav->next != NULL) {
        if (trav->data == val) {
            if (trav == head) {
                deleteAtHead();
                return;
            }
            else {
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev; 
                return;
            }
        }

        trav = trav->next;
    }

    if (trav->data == val) deleteAtTail();
}

void deleteNodeAfter(int val) {
    if (head == NULL) {
        cout << "Empty list" << endl;
    }

    Node* trav = head;

    while (trav->next != NULL && trav->data != val) {
        trav = trav->next;
    }

    if (trav->next == NULL) {
        if (trav->data == val) cout << "No node after given element" << endl;
        else cout << "No such element in list" << endl;
    }

    else {
        trav->next = trav->next->next;
        trav->next->prev = trav;
    }
}

bool valFoundTwice(int val) {
    int valCount = 0;
    Node* trav = head;

    while (trav != NULL) {
        if (trav->data == val) valCount++;
        trav = trav->next;
    }

    return valCount > 1;
}

int main() {
    InsertAtHead(0);
    InsertAtHead(3);
    InsertAtTail(4);
    InsertAfter(0, 5);
    display();

    head = reverseList();
    display();

    deleteNodeAfter(4);
    display();
}
