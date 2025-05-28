/* Given an array of distinct integers (nums) and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers
sum to target. You may return the combinations in any order. */

#include<bits/stdc++.h>
using namespace std; 

void combo(vector <int> curr , int index, vector<vector<int>> &ans, vector<int> &nums, int  target )
{
  int n=nums.size(); 

  if ( target==0) 
  //if (index==n && target==0) 
   // if it id only target ==0 then output will be printed multiple times , until n is reached
  {
    ans.push_back(curr); 
    return; // i have to add return here like this .
  }

  if (index==n || target<0)
  return;

  if (nums[index]<=target)
  {curr.push_back(nums[index]); 
  combo(curr, index , ans, nums, target-nums[index]);
  curr.pop_back(); }

  
  combo(curr, index+1 , ans, nums, target);
   return;
   
}

vector<vector<int>> combinationsum1(vector<int> nums , int target)
{
  vector <int> curr ;
  int index=0; 
  vector<vector<int>> ans;
  combo(curr ,index ,ans, nums,target );
  return ans;
}



int main()
{
  vector < int > nums {2,3,6,7};
  int target = 7;

  vector < vector < int >> ans = combinationsum1(nums, target);
  cout << "Combinations are: " << endl;
 for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
     cout << ans[i][j] << " ";
    cout << endl;
  }


}



