#include<iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node *link;
};
Node *front = NULL;

bool isempty(){
    if (front == NULL) return true;
    return false;
}

void enqueue(int val, int priority){
    Node *ptr, *q;
    ptr = new Node;
    ptr->data = val;
    ptr->priority = priority;

    if (front == NULL or priority < front->priority){
        ptr->link = front;
        front = ptr;
    }
    else{
        q = front;
        while(q->link != NULL and q->link->priority <= priority)
            q=q->link;
        ptr->link = q->link;
        q->link = ptr;
    }
}

void dequeue(){
    if (isempty()) cout << "Queue is empty." << endl;
    else{
        Node *ptr = front;
        front = front->link;
        delete(ptr);
    }
}

void showQueue(){
    if (isempty()) cout << "Queue is empty." << endl;
    else{
        Node *ptr = front;
        while(ptr != NULL){
            cout << ptr->priority << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }
}

int main(){
    enqueue(1, 0);
    enqueue(2, 3);
    enqueue(3, 2);
    cout<< "Queue: " << endl;
    showQueue();
    dequeue();
    cout << "Queue after removing front" << endl;
    showQueue();
}
