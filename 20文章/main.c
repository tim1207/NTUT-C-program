#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void input(char *s,int length){
    fgets(s,length,stdin);
    if( s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }
}
void cmp(const void* a ,const void* b){
    return strcmp(*(const char**)a , *(const char**)b);
}
int main()
{
    char A[1000];//="Can you can a can as a canner can can a can";
    char P[100];//="can";
    char Q[100];//="ban";
    input(A,1000);
    input(P,100);
    input(Q,100);

    char split[100][100];
    memset(split,'\0',sizeof(split));
    char *token = strtok(A," ");
    int splitLength;
    for( splitLength = 0 ; token != NULL ;splitLength++){
        strcpy(split[splitLength],token);

        //printf("%s\n",split[splitLength]);
        token = strtok(NULL," ");
    }
    //line 1
    for(int i = 0 ; i < splitLength ;i++){
        if( strcmp(split[i],P) == 0){
            printf("%s",Q);
        }else{
            printf("%s",split[i]);
        }
        if(i!=splitLength-1)
            printf(" ");
    }
    printf("\n");
    //line 2
    for(int i = 0 ; i < splitLength ;i++){
        if( strcmp(split[i],P) == 0){
            printf("%s %s",Q,P);
        }else{
            printf("%s",split[i]);
        }
        if(i!=splitLength-1)
            printf(" ");
    }
    printf("\n");
    //line 3
    for(int i = 0 ; i < splitLength ;i++){
        if( strcmp(split[i],P) == 0){
            continue;
        }else{
            printf("%s",split[i]);
        }
        if(i!=splitLength-1)
            printf(" ");
    }
    printf("\n");
    char dic[100][100];
    int count[100];
    for(int i = 0 ; i < 100;i++)
        count[i]=0;

    memset(dic,'\0',sizeof(dic));
    for(int i = 0 ; i < splitLength ;i++){
        for(int j = 0 ; j < 100 ; j++){
            if(dic[j][0] == '\0'){
                count[j]++;
                strcpy(dic[j],split[i]);
                break;
            }else if (strcmp(dic[j],split[i]) == 0){
                count[j]++;
                break;
            }
        }
    }
    int dicLength;
    for(int i = 0 ; i < 100 ;i++){
        if(count[i] !=0)
            dicLength = i+1;
    }
    char temp[100];
    for(int i = 0 ; i < dicLength;i++){
        for(int j = i+1;j<dicLength;j++){
            if(count[i] < count[j]){
            //if(strcmp(dic[i],dic[j]) > 0){
                strcpy(temp,dic[i]);
                strcpy(dic[i],dic[j]);
                strcpy(dic[j],temp);

                count[i] ^= count[j];
                count[j] ^= count[i];
                count[i] ^= count[j];
            }
            if(count[i] ==count[j] && strcmp(dic[i],dic[j]) > 0){
                strcpy(temp,dic[i]);
                strcpy(dic[i],dic[j]);
                strcpy(dic[j],temp);

                count[i] ^= count[j];
                count[j] ^= count[i];
                count[i] ^= count[j];
            }           
        }
    }
    for(int i = 0 ; i<dicLength;i++){
        printf("%s : %d",dic[i],count[i]);
        if(i!=dicLength-1){
            printf("\n");
        }
    }

    return 0;
}
/*
輸入一篇英文文章 A，文章中英文字以一個空白間隔。另外輸入 2 個英文字(word) P、Q。
(1) 將文章 A 中 P 字串以 Q 字串取代，並輸出。
(2) 在文章 A 中 P 字串前插入 Q 字串，並輸出。
(3) 將文章 A 中 P 字串刪除，並輸出。
(4) 分析文章 A 所有英文字 (word) 的頻率，依頻率由大自小排序， 頻率相同則以 word由小自大排序(That > This....)輸出。

----------------
輸入說明 :
第一行，文章 A
第二行，英文字 P
第三行，英文字 Q
----------------
輸出說明 :
第一行，將文章 A 中的 P 字串以 Q 字串取代之結果
第二行，在文章 A 中的 P 字串前插入 Q 字串之結果
第三行，將文章 A 中的 P 字串刪除之結果
第四~n行，將文章 A 中所有的英文字出現的頻率統計出來，由頻率高到低排列，若頻率一樣則由字母小到大排列(大寫在小寫之前)，請用 : 隔開單字與頻率(冒號前後皆有空白)，一個單字與頻率一行

-------------
Sample Input:
Can you can a can as a canner can can a can
can
ban
-------------
Sample Output:
Can you ban a ban as a canner ban ban a ban
Can you ban can a ban can as a canner ban can ban can a ban can
Can you a as a canner a
can : 5
a : 3
Can : 1
as : 1
canner : 1
you : 1

-------------
Sample Input:
Whether the weather be cold or whether the weather be hot
the
a
-------------
Sample Output:
Whether a weather be cold or whether a weather be hot
Whether a the weather be cold or whether a the weather be hot
Whether weather be cold or whether weather be hot
be : 2
the : 2
weather : 2
Whether : 1
cold : 1
hot : 1
or : 1
whether : 1



*/