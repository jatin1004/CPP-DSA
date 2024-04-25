#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
   unordered_map<string, int> m;
    //insertion
    //1
    pair<string, int> p = make_pair("mera", 2);
    m.insert(p);
    //2
    pair<string, int> p2("naam", 3);
    m.insert(p2);
    //3
    m["Jatin"] = 1;
    //it will not create new memory or entry in hastable,  it will only update mera
    m["mera"] = 3;
    //search
    cout<<m["mera"] <<endl;
    cout<<m.at("Jatin") <<endl;
    //important *******
    cout<<m["unknownkey"]<<endl; // it will give  0 bcz entry will created for unknown key corresponding to 0
    cout<<m.at("unknownkey") <<endl; //  it will give error when executed alone but if executeed after above cmnd this will also give 0 bcz entry was crearted
    //size
    cout<<m.size()<<endl;
    //to check presence
    cout<<m.count("mera")<<endl;//it will give true or false as 1 or 0 
    cout<<m.count("bro")<<endl;// give 0
    //erase function
    m.erase("naam");
    cout<<m.count("naam")<<endl;

    // access
    for(auto i:m){
        cout<<i.first << " " << i.second <<endl;
    }

    // access using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<< it->first <<" " <<it->second <<endl;
        it++;
    }
  return 0;
}