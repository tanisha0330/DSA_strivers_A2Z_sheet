#include <bits/stdc++.h>
using namespace std; 
/*
J>maxtarget=  0  1  2  3  4  5  6  7  8  9  10
I|
index=0       T  T  F  F  F  F  F  F  F  F  F  = prev
  ind=1       T  T  T  T  F                    =curr
  ind=2       T  T
  ind=3       T  T

*/
// by tabulation 
bool subset_Sum(int n, int k,vector <int>& arr,vector<vector<int>> &dp)
{     

for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
//dp[0][0]=T,dp[1][0]=T, dp[2][0]=T,*dp[3][0]=T

 if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
//{1, 2, 3, 4}
for (int i=1; i<n; i++)
{
  for (int j=1; j<=k; j++)
  {
    bool not_taken = dp[i-1][j]; 
    bool taken=false; 

if (arr[i]<=j)
 {
  taken = dp[i-1][j-arr[i]];
 }

  dp[n][k]= taken|| not_taken; 
  }
  return dp[n-1][k];
}}


int minimum_subset_sum_difference(vector<int> arr, int n)
{
  int total_Sum=0; 
  // first find the total sum 
  for (int i=0; i<n; i++)
  {
    total_Sum=total_Sum+arr[i]; 
  }


// make a dp vector
  vector<vector<int>>dp(n, vector <int> (total_Sum +1, -1)); 


// for filling the dp vector 
  for (int i=0; i<=total_Sum; i++)
  {
    bool dummy= subset_Sum(n-1, i, arr, dp); 
  }

  /* n=4 
  subset_sum(3, 0, arr, dp)
  subset_sum(3, 1, arr, dp)

  */

int mini=INT_MAX;             // declare a minimum var
for (int i=0; i<=total_Sum; i++) // iteration in total sum array one by one , calculating the diff - for which the value is true ; 
{
  if (dp[n-1][i]==true)
  {
    int diff=abs(i-(total_Sum-i)); 
    mini=min(diff, mini); 
  }
}
return mini; 
}

//space optimization 

int space_optimized(vector<int> & arr, int n)
{
  int total_sum=0;           

  for (int i=0; i<n; i++)
  {
    total_sum=total_sum+arr[i]; 
  }
 //we have calculated total sum

  vector <int> prev (total_sum+1,false); 

  // define the base cases 
  prev[0]=true; 

  // initializing the first row - i didnt entioned it.
  if (arr[0]<=total_sum) prev[arr[0]]=true; 


// filliing the prev array 
for (int ind=1; ind<n; ind++)
//start ind from 1 
 { vector<int> curr(total_sum+1, false); 
   curr[0]=true;    // i forgot to mention  
  for (int target=1; target<=total_sum; target++)     // note target will start from 1
 {


  bool not_take = prev[target];    // this will get its valur fron the earlier initialisation.
  bool take= false; 
  if (arr[ind]<=target)
      take = prev[target-arr[ind]]; 

 // prev=curr; 
  curr[target] = take ||not_take;
 }
 prev=curr;
}

// the function to get the moinimum absolutte ;

int mini=INT_MAX; 

for (int i=0; i<=total_sum; i++)
{int diff=abs(i-(total_sum-i)); 
mini= min(mini, diff); }
return mini; 
 

}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minimum_subset_sum_difference(arr, n);
cout<<endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl; 

     cout << "The minimum absolute difference is: " << space_optimized(arr, n);

    return 0;
}
