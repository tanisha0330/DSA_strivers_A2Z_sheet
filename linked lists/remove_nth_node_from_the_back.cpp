
#include <bits/stdc++.h>
using namespace std; 

class Node{
  public:
  int Value; 
  Node*Next=NULL; };

void PrintLL(Node *node)
{
  while (node !=NULL)
  {
    cout<<node->Value<<"->";
    node=node->Next; 
  }
  cout<<"NULL"<<endl; 
}

Node* DeleteNthNodefromEnd(Node* head, int N) 
{
        if (!head) return nullptr;
        Node* slow=head; 
        Node* fast=head; 

        for (int i=0; i<n ; i++)
        {
            if (fast!=NULL){
            fast=fast->next; }
        }

         if (fast == NULL)
        return head->next;

        
        while (fast->next!=nullptr)
        {
            slow=slow->next; 
            fast=fast->next; 
        }

       
        if (slow->next) {
            Node* toDelete = slow->next;
            slow->next = slow->next->next;
            delete toDelete;
        }
        return head;
    }

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end 
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}
