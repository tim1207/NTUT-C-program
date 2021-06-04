#include <stdio.h>
#include <string.h>
#define STR_N 300
int main(){
    char s1[STR_N];
    fgets(s1, STR_N, stdin);
    if (strlen(s1) > 0 && s1[strlen(s1)-1] == '\n' ) {
        s1[strlen(s1)-1] = '\0';
    }
    if (strlen(s1) > 0 && s1[strlen(s1)-1] == ' ' ) {
        s1[strlen(s1)-1] = '\0';
    }
    int n;
    scanf("%d ", &n);
    //getchar();
    char words[n][STR_N];
    for(int i=0; i<n; i++){
        fgets(words[i], STR_N, stdin);
        if (strlen(words[i]) > 0 && words[i][strlen(words[i])-1] == '\n' ) {
            words[i][strlen(words[i])-1] = '\0';
        }
        if (strlen(words[i]) > 0 && words[i][strlen(words[i])-1] == ' ' ) {
            words[i][strlen(words[i])-1] = '\0';
        }
    }
    
    int wordCount = 1;
    for(int i=0; i<strlen(s1); i++){
            if(s1[i] == ' ')
                wordCount++;
    }
    char wordList[wordCount][STR_N];
    
    strcpy(wordList[0], strtok(s1, " "));
    for (int i=1; i<wordCount; i++) {
       strcpy(wordList[i], strtok(NULL, " "));
    }


    // for(int i=0;i<n;i++)
    //     printf("%s\n",words[i]);
    int A[n][wordCount];
    memset(A,0,sizeof(A));
    for(int i=0;i<n;i++){
        int wordCountList = 1;
        for(int j=0; j<strlen(words[i]); j++){
                if(words[i][j] == ' ')
                    wordCountList++;
        }
        //printf("%s\n",words[i]);
        //printf("%d\n",wordCountList);


        char List[wordCountList][STR_N];
        memset(List,'\0',sizeof(List));
        strcpy(List[0], strtok(words[i], " "));
        for (int j=1; j<wordCountList; j++) {
            strcpy(List[j], strtok(NULL, " "));
        }

        // for (int j=0; j<wordCountList; j++) {
        //     printf("%d %s\n",i,List[j]);
        // }

        for (int j=0; j<wordCountList; j++) {
            for(int k=j+1;k<wordCountList;k++){
                if(strcmp(List[k],List[j])==0)
                    strcpy(List[j],"");
            }
        }
        
        // for (int j=0; j<wordCountList; j++) {
        //     printf("%d %s\n",i,List[j]);
        // }

		for(int k=0;k<wordCountList;k++){
        	for(int j=0;j<wordCount;j++){
                if(strcmp(List[k],wordList[j])==0 && strcmp(List[k],"")!=0)
                    A[i][j]=1;
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<wordCount;j++){
    //         printf("%d ",A[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    int ans=0;
    for(int i=0;i<n;i++){

        for(int k=i+1;k<n;k++){
            int array[wordCount];
            memset(array,0,sizeof(array));
            for(int j=0;j<wordCount;j++){
            		if(A[i][j]==1 && A[k][j]==1)
            			array[j]=0;
            		else
                    	array[j]=A[i][j]|A[k][j];
            }
            int num=0;
            // for(int j=0;j<wordCount;j++){
            //         printf("%d ",array[j]);
            // }
            for(int j=0;j<wordCount;j++){
                    num+=array[j];
            }
            if(num==wordCount)
                ans++;
        }
    }
    printf("%d",ans);

    
}











// 互補字S1, S2的定義是字串S1, S2沒有重複出現的字，且字串S1, S2內的字需包含在字串S內的字。 
// 此處，字串是英文字的一個集合，亦即，元素有重複只算一個，也不管排列情況。 
// 例如"Happy Happy Day"與"Day Happy Day"是相同的字串。輸入n個字串，輸出這n個字串互補的個數。 
// ---------------- 
// 輸入說明 : 
// 第一行，字串S 
// 第二行，輸入字串個數n 
// 第三行，第一個字串 
// 第四行，第二個字串 
// ........ 
// ---------------- 
// 輸出說明 : 
// 第一行，n個字串互補的個數 


// ------------- 
// Sample Input: 
// happy birthday to you 
// 4 
// happy to you 
// birthday birthday 
// to you 
// happy birthday 
// ------------- 
// Sample Output: 
// 2 

// ------------- 
// Sample Input: 
// what are you doing 
// 3 
// what what are 
// doing doing 
// what are are you you 
// ------------- 
// Sample Output: 
// 1

