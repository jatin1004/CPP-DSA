#include<iostream>
using namespace std;

class Node{
    public:
   int data;
   Node* prev;
   Node* next;
   Node(int d){
    this->data= d;
    this->next=NULL;
    this->prev = NULL;
   } 
   ~Node(){
    int value = this->data;
    if(this->next!=NULL){
        delete next;
        this->next = NULL;
    }
    cout<<"memory is free for "<<value<<endl;
   }
};
//traversing in LL
void print(Node* head){
    Node* temp=  head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout <<endl;
}
//length of linked list
int lengthOfLL(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(Node* &head,Node* &tail,  int d){
    //empty list
    if(head==NULL){
     Node* temp = new Node(d);
     head = temp;
     tail= temp;
    }
    else{
     //rest of general   
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
void insertattail(Node* &head, Node* &tail, int d){
    //empty list
    if(tail==NULL){
        Node* temp = new Node(d);
        head= temp;
        tail = temp;
    }
    //rest of general
    Node* temp = new Node(d);
    temp->next=NULL;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
    
}

void insertatposition(Node* &head, Node* &tail, int pos, int d){
   
    Node* temp = head;
    if(pos==1){
        insertathead(head,tail,  d);
        return;
    }
     Node* nodetoinsert = new Node(d);
     int cnt =1;
     while(cnt<pos-1){
        temp = temp->next;
        cnt++;
     }
     if(temp->next==NULL){
        insertattail(head, tail,d);
        return;
     }
     nodetoinsert->next=temp->next;
     temp->next->prev = nodetoinsert;
     temp->next=nodetoinsert;
     nodetoinsert->prev=temp;

}
void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp = head;
        temp->next->prev =NULL;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prevo = NULL;
        int cnt =1;
        while(cnt<pos){
        prevo= curr;
        curr= curr->next;
        cnt++;
        }
       
        if(curr->next == NULL){
            prevo->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
         prevo->next=curr->next;
        curr->next->prev = prevo;
        curr->prev = NULL;
        curr->next = NULL;
        if(prevo->next==NULL){
            tail= prevo;
        }
        delete curr;
    }
}

int main(){
   //Node* node1= new Node(10);
   Node* head= NULL;
   Node* tail = NULL;
    print(head);
  // cout<<lengthOfLL<<endl;
   insertathead(head,tail,  15);
   print(head);
   insertattail(head, tail, 25);
   print(head);
   insertattail(head, tail, 30);
   print(head);
   insertatposition(head, tail, 3, 20);
   print(head);
   insertatposition(head, tail, 1, 11);
   print(head);
   insertatposition(head, tail, 6, 99);
   print(head);

   deleteNode(head, tail, 6);
   print(head);

    return 0;

}