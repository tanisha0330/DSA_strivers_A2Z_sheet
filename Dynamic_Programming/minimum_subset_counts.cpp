#include <bits/stdc++.h>
using namespace std;

/*bool subsetSumToK(int n, int k,vector <int>& arr,vector<vector<int>> &dp)
{

if (k==0) return  true; 
if (n==0)
{if (arr[0]==k) return true; 
  else return false;}

if (dp[n][k]!=-1) return dp[n][k]; 

bool not_taken = subsetSumToK(n-1, k, arr,dp); 
bool taken=false; 
if (arr[n]<=k)
 {
  taken = subsetSumToK(n-1, k-arr[n], arr, dp);
 }

return dp[n][k]= taken|| not_taken; 


}
*/


bool subsetSumToK(int n, int k,vector <int>& arr,vector<vector<int>> &dp)
{

for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }


 if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

for (int i=1; i<n; i++)
{
  for (int j=1; j<k; j++)
  {
    if (j==0) return true; 
    
    bool not_taken = dp[i-1][j];
    bool taken=false; 
if (arr[i]<=j)
 {
  taken = dp[i-1][j-arr[i]];
 }

  dp[n][k]= taken|| not_taken; 
  }
  return dp[n-1][k];
}








}








int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
vector <vector<int>> dp(n,vector<int> (k+1, -1)); 
    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n-1, k, arr,dp))
        cout << "Subset with the given target found"<<endl;
    else
        cout << "Subset with the given target not found";
      return 0; }