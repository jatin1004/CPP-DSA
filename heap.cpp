#include<iostream>
using namespace std;

class heap{
  public:
  int arr[1000];
  int size ;
  heap(){
    arr[0]=-1;
    size =0;
  }
  void insert(int val){
    size = size+1;
    int index = size;
    arr[index] = val;
    while(index>1){
        int parent = index/2;
        if(arr[parent]<arr[index]){
           swap(arr[parent], arr[index]);
           index= parent;
        }
        else{
            return;
        }
    }
  }
  void print(){
    for(int i=1;i<=size;i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
  }
  void delfromheap(){
    if(size ==0){
        cout<<"Nothing to print" << endl;
        return;
    }
    
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size){
        int leftindex = 2*i;
        int rightindex = 2*i+1;
        if(leftindex<size && arr[i]<arr[leftindex] && arr[leftindex]>arr[rightindex]){
             swap(arr[i], arr[leftindex]);
             i=leftindex;
        }
        else if(rightindex < size && arr[i]< arr[rightindex] && arr[rightindex]>arr[leftindex] ){
            swap(arr[i], arr[rightindex]);
            i = rightindex;
        }
        else{
            return;
        }
    }
  }
};
void heapify(int arr[], int size , int index){
    int largest  = index;
    int left = 2*index;
    int right = 2*index+1;
    if(left<=size && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=size && arr[largest] <arr[right]){
        largest = right;
    }
    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}
void heapsort(int arr[], int n){
    int size =n;
    while(size>1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main(){

   heap h;
   h.insert(50);
   h.insert(53);
   h.insert(55);
   h.insert(52);
   h.insert(60);
   h.print();
   h.delfromheap();
   h.print();
   int arr[6] = {-1, 54, 55, 53, 52, 50};
   int n = 5;
   for(int i = n/2;i>0;i--){
    heapify(arr, n, i);
   }
   cout<<"Printing heapify "<<endl;
   for(int i =1;i<=n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   heapsort(arr, n);
   cout<<"Printing sorted heap "<<endl;
   for(int i =1;i<=n;i++){
    cout<<arr[i]<<" ";
   }
    return 0;
}