#include <iostream>
#define MAX_SIZE 5

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int A[MAX_SIZE];

public:
    Queue()
    {
        front = rear = -1;
        len = 0;
    }

    int len;
    int size();
    bool isFull();
    bool isEmpty();
    void display();
    void enqueue(int);
    int dequeue();
};

int Queue::size() { return len; }

bool Queue::isEmpty() { return len == 0; }

bool Queue::isFull() { return len == MAX_SIZE; }

void Queue::display()
{
    if (isEmpty())
        cout << "Empty Queue" << endl;
    else
    {
        for (int i = 0; i < len; i++)
            cout << A[(front + i) % MAX_SIZE] << " ";
    }
    cout << endl;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    else if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX_SIZE;

    A[rear] = x;
    len++;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Empty Queue" << endl;
        return -1;
    }

    int x = A[front];
    front = (front + 1) % MAX_SIZE;
    len--;

    return x;
}

int main()
{
    Queue Q;

    Q.dequeue();
    Q.display();
    cout << Q.len << endl;
    cout << Q.isEmpty() << endl;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.display();

    Q.enqueue(6);
    cout << Q.dequeue() << endl;
    Q.enqueue(6);
    Q.display();
}
