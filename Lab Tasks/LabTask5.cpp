// #include <iostream>
// using namespace std;

// struct BT
// {
//     BT *left, *right;
//     int value;
//     BT(int value)
//     {
//         this->value = value;
//         this->left = this->right = nullptr;
//     }
// };

// class BST
// {
// private:
//     BT *root;
//     void Insert(int value, BT *&temp)
//     {
//         if (temp == nullptr)
//         {
//             temp = new BT(value);
//             return;
//         }
//         else
//         {
//             if (value == temp->value)
//             {
//                 return;
//             }
//             else if (value > temp->value)
//             {
//                 Insert(value, temp->right);
//             }
//             else
//             {
//                 Insert(value, temp->left);
//             }
//         }
//     }

//     BT *Search(int value, BT *&temp)
//     {
//         if (temp == nullptr)
//         {
//             cout << "value not found\n";
//             return nullptr;
//         }
//         else if (temp->value == value)
//         {
//             return temp;
//         }
//         else if (temp->value < value)
//         {
//             return Search(value, temp->right);
//         }
//         else if (temp->value > value)
//         {
//             return Search(value, temp->left);
//         }
//         return nullptr;
//     }

//     BT *Successor(int value, BT *temp, BT *succ = nullptr)
//     {
//         if (temp == nullptr)
//         {
//             return succ;
//         }
//         else if (value < temp->value)
//         {
//             succ = temp;
//             return Successor(value, temp->left, succ);
//         }
//         else if (value > temp->value)
//         {
//             return Successor(value, temp->right, succ);
//         }
//         else
//         {
//             return Successor(value, temp->right, succ);
//         }
//     }

//     BT *Predecessor(int value, BT *temp, BT *pred = 0)
//     {
//         if (temp == nullptr)
//         {
//             return pred;
//         }
//         else if (value < temp->value)
//         {
//             return Predecessor(value, temp->left, pred);
//         }
//         else if (value > temp->value)
//         {
//             pred = temp;
//             return Predecessor(value, temp->right, pred);
//         }
//         else
//         {
//             return Predecessor(value, temp->left, pred);
//         }
//     }

// public:
//     BST()
//     {
//         root = nullptr;
//     }
//     void insert(int value)
//     {
//         Insert(value, root);
//     }
//     BT *search(int value)
//     {
//         return Search(value, root);
//     }
//     void successor(int value)
//     {
//         if (search(value) != nullptr)
//         {
//             BT *result = Successor(value, root);
//             if (result == nullptr)
//             {
//                 cout << "no successor found\n";
//             }
//             else
//             {

//                 cout << result->value << endl;
//             }
//         }
//     }
//     void predecessor(int value)
//     {
//         if (search(value) != nullptr)
//         {
//             BT *result = Predecessor(value, root);
//             if (result == nullptr)
//             {
//                 cout << "no predecessor found\n";
//             }
//             else
//             {

//                 cout << result->value << endl;
//             }
//         }
//     }
// };

// int main()
// {
//     BST a;
//     a.insert(10);
//     a.insert(5);
//     a.insert(20);
//     a.insert(6);
//     a.insert(2);
//     a.insert(15);
//     a.insert(30);
//     a.insert(25);
//     a.insert(24);
//     a.insert(21);
//     a.insert(31);
//     // a.successor(5);
//     // a.successor(6);
//     a.successor(10);
//     // a.successor(2);
//     // a.successor(15);
//     a.successor(20);
//     a.successor(30);
//    cout<<endl;
//     a.predecessor(10);
//     a.predecessor(20);
//     a.predecessor(30);
//     // a.predecessor(15);
//     // a.predecessor(5);
//     // a.predecessor(6);
//     // a.predecessor(2);

// }



























#include<iostream>
using namespace std;


struct Node{
    int val;
    Node *right = NULL;
    Node *left = NULL;
};
// ROOT PRIVATE MAKE GETTER FUNC FOR ROOT, CALL THAT FUNC INTO MAIN
class BST{
    public:
        Node * par;
        Node *root ;
        Node * search(int, Node *&);
        Node * suc(int);
        Node * pre(int, Node *);
        Node * del(int, Node *);
        void get_root(Node *&);
        void insert(int, Node *&);
        void preorder(Node *);
        void postorder(Node *);
        void inorder(Node *);
        
        BST();
};

BST::BST(){
    root = NULL;
    int *temp = NULL;
}

void BST::insert(int key, Node *& temp){
    if(temp==NULL){
        temp = new Node();
        temp->val = key;
        return;
    }
    if(temp->val == key){
        cout<<"KEY ALREADY EXISTS "<<endl;
        return;
    }
    if(key>temp->val){
        insert(key, temp->right);
    }
    if(key<temp->val){
        insert(key, temp->left);
    }
}




Node * BST::search(int key, Node *&temp){
    if(temp == NULL)
    {
        cout<<"Empty Tree";
        return NULL;
    }
    if(key == temp->val)
    {   
        cout<<"Key found"<<endl; 
        return temp;
    }

    if(key < temp->val){
      if(temp->left != NULL)
      {
        return search(key, temp->left);
      }
      else
      {
        cout<<"key not found"<<endl; 
        return NULL;
      }
    }
    if(key > temp->val){
      if(temp->right != NULL){
          
          return search(key, temp->right);
        }
      else
      {
        // cout<<"key not found"<<endl;
        return NULL;
      }
    }
}

void BST::preorder(Node *temp){
    cout<<temp->val<<" ,";
    if(temp->left != NULL){
        preorder(temp->left);}
    
    if(temp->right != NULL){
        preorder(temp->right);}
}

void BST::postorder(Node *temp){
    if(temp->left != NULL){
        postorder(temp->left);}
    
    if(temp->right != NULL){
        postorder(temp->right);}
        
    cout<<temp->val<<" ,";
}

void BST::inorder(Node *temp){
    if(temp->left != NULL){
        inorder(temp->left);
    }
    cout<<temp->val<<" ,";
    if(temp->right != NULL){
        inorder(temp->right);
    }
        
}

Node * BST::suc(int key){
    Node *temp2;
    Node *temp = search(key, root);
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->right != NULL){
        temp2 = temp->right;
        while(temp2->left != NULL)
        {
            temp2 = temp2->left;  
        }
        cout<<temp2->val;
        return temp2;
    }
}




Node * BST::pre(int key, Node * temp){
    Node * temp2;
    if(temp == NULL){
        return nullptr;
    }    
    if(key == temp->val){
        temp2 = temp->left;
        while(temp2->right){
            temp2 = temp2->right;
        }
        cout<<temp2->val<<endl;
        return temp2;
    }
    else if(key>temp->val){
        temp2 = temp;
        pre(key,temp->right);
    }
}

Node * BST::del(int key, Node *temp){
    if(root == NULL){
        return 0;
    }
    if(temp->val == key){
        if(temp->left == temp->right == NULL){
            delete temp;
        }
        if(temp->left == temp->right != NULL){
            Node *temp2 = suc(key);
            temp = temp2;
            delete temp2;
        }
        if(temp->right != NULL ){

        }
    }
}



int main(){
    BST b;
    b.insert(100, b.root);
    b.insert(70, b.root);
    b.insert(200, b.root);
    b.insert(1, b.root);
    b.insert(90, b.root);
    b.insert(75, b.root);
    b.insert(300, b.root);
    b.insert(400, b.root);
    b.insert(500, b.root);
    // b.search(400, b.root);
    b.pre(200,b.root);
    
    // b.suc(75);
    // cout<<endl;

    // b.suc(500);
    // cout<<endl;
    // b.suc(70);
    // cout<<endl;
    // b.suc(400);
}


// // THE METHOD THAT I UNDERSTAND // 

// // void BST::insert(int key, Node *temp){
//     // if(temp==NULL){
//     //     Node *nw = new Node;
//     //     nw->val = key;
//     //     temp = nw;
//     //     root = temp;
//     //     return;
//     // }
//     // if(temp->val == key){
//     //     cout<<"KEY ALREADY EXISTS "<<endl;
//     //     return;
//     // }
//     // if(key>temp->val){
//     //   if(temp->right != NULL){
//     //     insert(key, temp->right);}
//     //   else{
//     //     Node *nw = new Node;
//     //     nw->val = key;
//     //     temp->right = nw;}
//     // }
//     // if(key<temp->val){
//     //     if(temp->left != NULL){
//     //     insert(key, temp->left);}
//     //   else
//     //     {Node *nw = new Node;
//     //     nw->val = key;
//     //     temp->left = nw;}
//     // }
// // }

// // void BST::search(int key, Node * temp){
// //     if(temp == NULL)
// //     {
// //         cout<<"Empty Tree";
// //         return;
// //     }
// //     if(key == temp->val){cout<<"Key foud"<<endl; 
// //     return;}
// //     if(key < temp->val){
// //       if(temp->left != NULL){search(key, temp->left);}
// //       else{cout<<"key not found"<<endl; 
// //       return;}
// //     }
// //     if(key > temp->val){
// //       if(temp->right != NULL){search(key, temp->right);}
// //       else{cout<<"key not found"<<endl; 
// //       return;}
// //     }
    
// // }
