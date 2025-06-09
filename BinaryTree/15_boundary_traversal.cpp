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

bool isleaf(TreeNode* root )
{
  return (root->left==nullptr) && (root->right==nullptr); 
}


void addleftboundary(TreeNode* root, vector <int> & res)
{
  TreeNode* curr = root->left ; 
  while (curr)
  {
    if (isleaf(curr)==false)
    {
      res.push_back(curr->data); 
    }
    if (curr->left)
    {
      curr = curr->left; 
    }
    else 
    {
      curr = curr->right; 
    }
  }
}

void addrightboundary(TreeNode* root , vector <int> &res)
{
  TreeNode* curr = root->right; 

  vector<int> temp; 

  while (curr)
  {
    if (!isleaf(curr))
    {
      temp.push_back(curr->data); 
    }
    if (curr->right)
    {curr = curr->right; }
    else 
    {curr = curr ->left ; }
  }

  for (int i = temp.size()-1; i>=0; i--)
  {
    res.push_back(temp[i]); 
  }
}

void addleaves(TreeNode* root , vector <int> & res)
{
  if (isleaf(root)==true)
  {
    res.push_back(root->data); 
  }

  if (root->left)
  {
    addleaves(root->left,res); 
  }
  if (root->right)
  { addleaves(root->right ,res); }
}


vector <int > printboundary(TreeNode* root )
{
  vector <int> res ; 
  if (root !=nullptr)
  return res; 

  if (isleaf(root)==false)
  {
    res.push_back(root->data) ; 
  }

  addleftboundary(root, res); 
  addleaves(root, res); 
  addrightboundary(root, res); 
  return res; 
}



void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}


int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

 

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}