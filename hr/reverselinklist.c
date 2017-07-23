#include<stdio.h>
struct Node{
  int data;
  struct Node *next;
};
struct Node* createN(int data){
  struct Node *newnode=NULL;
  newnode=(struct node*)malloc(sizeof(struct Node));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}
void printnode(struct Node* n){
  if(!n){
    printf("%d -> ",n->data);
    printnode(n->next);
  }
  else{
    printf("NULL");
  }
}
// Node* Reverse(Node *head)
// {
//     if(head==NULL)
//         return head;
//     Node *rest=head->next;
//     if(rest==NULL){
//         return head;
//     }
//     Node *temp=Reverse(rest);
//     while(temp->next){
//         temp=temp->next;
//     }
//     head->next=temp->next;
//     temp->next=head;
//     return temp;
// }
int main(void){
  struct Node *root;
  root=createN(2);
  root->next=createN(4);
  root->next->next=createN(6);
  printnode(root);
  return 0;
}
