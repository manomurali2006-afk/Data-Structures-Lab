#include <stdio.h>
#include <stdlib.h>
struct Student { int roll; char name[30]; float marks; };
void displayAll(struct Student *p,int n){int i;printf("\\nRoll\\tName\\t\\tMarks\\n");
 for(i=0;i<n;i++)printf("%d\\t%-15s %.2f\\n",(p+i)->roll,(p+i)->name,(p+i)->marks);}
int main(void){int n,i;struct Student *p;printf("Enter number of students: ");
 if(scanf("%d",&n)!=1||n<=0)return 1;p=malloc((size_t)n*sizeof *p);if(!p)return 1;
 for(i=0;i<n;i++){printf("Roll: ");if(scanf("%d",&(p+i)->roll)!=1)goto bad;
 printf("Name: ");if(scanf("%29s",(p+i)->name)!=1)goto bad;
 printf("Marks: ");if(scanf("%f",&(p+i)->marks)!=1)goto bad;}
 displayAll(p,n);free(p);return 0;
bad: puts("Invalid input");free(p);return 1;
}
