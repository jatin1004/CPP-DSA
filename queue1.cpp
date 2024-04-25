#include<iostream>
#include<queue>
using namespace std;
int main(){
   queue<int> q;
   q.push(12);
   q.push(15);
   q.push(23);
   cout<<"size of queue is:"<<q.size()<<endl;
   q.pop();
   cout<<"size of queue is:"<<q.size()<<endl;
 return 0;
}