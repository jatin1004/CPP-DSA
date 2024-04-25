#include <iostream>
//linked list insertion singly
using namespace std;
 class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
    //memory free karvane k liye
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout <<"memory is free for "<< value <<endl;        
    }
 };
//insert at start
 void insert(Node* &head, int d){
    //create new node 
    Node* temp= new Node(d);
     temp->next=head;
     head=temp;
 }

//insert at tail
 void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp; 
 }

 void insertPosition(Node* &head,Node* &tail, int position, int d){
   //if we have to add at first position
    if(position == 1){
        insert(head, d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    //insert at last
    if(temp->next == NULL){
        insertTail(tail, d);
        return;
    }
    //insert at middle 
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
 }
 void print(Node* &head){
    
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout << endl;
 }
 void deleteNode(Node* &head,Node* &tail, int position){
    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        //memory free for first node
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
      //deleting node from middle or last
      Node* curr = head;
      Node* prev = NULL;
      int cnt=1;
      while(cnt<position){
        prev = curr;
        curr= curr->next;
        cnt++;
      }
      prev->next=curr->next;
      curr->next = NULL;
      if(prev->next==NULL){
       tail = prev;
      }
      delete curr;
      
    }
 }
int main(){
   Node* node1 = new Node(10);
 // cout << node1 ->data<<endl;
  //cout <<node1->next<<endl;
  Node* head = node1;
  Node* tail = node1;

   print(head);
  insertTail(tail, 12);
  print(head);
   insertTail(tail, 15);
   print(head);
   insertPosition(head,tail, 3, 44);
   print(head);
   deleteNode(head,tail, 4);
   print(head);
   cout <<"head is at"<<head->data <<endl;
   cout<<"tail is at "<<tail->data <<endl;
 return 0;
}