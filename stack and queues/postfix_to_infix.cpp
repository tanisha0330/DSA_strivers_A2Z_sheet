#include <bits/stdc++.h>
using namespace std; 


bool isOperator(char c)
{return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');}


string postfixToInfix(string postfix)
{
  stack <string> st; 
  for (int  i=0;i<postfix.size(); i++)
  {
    char c= postfix[i]; 


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
    string combined = "("+op2 + c + op1 + ")"; 
    st.push(combined); 
    }
  }
return (st.size()==1)? st.top(): "invalid expression"; 
}



int main() {
    string postfix = "AB-CD*+";
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}