#include <bits/stdc++.h>
using namespace std;

class Solution {
  public: 
  void sumarr(int index, vector<int> &result, vector<int> &nums, int sum)
  {
    int n= nums.size(); 
          if (index == n) {
            result.push_back(sum); 
            return;
        }
   
      
       sumarr(index +1, result,  nums,  sum+nums[index]);

       sumarr(index +1, result,  nums,  sum);

    
    
  }

public:
    vector<int> subsetSums(vector<int>& nums) {
        
        vector<int> result;
        int index=0; 
        int sum =0; 
        sumarr(index, result, nums, sum); 
        // ...
        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1,2, 3};

    // Call the function
    vector<int> output = sol.subsetSums(nums);

    // Print the result
    for (int sum : output) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
