#include<bits/stdc++.h>
using namespace std; 
void helper(vector <vector<char>> &ans,string &input, int index , vector<char> & list1)
{

  if (index==input.size())
  {ans.push_back(list1);
  return; }

// to include current char
  list1.push_back(input[index]); 
  helper (ans, input, index+1, list1);

// to exclude current char
  list1.pop_back();
  helper (ans, input, index+1, list1);
 

}


vector <vector<char>> generate(string &input)
{
  vector <vector<char>> ans; 
  int index=0; 
  vector<char> list1; 
  helper (ans, input, index, list1); 
  return ans;

}


void print(const vector<vector<char>> &ans)
{
  for (const auto &subset : ans)
  {
    for (char ch: subset)
      cout<<ch; 
    cout<<endl; 
  }
}

/*
for (const auto &subset : ans)
This loop goes through each subset inside the list of subsets (ans).

auto means: “Compiler, you figure out the type.” Here, subset becomes vector<char>.

const & is used to avoid copying and to be safe from accidental edits. (Good habit ✨)


**  for (char ch : subset)
This loop goes through each character in the current subset.


*/


int main()
{
  string input = "abc"; 
 vector<vector<char>> allsubsets=  generate(input); 
 print(allsubsets); 
 return 0;
  

}
