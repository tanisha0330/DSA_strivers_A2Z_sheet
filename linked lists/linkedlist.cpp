#include <bits/stdc++.h>
using namespace std; 

class Node{
  public:
  int Value; 
  Node*Next=NULL; };

void PrintNode(Node *node)
{
  while (node !=NULL)
  {
    cout<<node->Value<<"->";
    node=node->Next; 
  }
  cout<<"NULL"<<endl; 
}
int main(){ 

  
  {
    Node*node1 = new Node; 
    node1->Value =7; 

    Node*node2 = new Node; 
    node2->Value =14; 

    Node*node3 = new Node; 
    node3->Value =21; 
     
  node1->Next=node2; 
  node2->Next=node3; 

    PrintNode(node1);
    return 0; 





};}



