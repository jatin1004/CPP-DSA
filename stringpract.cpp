#include<bits/stdc++.h>
using namespace std;
bool solve(string s1, string s2){
    s1+= s1;
    if(s1.find(s2)!=-1){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}
int main(){
    string s1 = "geeksforgeeks";
    string s2 = "forgeeksgeeks";
    solve(s1,s2);

    return 0;
}