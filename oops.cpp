#include <iostream>
using namespace std;

class Hero{
  public:
  int age;
  int weight;
  protected:
  int height;
  string name;
  int getage(){
    return this->age;
  }
  int setweight(int w){
    this->weight = w;
  }
  
  

};
class Jack : public Hero{
    public:
  string color;
  void sleep(){
    cout << "sleeping" << endl;
  } 
  int getHeight(){
    return this->height;
     } 

};
int main(){
  Jack ans;

// ans.setweight(84);
 //cout << ans.height << endl;
  cout << ans.getHeight() << endl;
 // cout << ans.age << endl;
  //cout << ans.height << endl;
}