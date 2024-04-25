#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int d){
        this->data = d;
        this->next= NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is deleted for "<<value<<endl;
    }

};

void insertnode(Node* &tail, int element, int d){
    //list is empty
    if(tail==NULL){
        Node* newNode =new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    //list is non empty & we assume that element is present in list
    else{
      Node* curr = tail;
      while(curr->data!=element){
        curr= curr->next;
      }
      //element found
      Node* temp = new Node(d);
      temp->next = curr->next;
      curr->next=temp;
    }
}
void print(Node* &tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    do{
     cout<<tail->data<<" ";
     tail = tail->next;
    }
    while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){
   //list is empty
   if(tail==NULL){
    cout <<"list is empty" <<endl;
    return;
   }
   else{
    //assuming list is not empty and value is present in list
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != value){
        prev= curr;
        curr=curr->next;
    }
    //found the node to delete
    prev->next = curr->next;
    //single node linked list to delete
    if(curr==prev){
        tail=NULL;
    }
    else if(tail == curr){
        tail = curr->next;
    }
    curr->next = NULL;
    delete curr;
   }
}

bool iscircular(Node* tail){
  //empty list
  if(tail == NULL){
    return true;
  }
  Node* temp =tail->next;
  while(temp!=NULL&& temp!=tail){
    temp = temp->next;
  }
  if(temp == NULL){
    return false;
  }
  else if(temp == tail){
  return true;
  }

}
int main(){
   Node* tail=NULL;
    insertnode(tail, 5, 3);
    print(tail);
   
     insertnode(tail, 3, 7);
    print(tail);
/*
     insertnode(tail, 7, 9);
    print(tail);

     insertnode(tail, 7, 8);
    print(tail);
     

    deleteNode(tail, 3);
    print(tail);*/

    if(iscircular(tail)){
        cout <<"linked list is circular"<<endl;
    }
    else{
        cout<<"linked list is not circular"<<endl;
    }

 return 0;
}