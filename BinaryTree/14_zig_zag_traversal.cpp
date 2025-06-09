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

vector<vector<int>>  zigzag(TreeNode* root )
{
  vector<vector<int>> result; 
  if (root ==NULL)
  return result ; 

  queue <TreeNode*> q;
  q.push(root); 
  bool ltr=true; 
  while (!q.empty())
  {
    int size = q.size(); 
    vector<int> row(size); 
    for (int i =0; i<size;i++)
    {
      TreeNode* node = q.front(); 
      q.pop(); 
      int index = (ltr) ? i : (size-1-i); 

     row[index] = node->data; 
     if (node->left)
     {
      q.push(node->left); 

     }
     if (node->right)
     {
      q.push(node->right); 
     }

    }
    ltr =!ltr; 
    result.push_back(row);
  }
  return result;
  
  
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
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

}
   
   
