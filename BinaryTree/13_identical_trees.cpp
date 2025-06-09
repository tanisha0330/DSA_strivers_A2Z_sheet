#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1==NULL && root2==NULL) return true; 
  if (root1==NULL || root2 ==NULL) return false;
   

    return ((root1->data ==root2->data )&& areIdentical(root1->left,root2->left)&&areIdentical(root1->right,root2->right)); 
  
}

int main() {
  
  TreeNode* root1 = new TreeNode(1);
root1->left = new TreeNode(2);
root1->right = new TreeNode(3);
root1->left->left = new TreeNode(4);
root1->left->right = new TreeNode(5);


TreeNode* root2 = new TreeNode(1);
root2->left = new TreeNode(2);
root2->right = new TreeNode(3);
root2->left->left = new TreeNode(99);
root2->left->right = new TreeNode(5);
    if (areIdentical(root1, root2)==true)
        cout << "Trees are identical " << endl;
    else
        cout << "Trees are NOT identical" << endl;

    return 0;
}
