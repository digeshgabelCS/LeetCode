#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q1.pop();

        swap(q1, q2);

        return topElement;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();

        q2.push(topElement);
        q1.pop();

        swap(q1, q2);

        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* stack = new MyStack();

    stack->push(10);
    stack->push(20);
    stack->push(30);

    cout << "Top element: " << stack->top() << endl;   
    cout << "Popped: " << stack->pop() << endl;        
    cout << "Top element: " << stack->top() << endl;   
    cout << "Popped: " << stack->pop() << endl;       
    cout << "Is empty? " << (stack->empty() ? "Yes" : "No") << endl;
    cout << "Popped: " << stack->pop() << endl;        
    cout << "Is empty? " << (stack->empty() ? "Yes" : "No") << endl; 

    delete stack;
    return 0;
}