class Solution {
  public:
    int lowerBound(vector<int>& nums, int target) {
        // code here

 
        int n=nums.size() ; 
        int high =n-1 ; 
        int low = 0 ; 
        int ans =n; // if ans =0 ; , so jab target array k sare numbers se bada hota to we cannot update any  ans variable accordingly.

        while(low <=high)
        {
            int mid = (high +low)/2 ; 
            if (target <= nums[mid]) 
            {
                ans =mid ; 
                high = mid-1 ; 
                
            }
            else 
                
                low = mid+1 ; 

        }
        return ans; 
        

    }
};
