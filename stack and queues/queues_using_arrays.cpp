#include <bits/stdc++.h>
using namespace std; 

class Stack {
  int size; 
  int end; 
  int * arr; 
  int start;
  int currsize=0;
public: //constructor
    Stack(int capacity=1000) {
      start=-1; 
      end=-1;
      size=capacity;
      arr=new int[size];
      
     
    }

    void push(int x){
      if (end>=size-1){cout<<"stack overflow";}
      if (currsize==0){
        end=0; start=0;}
      else{
        end=end+1;}

      currsize=currsize+1;
      arr[end]=x;
      
    }

    int pop(){
       if (currsize==0){cout<<"stack underflow!"<<endl;}
       if (currsize==1){
        start=end=-1;}
      else {
        start=start+1; 
        currsize=currsize-1;
      }
      return arr[start];
    }

    int top(){
      if (currsize==0){cout<<"no element present"<<endl;}
       
       // start=start+1; - you do not have to modify this. 
      
      
      return arr[start];

    }


    bool isEmpty(){
      if (currsize==0) return false;
      else return true; 
      }

    }
  ;//will return 1 if it is non empty

  int main(){
    Stack s;
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(7);
   s.push(1);
   s.push(9);
   cout<<s.top()<<endl;
   s.pop();
   cout<<s.top();
   cout<<s.isEmpty();




  }
