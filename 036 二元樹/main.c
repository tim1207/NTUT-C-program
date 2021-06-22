#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define len 1000
typedef struct node_s{
    char s;
    struct node_s *left;
    struct node_s *right;
}node_t;
typedef struct queue_s{
    struct node_s *current;
    struct queue_s *next;
}queue_t;
void createQueue(queue_t *queue,node_t *node){
    queue->current = node;
    queue->next =NULL;
}
void createNode(node_t *node){
    node->left= NULL;
    node->right=NULL;
    node->s ='\0';
}
void split(char *source,char delimiter,char *a,char *b){
    memset(a,'\0',len);
    memset(b,'\0',len);
    for(int i = 0 ; i < strlen(source) ; i++){
        if(source[i] == delimiter){
            strncpy(a,source,i);
            i++;
            for(int j=0;i<strlen(source);i++,j++){
                b[j]=source[i];
            }
            break;
        }
    }

}
int idx = -1;
/*
I
FDHGIBEAC
P
ABDFGHIEC
*/
void createTree(node_t *node,char *inorder,char *order,char orderCode){
    if(orderCode == 'P'){
        idx++;
        node->s=order[idx];
        if(strlen(inorder) > 1)
        {
            char aSplit[len],bSplit[len];
            split(inorder,order[idx],aSplit,bSplit);
            if(strlen(aSplit) > 0)
            {
                node_t *l = calloc(1,sizeof(node_t));
                createNode(l);
                node->left=l;
                createTree(l,aSplit,order,orderCode);
            }
            if(strlen(bSplit) > 0 )
            {
                node_t *r = calloc(1,sizeof(node_t));
                createNode(r);                
                node->right=r;
                createTree(r,bSplit,order,orderCode);   
            }
        }
    }else{
        idx--;
        node->s=order[idx];
        if(strlen(inorder) > 1)
        {
            char aSplit[len],bSplit[len];
            split(inorder,order[idx],aSplit,bSplit);
            if(strlen(bSplit) > 0 )
            {
                node_t *r = calloc(1,sizeof(node_t));
                createNode(r);                
                node->right=r;
                createTree(r,bSplit,order,orderCode);   
            }
            if(strlen(aSplit) > 0)
            {
                node_t *l = calloc(1,sizeof(node_t));
                createNode(l);
                node->left=l;
                createTree(l,aSplit,order,orderCode);
            }
            
        }
    }
}
int main(){
    char a[len],b[len],c[len],d[len];
    scanf("%s",&a);
    scanf("%s",&b);
    scanf("%s",&c);
    scanf("%s",&d);
    if(a[0] == 'O' || c[0] =='O'){
        idx = strlen(b);
    }
    node_t *root = calloc(1,sizeof(node_t));
    createNode(root);
    if(a[0] == 'I'){
        createTree(root,b,d,c[0]);
    }else{
        createTree(root,d,b,a[0]);
    }
    queue_t *last = calloc(1,sizeof(queue_t));
    createQueue(last,root);
    queue_t *q = last;
    while(q != NULL)
    {
        printf("%c",q->current->s);       
        if(q->current->left != NULL)
        {           
            queue_t *temp = calloc(1,sizeof(queue_t));
            createQueue(temp,q->current->left);        
            last->next = temp;
            last = temp;
        }
        if(q->current->right != NULL)
        {           
            queue_t *temp = calloc(1,sizeof(queue_t));
            createQueue(temp,q->current->right);        
            last->next=temp;
            last = temp;
        }
        q = q->next;
    }
    
}
