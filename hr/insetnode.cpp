#include<iostream>
using namespace std;
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   };
Node* createNode(int data){
    Node *nh=new Node();
    nh->data=data;
    nh->next=NULL;
    nh->prev=NULL;
    return nh;
}
Node* SortedInsert(Node *head,int data)
{
    if(!head){
        head=createNode(data);
        return head;
    }
    if(head->data > data){
        Node *nn=createNode(data);
        Node *pre=head->prev;
        if(!pre){
            nn->next=head;
            head->prev=nn;
            return nn;
        }
        else{
            pre->next=nn;
            nn->prev=pre;
            nn->next=head;
            head->prev=nn;
            return nn;
        }
    }
    head->next=SortedInsert(head->next,data);
    return head;
    // Complete this function
   // Do not write the main method.
}
void printhead(Node *head){
  // cout<<"in print head"<<endl;
  while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
}
int main(){
  Node *root=NULL;
  root=SortedInsert(root,1);
  root=SortedInsert(root,4);
  root=SortedInsert(root,2);
  root=SortedInsert(root,3);
  // root=SortedInsert(root,7);
  // root=SortedInsert(root,6);
  // root=SortedInsert(root,9);
  // root=SortedInsert(root,10);
  printhead(root);
  return 0;
}
