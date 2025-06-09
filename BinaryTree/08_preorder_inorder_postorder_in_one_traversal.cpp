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
/*
⏩ Preorder = Root → Left → Right

🌀 Inorder = Left → Root → Right

🔚 Postorder = Left → Right → Root
*/