#include <bits/stdc++.h>
using namespace std; 

int solve(int n, vector<int> height)
{
  int jumpTwo = INT_MAX; 
  if (n==0) return 0; 

  int jumpOne= solve(n-1, height )+abs(height[n]-height[n-1]); 

  if (n>1)
  jumpTwo= solve(n-2, height )+abs(height[n]-height[n-2]); 

   return min(jumpOne,jumpTwo );

}



int memoization_solve(int ind, vector<int> height, vector <int> dp)
{
  int jumpTwo = INT_MAX; 
  dp[0]=0;  
 
  if (dp[ind]!=-1) return dp[ind];

  int jumpOne= memoization_solve(ind-1, height, dp)+abs(height[ind]-height[ind-1]); 
  if (ind>1)
  jumpTwo= memoization_solve(ind-2, height, dp)+abs(height[ind]-height[ind-2]); 

  return dp[ind]= min(jumpOne,jumpTwo );
 

}






int tabulation_solve( int n, vector <int> height)
{ vector <int> dp(n,0); 
  dp[0]=0; 
  for (int i=1; i<n; i++)
  {
    int jump2=INT_MAX;
    int jump1=dp[i-1] +abs(height[i]-height[i-1]); 
    if (i>1) 
    jump2=dp[i-2] +abs(height[i]-height[i-2]); 
    
    dp[i]= min(jump1,jump2); 
  }
  return dp[n-1];

}



int spaceOptimized_solve( int n, vector <int> height)
{ vector <int> dp(n,0); 
  
  int prev=0; 
  int curr=0; 
  int prev2=0; 

  for (int i=1; i<n; i++)
  {
    int jump2=INT_MAX;
    int jump1=prev +abs(height[i]-height[i-1]); 
    if (i>1) 
    jump2=prev2+abs(height[i]-height[i-2]); 

    curr= min(jump1,jump2); 
    prev2=prev; 
    prev=curr; 
   
  }
  return prev;

}





int main()
{ vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<solve(n-1,height)<<endl;
  int ind=n-1; 
  
 cout<<memoization_solve(ind,height, dp)<<endl;
 cout<<tabulation_solve(n,height)<<endl; 
 cout<<spaceOptimized_solve(n,height)<<endl; 



}