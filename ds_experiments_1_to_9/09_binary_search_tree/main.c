#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node *left,*right;};
struct Node *insert(struct Node *r,int x){if(!r){r=malloc(sizeof *r);if(!r){perror("malloc");exit(1);}r->data=x;r->left=r->right=NULL;}
 else if(x<r->data)r->left=insert(r->left,x);else if(x>r->data)r->right=insert(r->right,x);return r;}
void inorder(struct Node *r){if(r){inorder(r->left);printf("%d ",r->data);inorder(r->right);}}
void preorder(struct Node *r){if(r){printf("%d ",r->data);preorder(r->left);preorder(r->right);}}
void postorder(struct Node *r){if(r){postorder(r->left);postorder(r->right);printf("%d ",r->data);}}
void freeTree(struct Node *r){if(r){freeTree(r->left);freeTree(r->right);free(r);}}
int main(void){struct Node *root=NULL;int n,i,x;printf("Number of values: ");if(scanf("%d",&n)!=1||n<0)return 1;
 for(i=0;i<n;i++){printf("Value: ");if(scanf("%d",&x)!=1){freeTree(root);return 1;}root=insert(root,x);}
 printf("Inorder (sorted): ");inorder(root);printf("\\nPreorder: ");preorder(root);printf("\\nPostorder: ");postorder(root);puts("");freeTree(root);return 0;
}
