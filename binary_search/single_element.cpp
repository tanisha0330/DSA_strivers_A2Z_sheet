#include <bits/stdc++.h>
using namespace std; 

int single_element1(vector <int> arr)
{
int n= arr.size(); 
if (n==1) return arr[0]; 
if (n==0) return -1; 

for (int i=0; i<n; i++)
{
  if (i==0)
  {
    if (arr[i]!=arr[i+1]) return arr[i]; }
    else if (i==n-1) 
    {
      if (arr[i]!=arr[i-1]) return arr[i]; 
    }
    else 
    {if (arr[i]!=arr[i+1]&& arr[i]!=arr[i-1])
    {return arr[i];}}
  
}
// TC: O(N) SC: O(1)
}



int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}// TC:  O(N) ,  SC: O(1) 


int single_element2(vector<int> arr)
{
  int n=arr.size(); 
  if (n==1) return arr[0]; 
if (arr[0]!=arr[1]) return arr[0]; 
if (arr[n-1]!=arr[n-2]) return arr[n-1]; 
int low =1; 
int high=n-2; 

while (low<=high)

{
  int mid=low+(high-low)/2;

if (arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
{
return arr[mid];
}
 //elimination 

 //in left 
 if ( (mid  % 2 ==1 && arr[mid]==arr[mid-1])||(mid%2==0 && arr[mid]==arr[mid+1]))
      low =mid+1;

 else high=mid-1;

}
return -1;

//TC:  O(logN), N = size of the given array.
//SC: O(1)
}





int main()
{
   vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = single_element1(arr);
    int ans2 = single_element2(arr);
    cout << "The single element is: " << ans << "\n";
     cout << "The single element is: " << ans2 << "\n";
    return 0;
}