#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size= size;
        arr = new int[size];
        top = -1;
    }
  
   void push(int element){
     if(size-top >1){
        top++;
        arr[top]= element;
     }
     else{
        cout <<"stack overflow" <<endl;
     }

   }
  void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<"stack underflow"<< endl;
    }
   } 
  int peek(){
    if(top>=0){
        return arr[top];
    }
    else{
        cout<<"stack is empty"<<endl;
        return -1;
    }
   }
  bool isempty(){
     if(top == -1){
        return true;
     }
     else{
        return false;
     }
   }
  };
int main(){
    Stack st(5);
    st.push(15);
    st.push(14);    
    st.push(45);
    cout<<st.peek() <<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isempty()){
        cout<<"stack is empty bhai"<<endl;
    }
    else{
        cout<<"stack is not empty bhai"<<endl;
    }


   /*stack<int> s;
   s.push(2);
   s.push(3);
   s.pop();
  cout<< "top element is :"<<  s.top() <<endl;*/


}