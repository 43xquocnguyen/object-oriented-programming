#include "queue.h"
#include <vector>

void MENU(Queue *queue) {
    while (true)
    {
        system("cls");
        cout << "PROGRAM ENQUEUE & DEQUEUE (QUEUE)\n\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. DEQUEUE ALL\n\n";
        cout << "YOUR CHOOSE: ";

        char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

        if (choose == '1') {
            int x;
            cout << "ENQUEUE: ";
            cin >> x;
            Node *p = new Node(x);
            queue->enQueue(p);
        }
        else if (choose == '2') {
            int x;
            if (queue->deQueue(x)) {
                cout << "DEQUEUE: " << x << endl;
            }
            else cout << "EMPTY QUEUE\n";
        }
        else if (choose == '3') {
            int i = 0;
            while (true)
            {
                int x;
                if (queue->deQueue(x)) {
                    cout << "DEQUEUE " << i + 1 << ": " << x << endl;
                    i++;
                }
                else break;
            }
            if (!i) cout << "EMPTY QUEUE\n";
        }
        else {
            cout << "NOT FOUND OPTION!\n";
        }
        system("pause");
    }
    delete queue;
}
int main() {
    Queue *queue = new Queue;
    MENU(queue);
    delete queue;
    return 0;
}