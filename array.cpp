#include<iostream>
using namespace std;
 void reverse(int num[], int n){
 
   for(int i=0;i<n;i=i+2){
     if(i+1<n){
      swap(num[i],num[i+1]);
     }
   }
    
 }
 int printarray(int num[], int n){
    for(int i=0;i<n;i++){
        cout<<num[i] <<" ";
    }
    cout<<endl;
 }
 int main(){
    int num[5]={1, 2, 3, 4, 5, };
    reverse(num, 5);
    printarray(num, 5);
    return 0;
 }