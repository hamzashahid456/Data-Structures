// 20P-0484 Muhammad Faizan

#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next = NULL;
};
class Stack{
    private:
    Node *start;
    Node *top;
    Node *temp;

    public:
    Stack();
    void push(int);
    void pop();
    void print();
};

Stack::Stack(){
    start = top = temp = NULL;
}

void Stack::push(int x){
    if(start == NULL){
        Node *nw = new Node;
        nw->data = x;
        start = nw;
        top = start;
        start->next = top;
        return;
    }
    Node *nw = new Node;
    nw->data = x;
    nw->next = top;
    top = nw;
}

void Stack::pop(){
    if(start == NULL){
        cout<<"Underflow ";
        return;
    }
    temp = top;
    top = top->next;
    delete temp;
}


void Stack::print(){
    while(top != start){
        cout << top->data <<" , ";
        Stack::pop();        
    }
    temp = top;
    cout<<top->data;
    Stack::pop();
}


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.print();
    s.pop();
}


