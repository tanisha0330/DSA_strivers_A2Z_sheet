#include <bits/stdc++.h>
using namespace std;

bool subsetsumuntil( int ind , int target , vector <int> arr, vector<vector<int>> &dp)
{
  if (target==0) return true; 
  if (ind==0)
  return (arr[0]==target); 

  if (dp[ind][target] !=-1) 
  return dp[ind][target]; 


  bool not_take = subsetsumuntil(ind-1, target, arr, dp); 

  bool take= false ;
  if (arr[ind]<=target) 
  take= subsetsumuntil(ind-1, target-arr[ind], arr, dp);


  return take|| not_take; 
}


bool tabulation  ( int n , vector <int> arr)
{

  int totalsum= 0; 
   
  // first calculate the total sum 
  for (int i=0; i<n; i++)
  {
    totalsum= totalsum+ arr[i]; 
  }

  if (totalsum%2==1) return false; 
  else 
    {int target =totalsum/2; 

  vector<vector<int>> dp(n, vector<int>(target+1, -1)); 



 
  // base case 1 
  for (int i=0; i<n ; i++)
  {
    dp[i][0]=true; 
  }

  //base case 2

  if (arr[0]<=target)
  dp[0][0]=true; 



  for (int i=1; i<n; i++)
  {
    for (int j=1; j<=target; j++)
    {
      int not_taken =dp[i-1][j]; 
      int taken=false ; 
      if (arr[i]<=target)
      {
        taken = dp[i-1][j-arr[i]]; 
      }
      dp[i][j]= taken||not_taken; 

    }
  }
  return dp[n-1][target-1];
}}




bool space_optimization(int &n , vector<int> arr)
{
  int totalsum= 0; 
   
  // first calculate the total sum 
  for (int i=0; i<n; i++)
  {
    totalsum= totalsum+ arr[i]; 
  }

  if (totalsum%2==1) return false; 
  else 
    {int target =totalsum/2; 
      vector <int> prev(target+1, false); 
      


      if (arr[0]<=target) prev[arr[0]]=true; 

      for (int i=1; i<n; i++)
      { vector <int> curr(target+1, false); 
        curr[0]=true;
        for (int j=1; j<=target ; j++)
        {
          bool not_taken = prev[j]; 
          bool taken = false; 
          if (arr[0]<=target)
        {taken = prev[j-arr[i]]; }
          
          
          curr[j]= taken || not_taken ; 
        }
        prev=curr; 
      }
    return prev[target]; 



}}










bool can_partition (int & n , vector<int> arr)
{
  int totalsum= 0; 
   
  // first calculate the total sum 
  for (int i=0; i<n; i++)
  {
    totalsum= totalsum+ arr[i]; 
  }

  if (totalsum%2==1) return false; 
  else {
    int k =totalsum/2; 
    vector<vector<int>> dp(n, vector<int>(k+1, -1)); 
    return subsetsumuntil(n-1, k , arr, dp); 
  }
}





int main() {
    vector<int> arr = {2, 1, 3, 3, 4, 5};
    int n = arr.size();

    if (can_partition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";


      cout<<endl<<"+++++++++++++++"<<endl;


        if (tabulation(n,arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

      
      cout<<endl<<"+++++++++++++++"<<endl;


        if (space_optimization(n,arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}