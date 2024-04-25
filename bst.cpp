#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

   Node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
   } 
};
void inorder(Node* &root){
    if(root==NULL){
        return;
    }
   
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    
}
void preorder(Node* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* &root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node* insertintobst(Node* &root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data){
        root->right = insertintobst(root->right,d);
    }
    else{
        root->left = insertintobst(root->left, d);
    }
    return root;
}
Node* minvalue(Node*  &root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxvalue(Node* &root){
    Node* temp = root;
    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp;
}
Node* deletenode(Node* &root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data == val){
      if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
      }
      if(root->left !=NULL && root->right == NULL){
       Node* temp = root->left;
       delete root;
       return temp;
      }
      if(root->left == NULL && root->right !=NULL){
        Node* temp = root->right;
        delete root;
        return temp;
      }
      if(root->left != NULL && root->right !=NULL){
        int mini = minvalue(root->right)->data;
        root->data = mini;
        root->right = deletenode(root->right, mini);
        return root;
      }
      


    }
    else if(root->data > val){
        root->left= deletenode(root->left, val);
        return root;
    }
    else{
        root->right = deletenode(root->right, val);
        return root;
    }

}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       if(temp == NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
       }
       else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
       }
    }
}
void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data !=-1){
        insertintobst(root, data);
        cin>>data;
    }
}
int main(){
    Node* root= NULL;
    cout<<"Enter data to insert" <<endl;
    takeinput(root);
    cout<<"printing bst"<<endl;
    levelordertraversal(root);
    cout<<"printing inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"printing preorderorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"printing postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Min value is" <<minvalue(root)->data<<endl;
    cout<<"max value is "<<maxvalue(root)->data<<endl;
    return 0;
}