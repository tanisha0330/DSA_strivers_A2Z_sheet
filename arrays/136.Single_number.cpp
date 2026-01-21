/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       //best XOR approach
       int ans =0; 
     
       for (int i=0 ; i<nums.size() ; i++)
       {
        ans = nums[i]^ans;
       }
        return ans ;
    }
};

/*********************************************************************************/
//brute 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp=0; 
        for (int i=0; i<nums.size(); i++){
            temp=temp^nums[i];
   
    }
    return temp;
}};


/*********************************************************************************/
// by hashmaps 


class Solution {
public:
    int singleNumber(vector<int>& nums)
     {
       
       unordered_map<int , int> map ; 
     
       for (int i=0 ; i<nums.size() ; i++)
       {
        map[nums[i]] +=1 ; 
       }


        for (auto it : map) {
            if (it.second == 1) {
                return it.first;
            }}

        return -1 ; 
    }
};



