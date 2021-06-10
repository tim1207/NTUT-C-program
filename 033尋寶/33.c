#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct hole_s
{
    int id;
    int gold;
    int walked;
    struct hole_s *n1;
    struct hole_s *n2;
} hole_t;

int search(hole_t *h,int total,int knowMax,char *answer){

    if(h->walked== 1 || (h->n1==NULL && h->n2==NULL)){
        if(h->walked==0)
            total+= h->gold;
        if(knowMax != 0 ){
            if(total == knowMax){
                printf("%s%d\n",answer,h->id);
            }
        }
        return total;
    }
    int max = 0;
    if (h->walked == 0 && (h->n1 != NULL || h->n2!=NULL ) )
    {
        total+= h->gold;
        h->walked=1;
        char *tempS = calloc(100,sizeof(char));
        sprintf(tempS,"%d ",h->id);

        strcat(answer,tempS);
        int temp=0,temp2=0;
        if(h->n1 != NULL)
            temp = search(h->n1,total,knowMax,answer);
        //printf("temp: %d\n",temp);
        if(h->n2 != NULL)
            temp2 = search(h->n2,total,knowMax,answer);
        //printf("temp2: %d\n",temp2);
        h->walked=0;
        answer[strlen(answer)-1] ='\0';
        answer[strlen(answer)-1] ='\0';
        if(temp > max)
            max = temp;
        if(temp2>max)
            max =temp2;
    }
    return max;
    
}

int main(){
    int K,N;
    scanf("%d %d",&N,&K);
    //printf("%d %d\n",K,N);
    hole_t *hole = calloc(N,sizeof(hole_t));
    for(int i = 0 ; i < N ;i++){
        hole[i].id=0;
        hole[i].gold=0;
        hole[i].walked=0;      
        hole[i].n1=NULL;
        hole[i].n2=NULL;
    }
    for(int i = 0 ; i < N ;i++){// 輸入處理
        
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        hole[i].id = a;
        hole[i].gold = b;
        if(c != 0)
        {
            hole[i].n1= &hole[c-1];
        }
        if(d != 0 )
        {
            hole[i].n2= &hole[d-1];
        }
    }
    char *output = calloc(100,sizeof(char));
    int m = search(&hole[K-1],0,0,output);// find max
    search(&hole[K-1],0,m,output);// print path

    printf("%d",m);
    /*
    for(int i =0;i<N;i++){
        free( &hole[i]);
    }*/
    //free(&hole[0]);
    return 0;
}




/*
小明獲得一個尋寶祕笈和一隻鑰匙 A，依此找到第一個山洞 (編號 1)，發現裡面有三個寶箱 (X, n1, n2)，用鑰匙打開第一個寶箱 X，發現裝著一些數量的黃金 G1 和另一支鑰匙 B。鑰匙 B 只能選擇打開第二 (n1) 或第三個 (n2) 寶箱的其中一個。兩個寶箱裡面裝有第二、三個山洞的第一個寶箱鑰匙。小明只能利用鑰匙 B 開啟其中一個寶箱 (n1 或 n2) 往下一個山洞尋寶。每一個山洞都和第一個山洞一樣有三個寶箱，其中一個藏有某數量的黃金和一把鑰匙開啟其他寶箱往下一個山洞尋寶。下一個山洞可能是空的山洞或是已經走過的山洞，若是如此則尋寶之旅結束，如下圖所示。請寫一個程式找出可以獲得最多黃金的山洞編號順序。 

https://imgur.com/a/uZO4pAP 


輸入說明： 
------------------------------------------------------------------------ 
第一行是二個整數，代表山洞個數 N，以及第一個進入的山洞編號 K 
之後 N 行，每一行有四個整數，分別是山洞編號、黃金數量、下一個可以前往的兩個山洞編號 

輸出說明： 
------------------------------------------------------------------------ 
從山洞編號 K 進入，獲得最多黃金的山洞編號順序 (若多條路徑排序輸出) 以及可獲得的黃金數量 


範例一： 
------------------------------------------------------------------------ 
input： 
5 1 
1 6 2 4 
2 5 3 4 
3 7 2 5 
4 4 2 5 
5 0 0 0 

output： 
1 4 2 3 2 
1 4 2 3 5 
22



input:
4 1
1 0 2 3
2 4 0 0
3 2 4 0
4 2 0 0
output:
1 3 4
1 2

*/