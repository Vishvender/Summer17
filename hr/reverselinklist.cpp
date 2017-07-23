#include<iostream>
using namespace std;
struct Node{
  public:
    int data;
    struct Node *next;
};
Node* createN(int data){
  Node *newnode=NULL;
  newnode=new Node();
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}
void printnode(Node* n){
  if(n){
    cout<<(n->data)<<" -> ";
    printnode(n->next);
  }
  else{
    cout<<"NULL";
  }
}
Node* Reverse(Node *head)
{
    if(head==NULL)
        return head;
    Node *rest=head->next;
    if(rest==NULL){
        return head;
    }
    cout<<"call from "<<head->data<<endl;
    Node *newhead=Reverse(rest);
    Node *temp=newhead;
    cout<<"new head data "<<temp->data<<endl;
    while(temp->next){
        temp=temp->next;
    }
    head->next=temp->next;
    temp->next=head;
    // cout<<" temp returned"<<temp->data<<endl;
    return newhead;
}
int main(void){
  Node *root;
  root=createN(2);
  root->next=createN(4);
  root->next->next=createN(6);
  printnode(root);
  cout<<endl;
  root=Reverse(root);
  printnode(root);
  return 0;
}
