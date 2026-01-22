class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size() ; 
        int high =n-1 ; 
        int low = 0 ;
        int ans =nums.size() ;  

        while(high >= low )
        {
            int mid = (high +low)/2 ; 
            if (target <= nums[mid]) 
            {
                ans =mid ; 
                high = mid-1 ; 
            }
            else 
                low = mid+1 ;
            
            if (target == nums[mid]) return mid ; 


            }
            return ans ; 
            
    }
};
