#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
int occ(int arr[], int size, int key){
    
    int i=0;
    int j=size-1;
    while(i<=j){
        if(arr[i]==key){
            return i;
            ans.push_back(i);
            break;
        }
        if(arr[j]==key){
            return j;
            ans.push_back(j);
            break;
        }
        i++;
        j--;
        return -1;
    }


}
void printarray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i] <<" ";
    }
}
int main(){
    int arr[6]={1,2,1,4,1,2};
    printarray(arr, 6);
    int key =1;
    occ(arr, 6, 1);
    std::cout <<ans <<endl;
}