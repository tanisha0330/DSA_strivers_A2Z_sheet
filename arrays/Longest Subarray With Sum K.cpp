int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i=0 ; 
    int j=0 ; 
    int maxi =0 ; 
    int n=a.size();
    int sum=0;  
    while (j<n)
    {
        
        sum+= a[j] ; 
        
        while (sum >k) 
        {
            sum-=a[i] ; 
            i++ ; } 
        
         
        if (sum==k) 
        {
            maxi = max(maxi , j-i+1) ; 
            
        }
        j++;
        
    }
    return maxi ; 
}
