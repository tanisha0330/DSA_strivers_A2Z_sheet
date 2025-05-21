#include <bits/stdc++.h>
using namespace std; 




// Function to find leaders in the array
vector<int> Optimal_findLeaders(vector<int>& nums) {
   
    int  max=INT_MIN; 
    vector <int> ans;
     
    for (int i=nums.size()-1; i>0; i--)
  
    { if (i==nums.size()-1) 
      {max=nums[i]; 
      ans.push_back(nums[i]);}
     
     if (max<nums[i]){
        ans.push_back(nums[i]);
        max=nums[i];
      }
    }
    return ans;
}




vector<int> BruteForce_findleaders(vector <int> &nums)
{
  vector <int > ans; 
   
  for (int i=0; i<nums.size(); i++)

  { bool leaders=true; 
    for (int j=i+1; j<nums.size(); j++)
    {
      if (nums[j]>nums[i])
      {
        leaders=false; 
        break; 
      }}
      if (leaders==true){ans.push_back(nums[i]); }
    
  }
  return ans; 

}


int main() {
    vector<int> nums = {1, 2, 5, 3, 0, 1};

    vector<int> result = Optimal_findLeaders(nums);

    vector<int> result2=BruteForce_findleaders(nums); 
    

    cout << "Leaders: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    for (int val : result2) {
        cout << val << " ";
    }

    return 0;
}
