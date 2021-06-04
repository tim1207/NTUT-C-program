#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dfs(int goal,int *coinType,int k,int *book){
    int total = 0;
    int coin = 0;
    
    for(int i = 0 ; i < k ;i++){
        if(book[i] == -1)
            break;
        total += coinType[i]*book[i];
        //printf("book[%d]:%d\n",i,book[i]);
        coin += book[i];
    }
    //printf("total:%d\n",total);
    if(total == goal)
        return coin;
    int difference = goal-total;
    int min = 2147483647;
    for(int i = 0 ; i < k ;i++){
        if(book[i] == 0){
            book[i] = difference / coinType[i];
            if(book[i] == 0)
                book[i] = -1;
            //printf("book[%d]:%d\n",i,book[i]);
            
            int temp = dfs(goal,coinType,k,book);            
            book[i]=0;
            if(min > temp)
                min = temp;
        }
    }
    return min;

}
int main(){
    int k = 4;
    int goal = 18;
    int *coinType,*book;
    coinType = calloc(k,sizeof(int));
    book = calloc(k,sizeof(int));
    char s[100]={0};
    fgets(s,100,stdin);
    if(s[strlen(s)-1]=='\n')
        s[strlen(s)-1]='\0';
    char *split = strtok(s," ");
    for(int i = 0 ; i < k ;i++)    
    {
        coinType[i]=atoi(split);
        split = strtok(NULL," ");
    }

    
    printf("%d\n",dfs(goal,coinType,k,book));
}