class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size() ; 
        int high =n-1 ; 
        int low = 0 ; 

        while(high >= low )
        {
            int mid = (high +low)/2 ; 
            if (target <nums[mid]) 
            {
                high = mid-1 ; 
            }
            else 
                low = mid+1 ; 

            if (nums[mid] ==target) return mid ; 
        }
        return -1 ; 
        
    }
};
