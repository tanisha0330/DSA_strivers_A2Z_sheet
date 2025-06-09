#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int data ; 
  TreeNode* left ; 
   TreeNode* right ; 

   TreeNode(int val)
   {
    data= val; 
    left = NULL; 
    right= NULL; 
   }
};

// or breadth frist search 


void levelorder(TreeNode* root )
{
  if (root==nullptr ) return ; 

  queue <TreeNode*> q; 

  q.push(root); 

  while (!q.empty())
  {
    TreeNode* curr = q.front(); 
    q.pop(); 

    cout<<curr->data<<" "; 

    if (curr->left) q.push(curr->left);
    if (curr->right) q.push(curr->right); 
  }
}



void levelOrderLineByLine(TreeNode* root)
{
  if (root ==nullptr) return ; 
  queue <TreeNode*> q; 
  q.push(root); 


  while (!q.empty())
  {
    int size= q.size(); 

    for (int i=0; i<size; i++)
    {
      TreeNode* curr = q.front(); 
      q.pop(); 
      cout<<curr->data<<" "; 



      if (curr->left!=nullptr) q.push(curr->left); 
      if (curr->right!=nullptr) q.push(curr->right); 
    }
    cout<<endl;
  }
}


int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Level Order Traversal (Single Line): ";
    levelorder(root);
    cout << endl;

    cout << "Level Order Traversal (Line by Line):" << endl;
    levelOrderLineByLine(root);


    return 0;
}