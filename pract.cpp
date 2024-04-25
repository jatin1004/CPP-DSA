#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of terms:" <<endl;
    cin>>n;
    int arr[100];
   cout<<"enter the array:" <<endl;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int ans=0;
   for(int i=0; i<n;i++){
    ans=ans^arr[i];
   }
   cout<<ans;
  return ans;
}