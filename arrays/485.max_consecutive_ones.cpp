/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = INT_MIN ; 
        int cnt =0;

        for (int k=0 ; k<nums.size() ; k++)
        {
            if (nums[k]==0)
            {
                cnt =0 ; 
               
            } 
            
            if (nums[k]==1) cnt +=1 ; 
            ans = max(cnt , ans);
            
        }
        return ans ; 

      
        
    }
};
