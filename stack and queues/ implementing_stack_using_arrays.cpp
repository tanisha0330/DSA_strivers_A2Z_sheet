#include <bits/stdc++.h>
using namespace std;
class Stack {
  int size; 
  int _top; 
  int * arr; 
public: //constructor
    Stack(int capacity=1000) {
      _top=-1; 
      size=capacity;; 
      arr=new int[size];
     
    }
    
    void push(int x) {
      if (_top>=size-1)
      {
        cout<<"stack overflow"<<"\n";
        }
      _top++; 
      arr[_top]=x;
   
    }
    
    int pop() {
      if (_top==-1) {cout<<"the stack is emptty"<<endl;}
      int x=arr[_top];
      _top--; 
    }
    
    int top() {
      return arr[_top];
    
    }

    
    bool isEmpty() {
      while (_top==-1){
        _top=_top-1;
      }

  
    }
};

int main(){
  Stack s; 
 s.push(6);
  s.push(3);
  s.push(8);
  s.push(7); 
  cout<<s.top()<<" ";
  s.pop();
  cout<<s.top();
 

}
