/*Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist*/

#include <bits/stdc++.h>
using namespace std; 
void Bruteforcegetelements(int arr[], int n)
{
   if (n<=1) cout<<"no second largest element exist" ; 
   
   else 
   {
    sort(arr, arr+n); 
     int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
   }
}

void optimal_get_elements(int arr[], int n )
{
  int largest =INT_MIN; 
  int sec_largest=largest; 
  int mini =INT_MAX; 
  int sec_min=INT_MAX; 
  if (n<=1) {cout<<-1; }

  for (int i=0; i<n; i++)
  {
    if (arr[i]>largest )
    {
      sec_largest=largest;
      largest=arr[i]; 
       

    }
    else if (arr[i]>sec_largest && arr[i]!=largest)
    {
      sec_largest=arr[i];
    }
   
  }

  for (int j=0; j<n; j++)
  {
     if (arr[j]<mini)
    {
      sec_min = mini; 
      mini=arr[j]; 


       
    }
    else if (arr[j]<sec_min && arr[j]!=mini)
    {
      sec_min=arr[j]; 
    }
  }
  cout<<"second largest by better approach is : " << sec_largest<<endl;
  cout<<"smallest by better approach is : "<< sec_min;


}
int main(){
  int arr[]= {1,8,4,6,7,5}; 
  int n=sizeof(arr)/sizeof(arr[0]); 
  Bruteforcegetelements(arr,n); 
  cout<<endl; 
 optimal_get_elements(arr,n); 
  return 0; 
}
