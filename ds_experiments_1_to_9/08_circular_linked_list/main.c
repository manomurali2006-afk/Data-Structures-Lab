#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node *next;};
int main(void){struct Node *head=NULL,*tail=NULL,*p,*t;int n,i,x;
 printf("Number of nodes: ");if(scanf("%d",&n)!=1||n<0)return 1;
 for(i=0;i<n;i++){printf("Data: ");if(scanf("%d",&x)!=1)goto bad;p=malloc(sizeof *p);if(!p)goto bad;p->data=x;
 if(!head){head=tail=p;p->next=head;}else{p->next=head;tail->next=p;tail=p;}}
 if(!head)puts("Circular list is empty");else{printf("Circular Linked List: ");p=head;do{printf("%d -> ",p->data);p=p->next;}while(p!=head);puts("(head)");}
 if(head){tail->next=NULL;while(head){t=head;head=head->next;free(t);}}return 0;
bad: puts("Input or allocation error");if(head){tail->next=NULL;while(head){t=head;head=head->next;free(t);}}return 1;
}
