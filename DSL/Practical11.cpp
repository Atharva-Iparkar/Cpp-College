#include <iostream>
using namespace std;

const int MAX = 5;

class Job {
    int id;

    friend class Queue;

public:
    void getdata() {
        cout << "\nEnter Job id: ";
        cin >> id;
    }

    void putdata() {
        cout << "\n\t" << id;
    }
};

class Queue {
    int front, rear;
    Job queue[MAX];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void insert();
    void remove();
    void display();
};

bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

bool Queue::isFull() {
    return (rear == MAX - 1);
}

void Queue::insert() {
    Job j;

    if (isFull()) {
        cout << "\nQueue is Full.";
    } else {
        j.getdata();
        if (front == -1) front = 0; // Set front to 0 if inserting the first job
        rear++;
        queue[rear] = j; // Insert job at the end
        cout << "\nJob Added To Queue.";
    }
}

void Queue::remove() {
    if (isEmpty()) {
        cout << "\nQueue is Empty.";
    } else {
        cout << "\nJob " << queue[front].id << " Processed From Queue.";
        front++;
        // Reset front and rear if the queue becomes empty after removal
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void Queue::display() {
    if (isEmpty()) {
        cout << "\nQueue is Empty.";
    } else {
        cout << "\n\tJob id";
        for (int i = front; i <= rear; i++) {
            queue[i].putdata();
        }
    }
}

int main() {
    int ch;
    Queue q;

    do {
        cout << "\n\n****MENU****\n";
        cout << "1. Insert job\n";
        cout << "2. Display jobs\n";
        cout << "3. Remove job\n";
        cout << "4. Exit\n";

        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                q.insert();
                break;

            case 2:
                q.display();
                break;

            case 3:
                q.remove();
                break;

            case 4:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }
    } while (ch != 4);

    return 0;
}

