#include <bits/stdc++.h>
using namespace std; 

//count number of subsets_with sum k




int count(int k , vector <int> & arr)
{
 int cnt=0; 
 int n=arr.size(); 

 vector<vector <int>>dp(n, vector<int> (k+1, 0)); 

if (arr[0] == 0) dp[0][0] = 2;  // include and exclude
    else dp[0][0] = 1;              // only exclude

 for (int i=0; i<n; i++)
 dp[i][0] =1; 


 if (arr[0]<=k)
 dp[0][arr[0]]=1; 


 for (int ind=1; ind<n; ind++)
 {
  for (int sum=1; sum<=k ; sum++)
  {
    int not_take = dp[ind-1][sum]; 
    int take=0; 
    if (arr[ind]<=sum)
    {
      take = dp[ind-1][sum-arr[ind]]; 
    }
    dp[ind][sum]=take+not_take; 
  }
 }
 return dp[n-1][k]; 


}

//do space optimization too !!

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " <<count(k,arr);

    return 0;
}
