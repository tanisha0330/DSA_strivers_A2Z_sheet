#brute force 
class Solution:
    def sortArr(self, arr): 
        n = len(arr); 
        
        for i in range (n-1): 
            for j in range (n-1-i):
                if arr[j]>arr[j+1]:
                    arr[j],arr[j+1]=arr[j+1],arr[j]
#more optimized
class Solution:
    def sortArr(self, arr): 
        n = len(arr); 
        
        for i in range (n-1): 
            swapped=False
            for j in range (n-1-i):
                if arr[j]>arr[j+1]:
                    arr[j],arr[j+1]=arr[j+1],arr[j]
                    swapped=True
            if not swapped:
                break
        
