#include <bits/stdc++.h>
using namespace std; 

struct stackNode{
  int data; 
  stackNode* next; 
  int size; 
  stackNode(int d){
    data=d;
    next=NULL;
  }};

  //
  struct Stack{
    stackNode* top;
    int size; 
    Stack(){
      top=NULL;
      size=0;
    }

    void stackPush(int x){
      stackNode* element=new stackNode(x);
      element->next=top; 
      top=element;
      size=size+1;
    }

    int stackPop(){
      if(top==NULL) return -1;
      int topData=top->data;
      stackNode*temp=top;
      top=top->next;
      delete temp;
      return topData;
    }

    int stacktop(){
      return top->data;
    }

    void printstack(){
      stackNode* current=top; 
      while (current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;}
    }

  };
  


int main(){
  Stack s;
  s.stackPush(30);
  s.stackPush(20);
  s.stackPush(60);
  s.stackPush(90);
  s.stackPush(10);
  s.stackPop();
 cout<< s.stacktop();
  

 

}