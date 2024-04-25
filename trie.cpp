#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
         isterminal = false;
    }
};
class Trie{
    public:
   TrieNode* root;
     Trie(){
        root = new TrieNode('\0');
     }
   void insertutil(TrieNode* root, string word){
     if(word.length() == 0){
        root->isterminal = true;
        return;
     }
     //assume all letters should be lower case
     int index = word[0] - 'a';
     TrieNode* child;
     if (root->children[index] !=NULL)
     {
        child = root->children[index]; 
     }
     else{
        child = new TrieNode(word[0]);
        root->children[index] = child;
     }
     insertutil(child, word.substr(1));
     
   }
   void insertword(string word){
    insertutil(root, word);
   }
};
int main(){
  Trie* t  = new Trie();
  t->insertword("abcd");
return 0;
}