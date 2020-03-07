#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *link;
};
Node *front = NULL;
Node *rear = NULL;

bool isempty(){
    if (rear == NULL and rear == NULL) return true;
    return false;
}

void enqueue(int val){
    Node *ptr = new Node();
    ptr->data = val;
    ptr->link = ptr;

    if (rear==NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->link = ptr;
        ptr->link = front;
        rear = rear->link;
    }
}

int dequeue(){
    int val;
    if (isempty()) cout << "Queue is empty." << endl;
    else{
        Node *ptr = front;

        if (front == rear){
            val = front->data;
            front = NULL;
            rear = NULL;
            delete(ptr);
        }else{
            val = ptr->data;
            front = front->link;
            rear->link = front;
            delete(ptr);
        }
    }
    return val;
}

void showfront(){
    if (isempty()) cout << "Queue is empty." << endl;
    else cout << front->data << endl;
}

void showQueue(){
    Node *ptr = front;
    if (isempty()) cout << "Queue is empty." << endl;
    else{
        //ptr = ptr->link;
        while(ptr->link != front){
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << ptr->data;
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
    cout << "Removing front: " << dequeue() << endl;
    cout << "Queue after removing front" << endl;
    showQueue();
}
