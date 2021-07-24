#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size = 1000;
    int data[1000];
public:
    Queue();
    ~Queue();
    bool isFull();
    bool isEmpty();
    int peek();
    void enqueue(int);
    void dequeue(int&);
};

bool Queue::isEmpty() {
    return (front < 0 || front > rear) ? true : false;
}
bool Queue::isFull() {
    return rear == size - 1 ? true : false;
}
void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "Hang doi da day!" << endl;
        return;
    }
    rear++;
    data[rear] = item;
}
void Queue::dequeue(int &x) {
    if (isEmpty()) {
        cout << "Hang doi rong" << endl;
        return;
    }
    data[front] = 0;
    front++;
}
int Queue::peek() {
    int x = this->data[1];
    return x;
}

int main() {
    Queue q;
    q.enqueue(3);
    int x;
    q.dequeue(x);
    cout << "Hang doi co x = " << x;
}