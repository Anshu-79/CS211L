#include <iostream>
#define MAX_SIZE 101

using namespace std;

class Stack
{
private:
    int A[MAX_SIZE];

public:
    int top = -1;

    void push(int);
    int pop();
    bool isEmpty();
    void display();
};

void Stack::push(int x)
{
    if (top == MAX_SIZE - 1)
        cout << "Error: Stack overflow" << endl;
    else
        A[++top] = x;
}

int Stack::pop()
{
    if (top == -1)
        cout << "Error: Empty stack" << endl;
    else
        top--;
}

bool Stack::isEmpty()
{
    return top == -1;
}

void Stack::display()
{
    if (isEmpty())
        cout << "Empty stack" << endl;
    else
    {
        for (int i = top; i > -1; i--)
            cout << A[i] << endl;
    }
}

int main()
{
    Stack s;

    s.push(1);
    s.push(3);
    s.push(2);
    s.pop();
    s.display();
}
