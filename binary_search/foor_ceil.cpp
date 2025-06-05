#include <bits/stdc++.h>
using namespace std; 
 

// finding floor and ciel 

int findfloor(int arr[], int n, int x)
{
  int low=0; 
  int high= n-1; 
  

  int ans=-1; 


  while (low<=high)
  {
     int mid= low+ (high-low)/2; 
     if (arr[mid]<=x)
     {
      ans=arr[mid]; 
      low=mid+1; 
     }
     else {high = mid-1; }
  }
  return ans; 
}



int findCeil(int arr[], int n, int x)
{
  int ans=-1; 
  int high= n-1; 
  int low=0; 

  for (int i=0; i<n; i++)
  {
    int mid=low+(high-low)/2; 

    if (arr[mid]>=x)
    {
      ans=arr[mid]; 
      high=mid-1; 
    }
    else low=mid+1; 
  }
  return ans;
}


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	int f = findfloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}
int main() {
	int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}