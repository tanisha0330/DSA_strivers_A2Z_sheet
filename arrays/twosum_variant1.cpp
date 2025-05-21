#include <bits/stdc++.h>
using namespace std; 
//  Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

// defining two sum function 


string brute_twoSum(int n,vector <int> arr,int target)
{
  for (int i=0; i<n; i++){
    for (int j=i+1; j<n; j++)
    {
      if (arr[i]+arr[j]==target) return "YES";} }
      return "NO";
// TC: O(N^2) ; N- size of the array
//sc =O(1); 
}


string better_hashmaps_twoSum(int n, vector <int> arr, int target )
{
  unordered_map <int, int> mpp; 
  for (int i=0; i<n; i++)
  {
    int num=arr[i]; 
    int rest=target-num; 
    if (mpp.find(rest)!=mpp.end())
    {return "YES";}
    
  mpp[num]=i; 
  }
  return "NO";
  //single iteration - TC= O(N);  SC=O(N); 
}

string optimal_twopointers_twoSum(int n, vector <int> arr, int target )
{
  sort (arr.begin(), arr.end()); 
  int low=0; 
  int high= n-1; 
  
  while (low<high)
  {
  int sum=arr[high]+arr[low];      // define sum inside while loop -as will be changing.
  if (sum==target) return "YES"; 
  else if (sum>target)
  {high=high-1; }
  else 
  { low=low+1;}
  }

  return "NO"; 

  
  
}



int main()
{
  //taking the target as input 
  int target=7; 
  cout << "enter the target value ";
 // cin>> target; 


vector <int> arr={2,6,5,8,11}; 
int n= arr.size(); 

cout <<"answer from brute force "<<
brute_twoSum(n,arr,target) <<endl; 


// as a better approach we can use hashing , storing the sum of elements - traversing once and check if target-arr[i] exist previosly or not . 

cout<<"using hashmaps and a better approach :"<<better_hashmaps_twoSum(n,arr,target)<<endl; 



// we can still optimize the space , so we can use the 2 pointer approach. (sorting - 2 pointers at high and low )


cout<<"using two pointer and optimal approach :"<<optimal_twopointers_twoSum(n,arr,target)<<endl;




}

