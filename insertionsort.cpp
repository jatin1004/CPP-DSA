#include<iostream>
using namespace std;
void insort(int *arr, int s, int e){
    for(int i=1;i<=e;i++){
        int temp = arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]= arr[j];
            }
            else{
                break;
            }
            
        }
        arr[j+1]=temp;
    }
}
int main(){

     int arr[6] = {6,9,2,4,1,0};
     int n =6;
     insort(arr,0,n-1);
     
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}