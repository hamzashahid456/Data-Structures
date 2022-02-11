// 20P-0484 Muhammad Faizan

#include<iostream>
using namespace std;

class Stack{
    private:
    int size;
    int *stk;
    int *top;

    public:
    Stack();
    void push(int);
    void pop();
    void print();
};

Stack::Stack(){
    size = 5;
    top = NULL;
    stk = new int[size];
}

void Stack::push(int x){
    if(top == NULL){
        top = stk;
        *top = x;
        top++;
        return;
    }
    if(top == stk+size){
        cout<<"Over Flow"<<endl;
        return;
    }
    *top = x;
    top++;
}


void Stack::pop(){
    if(stk == NULL){
        cout<<"Under Flow";
    }
    top = NULL;
}

void Stack::print(){
   // top = stk+(size-1);
    if(top == NULL){
        cout<<"Empty Stack";
        return;
    }
    while(top != NULL){
        cout<<*top;
        Stack::pop();
        top--;
    }   
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
    cout<<endl;
    s.print();
}
