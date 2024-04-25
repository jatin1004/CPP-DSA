#include<iostream>
using namespace std;
int partition(int *arr, int s, int e){
  int pivot = arr[s];
  int cnt=0;
  for(int i=s+1;i<=e;i++){
    if(arr[i]<pivot){
        cnt++;
    }
  }
  int pvindx = s+cnt;
  swap(arr[s],arr[pvindx]);
  int i=s;int j=e;
  while(i<pvindx && j>pvindx){
    while(arr[i]<pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
      if(i<pvindx && j>pvindx){
        swap(arr[i],arr[j]);
        i++;
        j--;
      }
      
  }
  return pvindx;
}
void quicksort(int *arr, int s, int e){
   if(s>=e){
    return;
   }
  int p = partition(arr,s,e);
  quicksort(arr,s,p-1);
  quicksort(arr,p+1,e);
}
int main(){
     int arr[6] = {6,9,2,4,1,0};
     int n =6;
     quicksort(arr,0,n-1);
     
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}