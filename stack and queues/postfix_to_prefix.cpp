#include <bits/stdc++.h>
using namespace std;


// this time it is operator - operand 1 - operand 2 ; 
// postfix = "AB+CD-* --> prefix - *+AB-CD
 bool isOperator(char c)
 {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
 }

string postfixToPrefix(string postfix)
{
  stack <string> st; 
  for (int i=0; i<postfix.size(); i++)
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
    string combined = c+op2+op1; 
    st.push(combined); 
    }
  }
return (st.size()==1)? st.top(): "envalid expression"; 
}


int main() {
    string postfix = "AB+CD-*";
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}