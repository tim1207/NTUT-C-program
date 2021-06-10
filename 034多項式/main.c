#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define charLen 1000
struct linklist
{
    int pow;
    struct linklist *prev;
}typedef LinkList;
void output(LinkList *ls){
    LinkList *loop = ls;
    int allZero=1;
    while (loop->prev != NULL)
    {
        if(loop->pow!=0){
            allZero=0;
        }
        if(allZero==0)
            printf("%d ",loop->pow);
        loop  = loop->prev;
    }
    printf("%d\n",loop->pow);
}
void input(char *s){
    memset(s,'\0',charLen);
    fgets(s,100,stdin);
    if(s[strlen(s)-1]=='\n'){
        s[strlen(s)-1]='\0';
    }
}
int main(){
    LinkList *a = calloc(1,sizeof(LinkList));
    LinkList *b =calloc(1,sizeof(LinkList));
    int aN=0,bN=0;
    char s[charLen]={0};
    input(s);
    char *split = strtok(s," ");
    a->pow = atoi(split);
    split = strtok(NULL," ");

    while ( split != NULL)
    {
        
        LinkList *temp = calloc(1,sizeof(LinkList));
        temp->pow = atoi(split);
        temp->prev = a;
        a = temp;
        split = strtok(NULL," ");
        aN++;
    }
    
    input(s);
    split = strtok(s," ");
    b->pow = atoi(split);
    split = strtok(NULL," ");

    while ( split != NULL)
    {
        
        LinkList *temp = calloc(1,sizeof(LinkList));
        temp->pow = atoi(split);
        temp->prev = b;
        b = temp;
        split = strtok(NULL," ");
        bN++;
    }
    
    


    //printf("N:%d %d\n",aN,bN);
    int maxN = aN>bN?aN:bN;
    int sumN = aN+bN;
    LinkList *add = calloc(1,sizeof(LinkList*));
    LinkList *sub = calloc(1,sizeof(LinkList));
    LinkList *mul = calloc(1,sizeof(LinkList));
    LinkList *loopA=a;
    LinkList *loopB=b;
    add->pow = loopA->pow + loopB->pow;
    sub->pow = loopA->pow - loopB->pow;
    for(int i = 0 ; i < maxN ;i++){
        int aVal = 0 ,bVal = 0;
        if(loopA->prev != NULL)
        {
            loopA = loopA->prev;
            aVal = loopA->pow;
        }
        if(loopB->prev != NULL)
        {
            loopB = loopB->prev;
            bVal = loopB->pow;
        }
        LinkList *temp = calloc(1,sizeof(LinkList));
        temp->pow = aVal+bVal;
        temp->prev = add;
        add = temp;
        temp = calloc(1,sizeof(LinkList));
        temp-> pow = aVal-bVal;
        temp->prev = sub;
        sub = temp;
        //printf("i: %d\n",i);
    }
    for(int i = 0 ; i < sumN ; i++){
        LinkList *temp = calloc(1,sizeof(LinkList));
        temp->pow=0;
        temp->prev = mul;
        mul = temp;
    }
    //output(mul);
    //output(a);
    //output(b);
    loopA = a;
    

    for(int i = 0 ; i <= aN ;i++){
        loopB = b;
        for(int j = 0 ; j <= bN;j++){
            //printf("%d %d\n",loopA->pow,loopB->pow);
            int idx = i+j;
            //printf("idx: %d\n",idx);
            LinkList *temp = mul;
            for(int m = sumN ;m>idx;m--){
                temp= temp->prev;
            }
            temp->pow+= loopA->pow * loopB->pow;
            //printf("%d ",temp->pow);
            loopB = loopB->prev;
        }
        //printf("\n");
        loopA = loopA->prev;
    }
    output(add);
    output(sub);
    output(mul);
}


/*
***本題務必使用 Link List***

輸入兩個多項式，輸出相加、相減、相乘的結果。例如:

2x^4 + 3x^3 + x -1
x^5 - x^3 + 4x^2 - 3x +2
結果：
x^5 + 2x^4 + 2x^3 + 4x^2 - 2x + 1
-x^5 + 2x^4 + 4x^3 - 4x^2 + 4x - 3
2x^9 + 3x^8 - 2x^7 + 6x^6 + 5x^5 - 6x^4 + 11x^3 - 7x^2 + 5x - 2

輸入說明
輸入兩筆資料，分別代表兩個多項數。
每一筆輸入 n 個整數，第一個代表 n-1次方的係數，第 n 個代表 0 次方係數。

輸出說明
兩個多項式計算後從最高次方到0次方的係數，計算結果為0的係數也需印出。


Sample Input
2 3 0 1 -1
1 0 -1 4 -3 2

Sample Output
1 2 2 4 -2 1
-1 2 4 -4 4 -3
2 3 -2 6 5 -6 11 -7 5 -2

input
2 3 1 -1
1 0 -1 4 -3 2

output
1 0 1 7 -2 1
-1 0 3 -1 4 -3
2 3 -1 4 5 0 -1 5 -2
*/
