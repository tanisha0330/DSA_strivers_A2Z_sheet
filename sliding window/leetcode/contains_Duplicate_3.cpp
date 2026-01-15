/*
You are given an integer array nums and two integers indexDiff and valueDiff.
Find a pair of indices (i, j) such that:
i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.
*/



//brute_force : this willl give us  tle 
class Solution {
public:
    bool brute_containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size(); 
        bool ans =false ; 
        for (int i=0 ; i<n; i++)
        for (int j=i+1 ; j<n && abs(j-i)<=indexDiff ;j++)
        {
            if (abs(nums[i]-nums[j])<=valueDiff) ans= true ; 
        }
        return ans ;
        
    }
};



//OPTIMAL 

