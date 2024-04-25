#include<iostream>
using namespace std;
int fibonacci(int n ){
  int a=0;
    int fib=1;
    int b=1;
    int i =1;
    while(i<n)
    {
    fib=a+b;
    i++;
    a=b;
    b=fib;
    cout<< fib <<" ";
    }
    return fib;
    
}


int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    cout<<fibonacci(n);
}
