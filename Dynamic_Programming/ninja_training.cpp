#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int f(int day, int last, vector<vector<int>> & points , vector<vector<int>> &dp )
{
  if (dp[day][last]!=-1) return dp[day][last]; 
  if (day==0)
  {
    int maxi=0; 
    for (int i=0; i<=2; i++)
    {
      if (i!=last)
      {
        maxi=max(maxi, points[0][i]); 
      }
    }
    return dp[day][last]=maxi;
  }
  int maxi=0; 

  for (int i=0; i<=2; i++)
  {
    if (i!=last)
    {
      int activity = points[day][i]+f(day-1, i, points, dp); 
      maxi= max(maxi, activity); 

    }
  }
  return dp[day][last]= maxi; 


}

//tabulatation 
int f2(int day, int last, vector<vector<int>> & points , vector<vector<int>> &dp, int n )

  {
    

    // DECLARING THE BASE CASES 

    dp[0][0]= max (points[0][1], points [0][2]); 
    dp[0][1]= max (points[0][0], points [0][2]); 
    dp[0][2]= max (points[0][1], points [0][0]); 
    dp[0][3]= max (points[0][1], points [0][2], points[0][0]); 


  for (int day=1; day<n; day++)
  {
    for (last=0; last<4; last++)
    {
    dp[day][last]=0; 
    for (int task=0; task<3; task++)
    {
      int activity = points[day][task]+dp[day-1][last];
      dp[day][last]= max(dp[day][last], activity); 

    }
  }}
  return dp[n-1][3]; 


}
    
 
int maximumMeritPoints(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp (n,vector<int> (4,-1)); 
  
        return f(n-1,3, points, dp); 
    }
};

int main() {
    // Example usage:
    int n;
    cout<<" enter n : "; 
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    cout<<" enter the array : "  ; 
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    Solution obj;
    int ans = obj.maximumMeritPoints(n, points);
    cout << ans << endl;

    return 0;
}
