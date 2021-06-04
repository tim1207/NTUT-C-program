#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define length 100
void input(char *s){

    fgets(s,length,stdin);
    if( s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }

}
int main()
{
    char S[length][length];
    memset(S,'\0',sizeof(S));
    char temp[length];
    input(temp);
    char *token = strtok(temp," ");
    int splitLen = 0 ;
    for(splitLen = 0 ;token!=NULL;splitLen++){
        strcpy(S[splitLen],token);
        token = strtok(NULL," ");
    }


    char set[length][length];
    memset(set,'\0',sizeof(set));
    int n;
    scanf("%d\n",&n);
    for(int i = 0 ; i< n ;i++){
        input(set[i]);
    }
    int cp = 0;
    for(int i = 0 ; i < n ;i++){

        for(int j = i+1 ; j < n;j++){
            
           int book[splitLen],book2[splitLen];
            for(int m = 0 ;m<splitLen;m++){book[m]=0;book2[m]=0;}
            char temp[length],temp2[length];
            strcpy(temp,set[i]);
            strcpy(temp2,set[j]);
            char *token = strtok(temp," ");
            while (token != NULL)
            {
                for(int m = 0 ; m < splitLen ;m++){
                    if(strcmp(token,S[m]) == 0)
                    {
                        book[m] = 1;
                        break;
                    }
                }
                token = strtok(NULL," ");
            }
            token = strtok(temp2," ");
            while (token != NULL )
            {
                for(int m = 0 ; m < splitLen ;m++){
                    if(strcmp(token,S[m]) == 0)
                    {
                        book2[m] = 1;
                        break;
                    }
                }
                token = strtok(NULL," ");
            }
            int isCP = 1;
            for(int m = 0 ;m<splitLen;m++){
                if(book[m]^book2[m] == 0 )
                {
                    isCP=0;
                    break;
                }
            }
            if(isCP)
                cp++;
        }
    }
    printf("%d",cp);

    return 0;
}
/*
互補字S1, S2的定義是字串S1, S2沒有重複出現的字，且字串S1, S2內的字需包含在字串S內的字。
此處，字串是英文字的一個集合，亦即，元素有重複只算一個，也不管排列情況。
例如"Happy Happy Day"與"Day Happy Day"是相同的字串。輸入n個字串，輸出這n個字串互補的個數。
----------------
輸入說明 :
第一行，字串S
第二行，輸入字串個數n
第三行，第一個字串
第四行，第二個字串
........
----------------
輸出說明 :
第一行，n個字串互補的個數


-------------
Sample Input:
happy birthday to you
4
happy to you
birthday birthday
to you
happy birthday
-------------
Sample Output:
2

-------------
Sample Input:
what are you doing
3
what what are
doing doing
what are are you you
-------------
Sample Output:
1



*/
