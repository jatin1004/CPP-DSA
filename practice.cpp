#include <iostream>
using namespace std;
void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    int l1 = mid-s+1;
    int l2 = e-mid;
    int *first = new int[l1];
    int *second = new int[l2];
    int k =s;
    for(int i=0;i<l1;i++){
        first[i] = arr[k++];
    }
    k= mid+1;
    for(int i=0;i<l2;i++){
        second[i]=arr[k++];
    }
    int ind1 =0;
    int ind2 =0;
    int index=s;
    while(ind1<l1 && ind2<l2){
        if(first[ind1]<second[ind2]){
            arr[index++]=first[ind1++];
        }
        else{
             arr[index++]=second[ind2++];
        }
    }
    while(ind1<l1){
        arr[index++]=first[ind1++];
    }
    while(ind2<l2){
         arr[index++]=second[ind2++];
    }
}
void mergesort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
    
}
int main() {
   int arr[6] ={15,2,31,4,25,61};
   int n = 6;
   mergesort(arr,0,n-1);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
    return 0;
}