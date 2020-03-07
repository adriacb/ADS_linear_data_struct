#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *link;
};
Node *front = NULL;
Node *rear = NULL;

bool isempty(){
    if (front == NULL and rear == NULL) return true;
    return false;
}

void enqueue(int val){
    Node *ptr = new Node();
    ptr->data = val;
    ptr->link = NULL;

    if (front == NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->link = ptr;
        rear = ptr;
    }
}

void dequeue(){
    if (isempty()) cout << "Queue is empty." << endl;
    else{
        if (front == rear){
            delete(front);
            front = rear = NULL;
        }
        else{
            Node *ptr = front;
            front = front->link;
            delete(ptr);
        }
    }
}

void showfront(){
    if (isempty()) cout << "Queue is empty." << endl;
    else cout << front->data << endl;
}

void showQueue(){
    if (isempty()) cout << "Queue is empty." << endl;
    else{
        Node *ptr = front;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }
}

int main(){
    enqueue(1);
    cout << "The front element: " << endl;
    showfront();
    enqueue(2);
    enqueue(3);
    cout<< "Queue: " << endl;
    showQueue();
    dequeue();
    cout << "Queue after removing front" << endl;
    showQueue();
}
