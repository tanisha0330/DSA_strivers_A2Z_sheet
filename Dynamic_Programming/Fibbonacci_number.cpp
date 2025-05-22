#include <bits/stdc++.h>
using namespace std; 


int fb(int n, vector <int> &dp)
{  //memoization form 
  if (n<=1) return n; 
  if (dp[n] !=-1) {return dp[n];}
  return dp[n]=fb(n-1,dp)+fb(n-2,dp); 

}

int main()
{
  int n; 
  cout<<"enter the value of n: "; 
  cin>> n; 
  vector <int> dp(n+1, -1); 
  //r you can do 
  // tabulation
  int prev=1; 
  int prev2=0;
  if (n==0) prev=0;
  for (int i=2; i<=n; i++)
  {
    int curri=prev+prev2; 
    prev2=prev;
    prev=curri; 
  }
cout<<prev; 



  return 0;
}
