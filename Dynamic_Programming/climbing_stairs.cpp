#include <bits/stdc++.h>
using namespace std; 
int f(int n)
{
  if (n==0 || n==1) return 1; 
  return f(n-1) +f(n-2); 

}

int f2(int n, vector <int> & dp)
{
  dp[0]=0;
  dp[1]=1;
  if (dp[n]!=-1) return dp[n];
  return dp[n] = f2(n-1,dp) +f2(n-2,dp); 

}
int main(){
int n=3; 
vector <int> dp(n+1, -1);
f(n); 
 

int prev=1; 
int prev2=1;


for (int i=2; i<=n; i++)
{
  int curr_i=prev2+prev; 
  prev2=prev; 
  prev=curr_i; 
}
cout<<prev;
return 0;
}

