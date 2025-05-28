#include<bits/stdc++.h>
using namespace std; 

// to return all subsequences 

bool printsub(int arr[], int n,int target, int index=0, vector <int> curr={},int sum=0)
{  
  if (index==n)
  {
    if (target==sum)
   { return true ;}
    else return false;
  }

  curr.push_back(arr[index]);
  sum=sum+arr[index];
  if (printsub(arr,n,target, index+1,curr,sum)==true){return true;}

  
  curr.pop_back();
  sum=sum-arr[index];
  if (printsub(arr,n,target,index+1,curr,sum)==true){return true;}
  return false;
  

 

}






int main(){
  int arr[]={1,2,3};
  int n=sizeof(arr)/ sizeof(arr[0]);
  int target=3; 

  cout<<"all non empty subsequences : "<<endl;
  cout<<printsub(arr,n,target);
  return 0;
}