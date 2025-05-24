#include <bits/stdc++.h>
using namespace std; 


int getLongestSubarray1(vector <int> a , long long  k)
{
  int n= a.size(); 
  int len=0; 

  for (int i=0; i<n;i++)
  {
    for (int j=i ; j<n;  j++)
    {long long s=0; 
      for (int k=i ; k<=j ; k++)
      { s=s+a[k]; }

      if (s==k)
      len=max(len, j-i+1); 
    }
  }
  return len; 

// TC : O(N^3) , SC- O(1)
}



int getLongestSubarray2(vector <int> a , long long  k)
{
  int n= a.size(); 
  int len=0; 

  for (int i=0; i<n;i++)
  {long long s=0; 
    for (int j=i ; j<n;  j++)
    {
      

        s=s+a[j]; 
      

      if (s==k)
      len=max(len, j-i+1); 
    }
  }
  return len; 
  //// TC : O(N^2) , SC- O(1)
}


int getLongestSubarray3(vector <int> a , long long  k) // USING HASHMAPS 
{
  int n=a.size(); 
  map <long long , int> presummap; 
  long long sum =0; 
  int maxlen= 0; 

  for (int i=0; i<n; i++)
  {
    sum=sum+a[i];

    if (sum==k)
    {maxlen= max(maxlen, i+1); }

    long long rem = sum-k; 

    if (presummap.find(rem)!=presummap.end())
    {
      int len = i-presummap[rem]; 
      maxlen= max(maxlen, len); 
    }

    if (presummap.find(sum)== presummap.end())
    {
      presummap[sum]=i; 
    }
  }
  return maxlen;
}


int getLongestSubarray4(vector <int> a , long long  k)
{
  int l=0; 
  int r= 0;
  long long sum=a[0]; 
  int maxlen=0; 
  int n=a.size(); 

  while (r<n){
  while (l<= r && sum>k)
  {
    sum=sum-a[l]; 
    l++; 

  }

  if (sum==k)
  {
    maxlen = max(maxlen, r-l+1); 
  }

  r++; 
  if (r<n) sum=sum+a[r]; 
}
return maxlen; }



int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len1 = getLongestSubarray1(a, k);
    int len2 = getLongestSubarray2(a, k);
    int len3 = getLongestSubarray3(a, k);
     int len4 = getLongestSubarray4(a, k);
    cout << "The length of the longest subarray is: " << len1 << "\n";

     cout << "The length of the longest subarray is: " << len2 << "\n";

      cout << "The length of the longest subarray is: " << len3 << "\n";

       cout << "The length of the longest subarray is: " << len4 << "\n";
    return 0;
}
