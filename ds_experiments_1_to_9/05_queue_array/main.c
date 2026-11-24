#include <stdio.h>
#define MAX 5
int q[MAX],front=0,rear=-1;
int enqueue(int x){if(rear==MAX-1){puts("Queue Overflow");return 0;}q[++rear]=x;return 1;}
int dequeue(int *x){if(front>rear){puts("Queue Underflow");return 0;}*x=q[front++];return 1;}
void display(void){int i;if(front>rear){puts("Queue is empty");return;}printf("Queue: ");for(i=front;i<=rear;i++)printf("%d ",q[i]);puts("");}
int main(void){int n,i,x;printf("Number of elements (max 5): ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;
 for(i=0;i<n;i++){printf("Element: ");if(scanf("%d",&x)!=1)return 1;enqueue(x);}
 puts("Before DEQUEUE:");display();if(dequeue(&x))printf("Dequeued: %d\\n",x);puts("After DEQUEUE:");display();return 0;
}
