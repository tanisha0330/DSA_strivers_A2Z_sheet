#include <bits/stdc++.h>
using namespace std; 
class Node{
  public: 
  int data; 
  Node* next; 

  public: 
  Node(int data1, Node* next1=nullptr){
    data=data1; 
    next =next1; 
  }
};

Node* converArr2LL(vector<int>&arr){
Node* head=new Node(arr[0]); 
Node* mover=head;
for (int i =1; i<arr.size(); i++){
  Node * temp = new Node(arr[i]);
  mover->next=temp; 
  mover=temp;
}
return head;

}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next; 
  }
  cout<<endl;
}

int lengthofLL(Node*head){
  int cnt=0;
  Node* temp=head;
while(temp){
  temp=temp->next;
  cnt++;

}
return cnt;

}

int checkIfPresent(Node* head, int val){
  Node* temp=head;
while(temp){
  if (temp->data==val) {return 1;}
  temp=temp->next;
}
return 0;
}

Node* removeHead(Node* head){
  if (head==NULL) return head; 
  Node* temp=head; 
  head=head->next; 
  free(temp);
  return head; 
}

Node* removeTail(Node* head){
  if (head==NULL || head->next==NULL){
    return NULL;
  }
  Node* temp = head;
while (temp->next->next!=NULL){
   temp=temp->next;
  }
  delete(temp->next);
  temp->next=nullptr;
  return head;
}

Node* removek(Node* head, int k){
  if (head==NULL) return head;
  if (k==1){
    Node*temp=head; 
    head=head->next;
    free(temp); 
    return head; 
  }

  int cnt= 0; 
  Node* temp=head; 
  Node* prev=NULL; 
  while(temp!= nullptr){
    cnt++; 
    if (cnt==k){
      prev->next= prev->next->next;
      free(temp); 
      break;
  }
  prev=temp; 
  temp=temp->next; 

}
return head;
}

Node* inserthead(Node* head, int val){
  Node* temp=new Node(val,head);
  return temp;
}

Node* insertTail(Node* head, int val){
  if (head==NULL){
    return new Node(val);
  }
  Node* temp=head; 
  while(temp->next!=NULL){
       temp=temp->next; 
  }
  Node* newNode=new Node(val);
  temp->next=newNode;
  return head;
  }
  
  Node* insertk(Node*head, int val, int k){
   
    if (head==NULL){
      if (k==1) return new Node(val); 
      else return NULL;
    }
    int count=0;
    Node* prev=NULL; 
    Node* temp = head; 
    while(temp->next!=NULL){
      temp=temp->next; 
      count++; 
    if (count==(k-1)){
      Node* x=new Node(val,temp->next); 
      temp=x; 
      break; 

    }
   
  }
  return head; 

     
      

    }

  






int main(){

  vector<int> arr={123,5,8,7}; 



  Node*head =converArr2LL(arr);


head=insertk(head,900,2); 
print(head);
// time complexity is big o of k;
//deletion of head 


}
  
 