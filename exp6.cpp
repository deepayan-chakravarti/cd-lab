#include <iostream>

using namespace std;

const int MAX = 5;

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " inserted\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        cout << arr[top] << " deleted\n";
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    cout << "Deepayan Chakravarti" <<endl;
    cout << "04714802724" <<endl;
    Stack s;

    cout << (s.isEmpty() ? "true" : "false") << "\n";
    cout << (s.isFull() ? "true" : "false") << "\n\n";

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.push(60);

    cout << (s.isFull() ? "true" : "false") << "\n";
    cout << (s.isEmpty() ? "true" : "false") << "\n";
    cout << "Current stack size: " << s.size() << "\n";
    cout << "Top element (peek): " << s.peek() << "\n\n";

    s.display();

    s.pop();
    s.pop();

    s.display();
    cout << "New top element: " << s.peek() << "\n";
    cout << "New stack size: " << s.size() << "\n\n";

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout << (s.isEmpty() ? "true" : "false") << "\n";

    return 0;
}