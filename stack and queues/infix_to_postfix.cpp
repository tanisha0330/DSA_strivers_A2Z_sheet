#include <bits/stdc++.h>
using namespace std; 
 
int prec(char c)
{   // definig the priorities 
  if (c=='^') return 3; 
  else if (c=='/' || c=='*' ) return 2; 
  else if (c=='+' || c=='-' ) return 1; 
  else return -1; 
}

void infixToPostFix(string s)
{
  stack <char> st; 
  string result; 
for (int i =0; i<s.length(); i++)
  {char c= s[i]; 

      // adding normal charachters to result 
  if ((c>='a' && c<='z') || (c>='A' && c<='Z')|| (c>='0' && c<='9')) 
  {result=result+c; }


  // on encountering brackets
  else if (c=='(')
  st.push('('); 

  else if (c==')')
  {
    while (st.top()!='(')
    {result= result+ st.top(); 
    st.pop(); }
    st.pop(); }
  
  

  else // for operators 
   {
    while (!st.empty() && prec(s[i])<= prec(st.top()))  // lower next priority condition
    {result= result +st.top(); 
    st.pop();
  }
    st.push(c);    // normally pushing to the stack 
  }
}
 

while (!st.empty()) // remaining elements to the stack 
{
  result= result + st.top(); 
  st.pop(); 
}
cout << "Prefix expression: " << result << endl;

}


int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostFix(exp);
  return 0;
}