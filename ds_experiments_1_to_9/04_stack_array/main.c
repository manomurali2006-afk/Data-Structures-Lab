#include <stdio.h>
#define MAX 5
int s[MAX],top=-1;
void push(int x){if(top==MAX-1)puts("Stack Overflow");else s[++top]=x;}
int pop(int *ok){if(top==-1){*ok=0;return 0;}*ok=1;return s[top--];}
void display(void){int i;if(top<0){puts("Stack is empty");return;}printf("Stack (top to bottom): ");for(i=top;i>=0;i--)printf("%d ",s[i]);puts("");}
int main(void){int n,i,x,y,ok;printf("Number of elements (max 5): ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;
 for(i=0;i<n;i++){printf("Element: ");if(scanf("%d",&x)!=1)return 1;push(x);}
 puts("Before POP:");display();y=pop(&ok);if(ok)printf("Popped: %d\\n",y);else puts("Stack Underflow");puts("After POP:");display();return 0;
}
