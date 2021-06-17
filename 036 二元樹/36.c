#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

typedef struct _node {
    char value;
    struct _node *left;
    struct _node *right;
} node;

node* createNode(char value){
    node *nNode = (node *) malloc(sizeof(node));
    nNode->value = value;
    nNode->left = NULL;
    nNode->right = NULL;
    
    return nNode;
}

int search(char arr[], int start, int end, char value) {
    for (int i=start; i<=end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int height(node *node) {
    if (node) {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    } else {
        return 0;
    }
}

void printLevel(node *root, int level) {
    if (!root)
        return;
    if (level == 0)
        printf("%c", root->value);
    else if (level > 0) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void bfsTraversal(node *root) {
    for (int i=0; i<=height(root); i++) {
        printLevel(root, i);
    }
}

node* constructWithPreorder(char pre[], char in[], int in_start, int in_end) {
    static int preIndex = 0;
    
    if (in_start > in_end)
        return NULL;
    
    node *curNode = createNode(pre[preIndex++]);
    
    if (in_start == in_end)
        return curNode;
    
    int in_index = search(in, in_start, in_end, curNode->value);
    curNode->left = constructWithPreorder(pre, in, in_start, in_index-1);
    curNode->right = constructWithPreorder(pre, in, in_index+1, in_end);
    
    return curNode;
}
node* constructWithPostorder(char in[], char post[], int in_start, int in_end, int post_start, int post_end) {
    
    if (in_start > in_end || post_start > post_end)
        return NULL;
    
    node *curNode = createNode(post[post_end--]);
    
    if (in_start == in_end)
        return curNode;
    
    int in_index = search(in, in_start, in_end, curNode->value);
    curNode->left = constructWithPostorder(in, post, in_start, in_index-1,post_start, post_start + in_index - (in_start+1));
    curNode->right = constructWithPostorder(in, post, in_index+1, in_end, post_start - in_start + in_index, post_end);
    
    return curNode;
}

int main() {
    char pre[N], in[N], post[N];
    strcpy(pre, "");
    strcpy(post, "");
    for (int i=0; i<2; i++) {
        char order, buffer;
        char input[N+1];
        
        scanf("%c", &order);
        buffer = getchar();
        while (buffer != '\n' && buffer != EOF)
            buffer = getchar();
        
        fgets(input, N+1, stdin);
        while(input[strlen(input)-1] == '\n' || input[strlen(input)-1] == ' ')
            input[strlen(input)-1] = '\0';
            
        if (order == 'P')
            strcpy(pre, input);
        else if (order == 'I')
            strcpy(in, input);
        else if (order == 'O')
            strcpy(post, input);
    }
    
    node* root = (node *) malloc(sizeof(node));
    if (strcmp(pre, ""))
        root = constructWithPreorder(pre, in, 0, (int) strlen(in) - 1);
    else if (strcmp(post, "")){
        int postLength = (int) strlen(post) - 1;
        root = constructWithPostorder(in, post, 0, (int) strlen(in) - 1, 0, postLength);
    }
    bfsTraversal(root);
    printf("\n");
    
    return 0;
}


/*
給定前序或後序以及中序，產生唯一個Binary Tree，依序印出Tree的內容，印出順序，由上而下，由左而右印出。 

前序代碼：P 
中序代碼：I 
後序代碼：O 

-------------- 
輸入說明 

第一筆輸入前序、中序或後序代碼。 
第二筆輸入上一筆輸入種類尋訪的結果，大寫英文字母。 
第三筆輸入前序、中序或後序代碼。 
第四筆輸入上一筆輸入種類尋訪的結果，大寫英文字母。 

------------- 
輸出說明 

輸出為一二元樹的內容，由上而下，由左而右。 

範例一 
------------- 
Input: 
P 
ABCDEFGHI 
I 
BCAEDGHFI 

-------------- 
Output : 
ABDCEFGIH 


範例二: 
------------- 
Input: 
O 
CBEHGIFDA 
I 
BCAEDGHFI 

-------------- 
Output: 
ABDCEFGIH

*/