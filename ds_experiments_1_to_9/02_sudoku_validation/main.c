#include <stdio.h>
#define N 9
int validRows(int a[N][N]) {
 int r,c,s[10]; for(r=0;r<N;r++){for(c=0;c<10;c++)s[c]=0;
 for(c=0;c<N;c++){int v=a[r][c];if(v&&s[v])return 0;s[v]=1;}} return 1;
}
int validCols(int a[N][N]) {
 int r,c,s[10]; for(c=0;c<N;c++){for(r=0;r<10;r++)s[r]=0;
 for(r=0;r<N;r++){int v=a[r][c];if(v&&s[v])return 0;s[v]=1;}} return 1;
}
int validBoxes(int a[N][N]) {
 int r,c,i,j,s[10]; for(r=0;r<N;r+=3)for(c=0;c<N;c+=3){
 for(i=0;i<10;i++)s[i]=0;
 for(i=r;i<r+3;i++)for(j=c;j<c+3;j++){int v=a[i][j];if(v&&s[v])return 0;s[v]=1;}}
 return 1;
}
int main(void){int a[N][N],r,c,ok=1; puts("Enter 9x9 Sudoku board (0 for empty):");
 for(r=0;r<N;r++)for(c=0;c<N;c++){if(scanf("%d",&a[r][c])!=1)return 1;if(a[r][c]<0||a[r][c]>9)ok=0;}
 puts(ok&&validRows(a)&&validCols(a)&&validBoxes(a)?"Valid Sudoku Board":"Invalid Sudoku Board");return 0;
}
