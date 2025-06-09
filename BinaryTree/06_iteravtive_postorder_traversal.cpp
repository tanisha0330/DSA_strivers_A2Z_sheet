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


void iterative_postorder(TreeNode* root)
{
  stack <TreeNode*> s1, s2; 
  
  if (root==NULL) return ; 
  s1.push(root); 
  while (!s1.empty())
  {
    TreeNode* curr = s1.top(); 
    s1.pop();
    s2.push(curr); 

    if (curr->left) s1.push(curr->left); 
    if (curr->right) s1.push(curr->right); 
  }

  while (!s2.empty())
  {
    cout<<s2.top()->data<<" "; 
  s2.pop(); 
  }
}



void iterative_postorder2(TreeNode* root)
{
  stack <TreeNode*> st;  
  TreeNode* curr = root ; 
  TreeNode* prev = nullptr; 


  while (!st.empty() || curr!=nullptr)
  {if (curr!=nullptr)
      {st.push(curr); 
      curr=curr->left; }
    else 
        {TreeNode* temp = st.top(); 

        if (temp->right!=NULL && temp->right!=prev)
        {
          curr= temp->right; 
        }
        else 
        {
          cout<<temp->data<<" "; 
          st.pop(); 
          prev = temp; 
        }
      }

  }


  
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


    cout << "postorder Iterative: ";
    iterative_postorder(root);
    cout << endl;
}


/*

🧾 Dry Run Table (w/ prev tracking):
Step	Stack  Top	  curr	  prev	 Action
1	     —	   1	   NULL	    Push 1, go      left
2	     1  	 2	   NULL	    Push 2, go left
3	     2 	   4	   NULL	    Push 4, go left (NULL)
4	     4 	  NULL	 NULL	    Right doesn't exist, print 4
5	     2   	NULL	  4     	Right = 5, move curr = 5
6  	   2,5 	 NULL	4	       Right doesn't exist, print 5
7	     2	  NULL	5	       Right == prev, print 2
8	     1	  NULL	2	       Right = 3, move curr = 3
9	     1,3	 6	  2	         Push 6, go left (NULL)
10	   3,6	 NULL	2	       No right, print 6
11	   3	   NULL	6	       Right = 7, move curr = 7
12	   3,7	 NULL	6	       No right, print 7
13	   3	  NULL	7	       Right == prev, print 3
14	   1	  NULL	3	       Right == prev, print 1
15	   —	  NULL	1	       Done!
*/
