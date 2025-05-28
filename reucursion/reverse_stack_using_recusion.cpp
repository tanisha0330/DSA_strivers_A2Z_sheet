#include <bits/stdc++.h>
using namespace std; 

void insert_element(stack <int> & st,int element)
{
  if (st.empty())
  {
    st.push(element); 
    return ; 
  }

  int temp = st.top(); 
  st.pop(); 

  insert_element(st, element); 
  st.push(temp); 

}


void empty_stack(stack<int> &st)
{
if (st.empty()) return  ; 
int temp = st.top(); 
st.pop(); 
empty_stack(st); 
insert_element(st,temp); 

}
 

int main()
{
  stack <int> st; 
  st.push(7); 
  st.push(3); 
  st.push(5); 
  st.push(2); 
  st.push(4); 
  st.push(1);
  

  while (!st.empty())
  {cout<<st.top()<<" "; 
  st.pop();}
  cout<<endl; 

  st.push(7); 
  st.push(3); 
  st.push(5); 
  st.push(2); 
  st.push(4); 
  st.push(1);
  
  empty_stack(st); 


  while (!st.empty())
  {cout<<st.top()<<" "; 
  st.pop();}
  return 0;  

}
