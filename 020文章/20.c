#include <stdio.h>
#include <string.h>
#include <limits.h>
 
struct Word{
    char value[100];
    int count;
};
 
 
int check_same(struct Word *sortedWords,int wordCount,char*temp){
    int flag=0;
    for(int i=0;i<wordCount;i++){
        if(!strcmp( (sortedWords[i].value),temp) )
            flag=1;
            break;
    }
    return flag;
}
 
 
int main(){
    char A[1000], P[100], Q[100],A_copy[1000];
    fgets(A, 1000, stdin);
    if (strlen(A) > 0 && A[strlen(A) - 1] == '\n')
        A[strlen(A) - 1] = '\0';
    strcpy(A_copy,A);
    fgets(P, 100, stdin);
    fgets(Q, 100, stdin);
    if (strlen(P) > 0 && P[strlen(P) - 1] == '\n')
        P[strlen(P) - 1] = '\0';
    if (strlen(P) > 0 && P[strlen(P) - 1] == ' ')
        P[strlen(P) - 1] = '\0';
    if (strlen(Q) > 0 && Q[strlen(Q) - 1] == '\n')
        Q[strlen(Q) - 1] = '\0';
    if (strlen(Q) > 0 && Q[strlen(Q) - 1] == ' ')
        Q[strlen(Q) - 1] = '\0';
 
    int wordCount = 1;
    for (int i=0; i<strlen(A); i++)
        if(A[i] == ' ')
            wordCount++;
 
    char temp[wordCount][100];
    memset(temp,'\0',sizeof(temp));
    char *token = strtok(A, " ");
    int i = 0;
    while( token != NULL ) {
        strcpy(temp[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    //change
    for(int i=0; i<wordCount; i++){
        if (!strcmp(temp[i],P))
            printf("%s", Q);
        else
            printf("%s", temp[i]);
        if(i!=wordCount-1)
        	printf(" ");
    }
    printf("\n");
    // 1 complete
    //insert
    for(int i=0; i<wordCount; i++){
        if (!strcmp(temp[i],P))
            printf("%s %s", Q, P);
        else
            printf("%s", temp[i]);
        if(i!=wordCount-1)
        	printf(" ");
    }
    printf("\n");
    // 2 complete
    //delete
    for(int i=0; i<wordCount; i++){
        if (strcmp(temp[i],P)){
            printf("%s", temp[i]);
            if(i!=wordCount-1)
        		printf(" ");
        }
    }
    printf("\n");
    //3 complete 
 
    struct Word sortedWords[wordCount];
    for(int i=0; i<wordCount; i++){
            strcpy(sortedWords[i] .value,temp[i]);
            sortedWords[i].count=1;
    }
 
    for(int i=0;i<wordCount;i++)
    {
        for(int j=i+1;j<wordCount;j++)
        {
            //printf("%d %d =%d\n",i,j,strcmp(sortedWords[i].value,sortedWords[j].value));
            if(strcmp(sortedWords[i].value,sortedWords[j].value)==0 && sortedWords[j].count!=0)
            {
                sortedWords[i].count+=sortedWords[j].count;
                struct Word Words={.value="",.count=0};
                sortedWords[j]=Words;
            }
        }
    }
    //sort  small is first and count is first
    for(int i=0;i<wordCount;i++)
    {
        for(int j=i;j<wordCount;j++)
        {
            //printf("%d %d =%d\n",i,j,strcmp(sortedWords[i].value,sortedWords[j].value));
            if(sortedWords[i].count<sortedWords[j].count)
            {   //swap
                struct Word swap = sortedWords[i];
                sortedWords[i]=sortedWords[j];
                sortedWords[j]=swap;
            }
            if(sortedWords[i].count==sortedWords[j].count){
                if( strcmp(sortedWords[i].value,sortedWords[j].value)>0){
                    struct Word swap = sortedWords[i];
                    sortedWords[i]=sortedWords[j];
                    sortedWords[j]=swap;
                }        
            }
        }
    }
 
    for(int i=0;i<wordCount;i++){
        if(strcmp(sortedWords[i].value,"")!=0)
        printf("%s : %d\n", sortedWords[i].value, sortedWords[i].count);
    }
 
 
 
 
 
 
 
}
 
 
 
 
 
 
 
 
 
 
 
 
//024
// 輸入一篇英文文章 A，文章中英文字以一個空白間隔。另外輸入 2 個英文字(word) P、Q。 
// (1) 將文章 A 中 P 字串以 Q 字串取代，並輸出。 
// (2) 在文章 A 中 P 字串前插入 Q 字串，並輸出。 
// (3) 將文章 A 中 P 字串刪除，並輸出。 
// (4) 分析文章 A 所有英文字 (word) 的頻率，依頻率由大自小排序， 頻率相同則以 word由小自大排序(That > This....)輸出。 
 
// ---------------- 
// 輸入說明 : 
// 第一行，文章 A 
// 第二行，英文字 P 
// 第三行，英文字 Q 
// ---------------- 
// 輸出說明 : 
// 第一行，將文章 A 中的 P 字串以 Q 字串取代之結果 
// 第二行，在文章 A 中的 P 字串前插入 Q 字串之結果 
// 第三行，將文章 A 中的 P 字串刪除之結果 
// 第四~n行，將文章 A 中所有的英文字出現的頻率統計出來，由頻率高到低排列，若頻率一樣則由字母小到大排列(大寫在小寫之前)，請用 : 隔開單字與頻率(冒號前後皆有空白)，一個單字與頻率一行 
 
// ------------- 
// Sample Input: 
// Can you can a can as a canner can can a can 
// can 
// ban 
// ------------- 
// Sample Output: 
// Can you ban a ban as a canner ban ban a ban 
// Can you ban can a ban can as a canner ban can ban can a ban can 
// Can you a as a canner a 
// can : 5 
// a : 3 
// Can : 1 
// as : 1 
// canner : 1 
// you : 1 
 
// ------------- 
// Sample Input: 
// Whether the weather be cold or whether the weather be hot 
// the 
// a 
// ------------- 
// Sample Output: 
// Whether a weather be cold or whether a weather be hot 
// Whether a the weather be cold or whether a the weather be hot 
// Whether weather be cold or whether weather be hot 
// be : 2 
// the : 2 
// weather : 2 
// Whether : 1 
// cold : 1 
// hot : 1 
// or : 1 
// whether : 1
 
 
 
 
 
 
 
 
//024
// 輸入一篇英文文章 A，文章中英文字以一個空白間隔。另外輸入 2 個英文字(word) P、Q。 
// (1) 將文章 A 中 P 字串以 Q 字串取代，並輸出。 
// (2) 在文章 A 中 P 字串前插入 Q 字串，並輸出。 
// (3) 將文章 A 中 P 字串刪除，並輸出。 
// (4) 分析文章 A 所有英文字 (word) 的頻率，依頻率由大自小排序， 頻率相同則以 word由小自大排序(That > This....)輸出。 
 
// ---------------- 
// 輸入說明 : 
// 第一行，文章 A 
// 第二行，英文字 P 
// 第三行，英文字 Q 
// ---------------- 
// 輸出說明 : 
// 第一行，將文章 A 中的 P 字串以 Q 字串取代之結果 
// 第二行，在文章 A 中的 P 字串前插入 Q 字串之結果 
// 第三行，將文章 A 中的 P 字串刪除之結果 
// 第四~n行，將文章 A 中所有的英文字出現的頻率統計出來，由頻率高到低排列，若頻率一樣則由字母小到大排列(大寫在小寫之前)，請用 : 隔開單字與頻率(冒號前後皆有空白)，一個單字與頻率一行 
 
// ------------- 
// Sample Input: 
// Can you can a can as a canner can can a can 
// can 
// ban 
// ------------- 
// Sample Output: 
// Can you ban a ban as a canner ban ban a ban 
// Can you ban can a ban can as a canner ban can ban can a ban can 
// Can you a as a canner a 
// can : 5 
// a : 3 
// Can : 1 
// as : 1 
// canner : 1 
// you : 1 
 
// ------------- 
// Sample Input: 
// Whether the weather be cold or whether the weather be hot 
// the 
// a 
// ------------- 
// Sample Output: 
// Whether a weather be cold or whether a weather be hot 
// Whether a the weather be cold or whether a the weather be hot 
// Whether weather be cold or whether weather be hot 
// be : 2 
// the : 2 
// weather : 2 
// Whether : 1 
// cold : 1 
// hot : 1 
// or : 1 
// whether : 1
 
 