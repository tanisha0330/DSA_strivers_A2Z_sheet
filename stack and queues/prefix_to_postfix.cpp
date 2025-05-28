#include <bits/stdc++.h>
using namespace std; 



/*logic :  start readiung the string from right to left - whenevr u encounter a operator - just reverse last 2 charachters from resultant stack and push the operator- these reversal can be done by ooping one by one and pushing with operand*/


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfic(string prefix)
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
    string combined = op1+op2+c; 
    st.push(combined); 
    }
  }
return (st.size()==1)? st.top(): "envalid expression"; 
}



int main ()
{
  string prefix = "*+AB-CD"; 
  string postfix= prefixToPostfic(prefix); 
  cout<<"postfix expression: "<<postfix<< endl; 
}

/*
For prefix: *+AB-CD

Read D → push

Read C → push
{DC}
Read - → pop C, D → combine CD- → push
{CD-}
Read B → push

Read A → push
{BA}
Read + → pop A, B → combine AB+ → push
{AB+}
Read * → pop AB+, CD- → combine AB+CD-* → boom 💥
*/