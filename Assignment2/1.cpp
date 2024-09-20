#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node** head, int val) {
    Node* temp = new Node();
    temp->data = val;

    temp->next = *head;
    *head = temp;
}

void removeAtHead(Node** head) {
    Node* next = *head;
    next = next->next;
    *head = next;
}

void insertAtTail(Node** head, int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    Node* trav = *head;

    while (trav->next != NULL) {
        trav = trav->next;
    }

    trav->next = temp;
}

void removeAtTail(Node** head) {
    Node* trav = *head;

    while (trav->next->next != NULL) {
        trav = trav->next;
    }

    trav->next = NULL;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertNodeAfter(Node** head, int searchVal, int insertVal) {
    Node* trav = *head;
    Node* insertedNode = new Node();
    insertedNode->data = insertVal;

    while (trav->data != searchVal) {
        trav = trav->next;
    }

    insertedNode->next = trav->next;
    trav->next = insertedNode;
}

void deleteNode(Node** head, int val) {
    Node* trav = *head;

    if (trav->data == val) {
        removeAtHead(head);
        return;
    }

    while (trav->next != NULL && trav->next->data != val) {
        trav = trav->next;
    }

    if (trav->next == NULL) {
        if (trav->data == val) removeAtTail(head);
        else cout << "No such element in list" << endl; 
    } else {
        trav->next = trav->next->next;
    }
}

void deleteNodeAfter(Node** head, int val) {
    Node* trav = *head;

    while (trav->next != NULL && trav->data != val) {
        trav = trav->next;
    }

    if (trav->next == NULL) {
        if (trav->data == val) cout << "No node after given element" << endl;
        else cout << "No such element in list" << endl;
    }
    else trav->next = trav->next->next;
}


int search(Node* head, int val) {
    int i = 0;
    Node* trav = head;

    while (trav->data != val) {
        i++;
        trav = trav->next;
    }
    
    return i;
}

int countNodes(Node* head) {
    Node* trav = head;
    int count = 0;

    while (trav != NULL) {
        count++;
        trav = trav->next;
    }

    return count;
}

float average(Node* head) {
    Node* trav = head;
    int sum = 0, count = countNodes(head);

    while (trav != NULL) {
        sum += trav->data;
        trav = trav->next;
    }

    return sum / count;
}

void displayReversed(Node* head) {
    Node* trav = head;

    if (trav == NULL) return;
    
    displayReversed(trav->next);

    cout << trav->data << " ";
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* trav = head;
    Node* next;

    while (trav != NULL) {
        next = trav->next;
        trav->next = prev;
        prev = trav;
        trav = next;
    }
    head = prev;
    return head;
}

bool valFoundTwice(Node* head, int val) {
    int valCount = 0;
    Node* trav = head;

    while (trav != NULL) {
        if (trav->data == val) valCount++;
        trav = trav->next;
    }

    return valCount > 1;
}

int main() {
    Node* head = new Node();
    head->data = 0;

    display(head);
    
    insertAtHead(&head, 3);
    display(head);
    
    insertAtTail(&head, 4);
    display(head);

    insertNodeAfter(&head, 0, 5);
    display(head);

    int idx = search(head, 5);
    cout << "First occurence of " << 5 << " is at index " << idx << endl;

    int avg = average(head);
    cout << "Average: " << avg << endl;

    displayReversed(head);
    cout << endl;

    head = reverse(head);
    display(head);

    removeAtHead(&head);
    display(head);

    removeAtTail(&head);
    display(head);

    deleteNode(&head, 0);
    display(head);

    insertAtHead(&head, 3);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    display(head);

    deleteNodeAfter(&head, 3);
    display(head);

    insertAtHead(&head, 1);
    display(head);

    cout << valFoundTwice(head, 2) << endl;


}
