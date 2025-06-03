#include <bits/stdc++.h>
using namespace std; 

    int f (int m , int n, vector<vector<int>> & grid)
    {
        
        if (m==0 && n==0) return grid[m][n]; 

        if (m<0 || n<0) return INT_MAX;
       
        int up = f(m,n-1, grid); 
        int left = f(m-1, n, grid); 
        int resUp = (up == INT_MAX) ? INT_MAX : up + grid[m][n];
        int resLeft = (left == INT_MAX) ? INT_MAX : left + grid[m][n]; 


        // yaha par ek integer overflow ho raha tha 

        return min(resUp, resLeft);
     

    }



     int f2 (int m , int n, vector<vector<int>> & grid,vector <vector<int>> & dp)
    {
        
        if (m==0 && n==0) 
        {return dp[m][n]= grid[m][n]; 
        }

        if (m<0||n<0) return INT_MAX;

         if (dp[m][n]!=-1) return dp[m][n];

         
        int up = f2(m,n-1, grid, dp); 
        int left =  f2(m-1, n, grid, dp); 
        
        int resUp = (up == INT_MAX) ? INT_MAX : grid[m][n] + up;
            int resLeft = (left == INT_MAX) ? INT_MAX : grid[m][n] + left;

            return dp[m][n] = min(resUp, resLeft);
     

    }






    int minPathSum(vector<vector<int>>& grid) {
  
       int m=grid.size(); 
       int n= grid[0].size(); 
       vector <vector <int>> dp(m, vector<int> (n,-1));
       return f(m-1,n-1,grid);   

    }
