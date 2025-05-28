#include <bits/stdc++.h>
using namespace std; 


/*
Given a prefix expression like:
*+AB-CD
We want to convert it to an infix expression:
((A+B)*(C-D))
*/
 

/*
if operand - push ; 
if operator - > pop 2 , 
combine as : operand1->operator-> operand 2;
pushback to stack ; 

*/

bool isOperator(char c)
{return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');}


string prefixToInfix(string prefix)
{
  stack <string> st; 
  for (int i=prefix.size()-1; i>=0; i--)
  {
    char c= prefix[i]; 


    // if operand , push as string 

    if (isalnum(c))
    {
      st.push(string(1,c)); 
    }

    else if (isOperator(c))
    {{
      if (st.size()<2)
      return "invalid string"; 
    }
    string op1= st.top(); st.pop(); 
    string op2= st.top(); st.pop(); 
    string combined = "("+op1 + c + op2 + ")"; 
    st.push(combined); 
    }
  }
return (st.size()==1)? st.top(): "invalid expression"; 
}



int main() {
    string prefix = "*+AB-CD";
    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}