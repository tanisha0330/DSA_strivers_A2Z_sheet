// brute force approach 
   void sortArr(vector<int> &arr) {
        int n = arr.size(); 
        for (int i=0 ; i<n-1 ; i++)
        {
            for (int j=0 ; j<n-i-1 ; j++)
            {
                if (arr[j] >arr[j+1])
                {
                    swap(arr[j],arr[j+1]); 
                }      
            }
        }  
    }
};


// optimized approach 
   void sortArr(vector<int> &arr) {
        int n = arr.size(); 
        for (int i=0 ; i<n-1 ; i++)
        {  bool swapped =false ; 
            for (int j=0 ; j<n-i-1 ; j++)
            {
              
                if (arr[j] >arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    swapped =true; 
                }
              
            }
         if (swapped ==false) break ; 
        }  
    }
};

//more optimized code 

