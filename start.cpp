#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter the number of rows:\n";
    cin>>a;
    int i=1;
    while(i<=a){
        int j=1;
        while(j<=a-i+1){
        cout<<j;
        j++;
        }
        int star=i-1;
        while(star){
            cout<<"*";
            star--;
        }
        int star2=i-1;
        while(star2){
            cout<<"*";
            star2--;
        }
        int k=a-i+1;
        while(k){
            cout<<k;
            k--;
        }
        cout<< endl;
        i++;
    }
}