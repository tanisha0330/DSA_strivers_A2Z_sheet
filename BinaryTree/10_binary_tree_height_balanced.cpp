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



int height(TreeNode* root )
{
  if (root==nullptr) return 0; 
  int lh = height(root->left); 
  if (lh==-1) return -1; 
  int rh = height(root->right);
   if (rh==-1) return -1; 


  if (abs(lh-rh)>1 ) return -1; 

  return 1 + max(lh,rh); 
}


int main() {
    // Build this sample tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    //root->right->left = new TreeNode(6);
    //root->right->right = new TreeNode(7);


    cout << "height : " << height(root);
   
    cout << endl;
}