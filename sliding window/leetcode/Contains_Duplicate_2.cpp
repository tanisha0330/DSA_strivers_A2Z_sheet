//brute-force , this will give TLE 

class Solution {
public:

    bool brute_containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0 ; 
        
    
    while (l<=nums.size()-1)
    {
        int r=l+1; 
         while (r<=nums.size()-1)
        {
            if (nums[l]==nums[r] && abs(l-r)<=k)
            return true  ; 
            
            else 
            r++ ; 
        }
        l++; 
    }
       
    return false ; 
    }
};

