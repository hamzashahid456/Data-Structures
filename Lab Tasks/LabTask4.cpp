#include<iostream>
using namespace std;

class Queue{
    private:
    int size;
    int *que;
    int *fron;
    int *rear;

    public:
    Queue();
    void enqueue(int);
    void dequeue();
    void print();
};

Queue::Queue(){
    size = 5;
    fron = NULL;
    rear = NULL;
    que = new int[size];
  
}

void Queue::enqueue(int i){
    if(rear == NULL || *rear == 0){
        fron = que;
        rear = fron;
        *rear = i;
        return;
    }
    if(rear == que + (size - 1) && *que == 0){
        rear = que;
        *rear = i;
        return;
    }
    if(rear == que + (size - 1) && fron == que || rear + 1 == fron){
        cout<<"No empty space "<<endl;
        return;
    }
    rear++;
    *rear = i;
}

void Queue::dequeue(){
    if(fron = rear){
        *fron = NULL;
        *rear = NULL;
        return;
    }
    if(rear == fron + 1){
        fron++;
    }
    if(rear == NULL){
        cout<<"Under Flow "<<endl;
        return;
    }
    if(fron == que + (size-1)){
        fron = que;
    }
    fron++;
}

void Queue::print(){
    int *pri;
    pri = fron;
    if(rear == NULL){
        cout<<"Empty List "<<endl;
    }
    while(pri != rear){
        cout<<*pri<<" , ";
        if(pri == que + (size - 1)){
            pri = que;
        }
        else{
            pri++;
        }
        if(pri == rear){
            cout<<*pri<<endl;
        }   
    }
    
}



int main(){
    Queue q;
    q.dequeue();
    q.enqueue(1);
    q.dequeue();
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.enqueue(8);
    q.print();
}
