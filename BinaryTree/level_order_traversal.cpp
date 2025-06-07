#include <bits/stdc++.h>
using namespace std; 

class Node
{
public: 
  int val; 
  Node* left; 
  Node* right;
  Node(int val)
  {
    this->val =val;
    this->left = NULL; 
    this->right=NULL;
  }
};

int levels(Node* root)
{
  if (root==nullptr) return 0;
  
  return 1+ max(levels(root->left),levels(root->right));
  
}
void display(Node* root)
{
  if (root == NULL) return ; 
  cout<<root->val<<endl; 
   display(root->left);
  display(root->right);
 
}

void nthlevel(Node* root, int curr, int level)
{
  if (root==NULL) return; //base case
  if (curr==level) cout<<root->val<<" ";
  nthlevel(root->left, curr+1, level); 
  nthlevel(root->right, curr+1, level); 

}

void nthlevelrev(Node*root, int curr, int level)
{
  if (root==NULL) return; //base case
  if (curr==level) cout<<root->val<<" ";
  nthlevel(root->right, curr+1, level);
  nthlevel(root->left, curr+1, level); 
  
}

void levelorder(Node* root)
{
  int n=levels(root);
  for (int i=1; i<=n; i++)
  { 
    nthlevel(root,1,i);
    nthlevelrev(root,1,i);
    cout<<endl;
  }
  /*1 1 
2 3 3 2
4 5 6 9 6 9 4 5*/

}





int main()
{
  Node* a= new Node (1);
  Node* b= new Node (2);
  Node* c= new Node (3);
  Node* d= new Node (4);
  Node* e= new Node (5);
  Node* f= new Node (6);
  Node* g= new Node (9);
  a->left =b; 
  a->right=c;
  b->left=d;
  b->right=e;
  c->left=f;
  c->right=g;
  levelorder(a); 
  

// level order traversal;


}
