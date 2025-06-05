#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 27;

    int low=1; 
    int high=n; 
    int k=3;

    while(low<=high)
    {
      int mid=low+ (high-low)/2;
      int ans=1; 

      for (int i=0; i<k;i++ )
      {ans = ans*mid; }

      if (ans<=n)low= mid+1; 
      else high=mid-1; 
    

    }
    
    cout<<high; 
}