#include<bits/stdc++.h>
using namespace std; 

 set<vector<int>> uniqueSubs;  /// declare a global variable , 

// functnio to store 


// to return all subsequences 

void printsub(int arr[], int n,int target, int index=0, vector <int> curr={},int sum=0)
{  
  if (index==n)
  {
    if (target==sum)
    { vector <int> temp = curr; 
      sort(temp.begin(), temp.end());  // sort before storing to normalize [1,2] and [2,1]
      uniqueSubs.insert(temp);

    /* for (int x:curr)
      {
        cout<<x<<" ";
      }
      cout<<endl;*/
    }
    return;
  }

  curr.push_back(arr[index]);
  printsub(arr,n,target, index+1,curr,sum+arr[index]);
  curr.pop_back();

  printsub(arr,n,target,index+1,curr,sum);
  sum=sum-arr[index];
}






int main(){
  int arr[]={1,2,3, 1, 1, 1};  // but here we are getting repeated results. - > so this only when we are having unique elements . -> to solve this you can store them in a set after getting the list of vectors and before storing make sure to sort them .
  int n=sizeof(arr)/ sizeof(arr[0]);
  int target=3; 

  cout<<"all non empty subsequences : "<<endl;
  printsub(arr,n,target);
 cout << "All unique subsequences that sum to target:" << endl;
    for (const auto &subset : uniqueSubs)
    {
        for (int x : subset)
            cout << x << " ";
        cout << endl;
    }

  return 0;
}
