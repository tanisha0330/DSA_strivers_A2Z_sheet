/*
We define a harmonious array as an array where the difference 
between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest
harmonious subsequence among all its possible subsequences.
*/
//optimal solution 

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count; 

        for (int i=0 ; i<nums.size() ; i++)
        {
            count[nums[i]]++ ; 
        }

        int maxi = 0 ; 
        
        for (auto &it : count)
        {
            int x = it.first ; 
            if (count.count(x+1))
            {
                maxi = max(maxi  , count[x]+count[x+1]);
            }
        }
        return maxi;

        
    }
};
