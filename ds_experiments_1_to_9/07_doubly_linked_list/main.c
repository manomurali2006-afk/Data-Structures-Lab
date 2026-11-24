#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node *prev,*next;};
void freeList(struct Node *p){while(p){struct Node *t=p;p=p->next;free(t);}}
int main(void){struct Node *head=NULL,*tail=NULL,*p;int n,i,x;
 printf("Number of nodes: ");if(scanf("%d",&n)!=1||n<0)return 1;
 for(i=0;i<n;i++){printf("Data: ");if(scanf("%d",&x)!=1)goto bad;p=malloc(sizeof *p);if(!p)goto bad;
 p->data=x;p->next=NULL;p->prev=tail;if(tail)tail->next=p;else head=p;tail=p;}
 printf("Forward: ");for(p=head;p;p=p->next)printf("%d <-> ",p->data);puts("NULL");
 printf("Backward: ");for(p=tail;p;p=p->prev)printf("%d <-> ",p->data);puts("NULL");freeList(head);return 0;
bad: puts("Input or allocation error");freeList(head);return 1;
}
