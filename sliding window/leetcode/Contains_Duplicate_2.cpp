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



class Solution {
public:

    bool optimal_containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> last_index; 
        int n = nums.size(); 

        for (int i=0 ; i<n; i++)
        {
            if (last_index.count(nums[i])==true)
            {
                if (abs(i-last_index[nums[i]])<=k)
                return true ; 
            }
            last_index[nums[i]] =i ;
        }
        return false ; 
    }
};
