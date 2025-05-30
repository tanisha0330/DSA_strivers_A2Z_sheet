#include <bits/stdc++.h>
using namespace std; 

int solve(int  n, vector<int> &height, int &k)
{
  int mini= INT_MAX; 
  if (n==0) return 0; 

  for (int j=1; j<=k ; j++){    // for (int j = 1; j < k; j++)  // Wrong 🚫
    if (n>=j)
  {
    int jump = solve(n-j, height, k)+abs(height[n]-height[n-j]); 
    mini= min(jump, mini); }}

  

   return mini;
  
}

int memoization(int n, vector<int> & height , int & k, vector<int> & dp)
{
  int mini= INT_MAX; 
  if (n==0) return 0; 
  if (dp[n]!=-1) return dp[n];
  for (int j=1; j<=k ; j++){    // for (int j = 1; j < k; j++)  // Wrong 🚫
    if (n>=j)
  {
    int jump = solve(n-j, height, k)+abs(height[n]-height[n-j]); 
    mini= min(jump, mini); }}

  

   return dp[n]=mini;
  
}


int tabulation(int n, vector<int> & height , int & k, vector<int> & dp)
{
  
  dp[0] =0; 
for (int i=1; i<n; i++)  //  the loop will start from i=1 as , the frog is already at 0th index
  { int mini= INT_MAX; 
    for (int j=1; j<=k ; j++){  
    if (i>=j)
  {
    int jump = dp[i-j]+abs(height[i]-height[i-j]); 
    mini= min(jump, mini); }}

  

   dp[i]=mini;}
   return dp[n-1]; 
  
}









int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector <int> dp(n,-1); 
    cout << solve(n-1, height, k) << endl;
    cout<<memoization(n-1,height, k, dp)<<endl;
     cout<<tabulation(n,height, k, dp)<<endl;
    return 0;
}