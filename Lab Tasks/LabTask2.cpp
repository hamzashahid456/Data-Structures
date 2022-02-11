#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
    Node *prev;
};

class Link{
    private:
    Node *head, *curr, *ptr;
    int length;

    public:
    void options();
    Link();
    void add();
    void del(int);
    void print(); 
    bool emptiness();
};


Link::Link(){
        head = curr = ptr = NULL;
        length = 0;
}

void Link::add(){
    curr = head;
    if(head == NULL){
        Node *nw = new Node;
        head = nw;
        cout<<"Enter First value : ";cin>>head->data;
        head->next = head;
        head->prev = head;
        nw = NULL;
        return;
    }
   while (curr->next != head)
    {
        curr = curr->next;
    }

    Node *nw = new Node;
    nw->prev = curr;
    nw->next = head;
    curr->next = nw;  
    curr = nw;      
    cout<<"Enter next value : ";cin>>curr->data;
    head->prev = nw;
    nw = NULL;
    length ++;
}

void Link::print(){
    curr = head;
    if(head == NULL){
        cout<<"empty list"<<endl;
        return;
    }
    while (curr->next != head)
    {
        cout<<curr->data<<" , ";
        curr = curr->next;
    }
    cout<<curr->data;
    cout<<endl;

}

void Link::del(int v){
    curr = head;
    ptr = curr;
    
    if(head == NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    cout<<"Enter value to delete : "; cin>>v;
    if(v == head->data){

        if(head->next == head){

            delete head;
            head = nullptr;
            return;
        }
        head = head->next;
        curr = head;
        curr->prev = ptr->prev;
        ptr->prev->next = head;
        delete ptr;
        return;
    }
    

    while(curr ->data != v){
        curr = curr->next;
    }

    
    
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    delete curr;
    
    curr = nullptr;
    
    
    
}


bool Link::emptiness(){
    if(head == NULL){
        return true;
    }
    else{return false;}
}


void Link::options(){
    cout<<"Press A to Enter next value "<<endl;
    cout<<"Press D to Delete value "<<endl;
    cout<<"Press P to Print List "<<endl;
}


int main(){
    int P, v, s,d;
    char o;
    Link list;
    list.options();
    while(true){
        cout<<"Enter your choice : ";cin>>o;
        if(o == 'x'){break;}
        else if(o == 'a'){list.add();}
        else if(o == 'p'){list.print();}
        else if(o == 'c'){list.emptiness();}
        else if(o == 'd'){list.del(d);}
    }

    return 0;
}
