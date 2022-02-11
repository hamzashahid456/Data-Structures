#include<iostream>
#include<string>
using  namespace std;

class list{
private:
    int *arr; //will be used to initialize an empty list and will always point to the first position.
    int size; //total capcity of the list
    int len; //number of current elements in the list
    int *current; //pointer to point the current position
    int *temp; //can be used for temporary works
    int myList[3] = {1,2,3};
public:
list(){
    len = 3;
    size = 0;
    current = temp = NULL;
    arr = myList;
}

list(int userSize){
    size = userSize;
    myList[size];
}

list(list& othrList){
    //int newList[] = myList[size];
}

void clear(){
    current = arr;
    if(len == 0){
        cout<<"Invalid action";
        return;
    }
    while (*current != -999)
    {
        current = NULL;
        current++;
    }
}


//Insert a Value at Specific Position
void insert(int value,int pos){
    current = arr;
    temp = current;
    if(pos <= len){
        len++;
        size++;
    }
    if(pos >= len+2){
        cout<<"Invalid position ";
        return;
    }
    else if(pos < 0){
        cout<<"Inavlid Position ";
        return;
    }
    for(int i = 1; i<=len+1; i++){
        temp++;
        current++;
    }
    while(current != (arr + pos)){
        *(current + 1) = *current;
        *(temp - 1) = *temp;
        current--;
        temp--;
    }
       *current = value;
}

void print(){
    current = arr;
    for(int i = 0; i <= len; i++){
        cout<<*current<<" ,";
        current++;
    }
}

void remove(int pos){
    if(len == 0){
        cout<<"Empty list";
    }
    for(int i = 0; i <= len; i++){
        current++;
    }
}

void start(){
    current = arr;
}

void update(int value,int pos){
    current = arr;
    for(int i = 0; i<=len; i++){
        current++;
    }
    *current = value;
}

int length(){
    current = arr;
    int x = 0;
    while (current != NULL)
    {
        x++;
    }
    current++;
    cout<<"length is "<<x<<endl;
    return len;
}

void insert(int value){
    current = arr;
    if(len == 0){
        *current = value;
        len++;
    }
    for(int i = 0; i <=len+1 ; i++){
        current++;
    }
    *current = value;
    len++;
}

void end(){
    current = arr;
    while (current != NULL)
    {
        current++;
    }
    
}
bool find(int value){
    current = arr;
    while (current != NULL)
    {
        current++;
        if(*current == value){
            break;
            return true;
        }
        else{
            return false;
        }
    }
}

};


int main(){
    list l;
    list(5);
    l.insert(2);
    l.insert(9,1);
  //  l.length();
    l.print();
    return 0;
}

