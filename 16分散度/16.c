#include <string.h>
#include<stdio.h>

int isSet(int*arr,int m){
    for (int i = 0; i < m; i++)
    {
        for (int j=i+1; j<m; j++) {
            if (*(arr+i)==*(arr+j)) 
                return 0;
        }     
    }
    return 1;
}


int myFunc(int*arr,int size,int m){
    int counter=0;
    for(int i=0;i<size-m+1;i++){
        if(isSet(arr+i,m)==1)
            counter++;
    }
    return counter;
}
int main(){
   char input[100];
    int m;
    scanf("%s", input);
    scanf("%d", &m);
    int size = strlen(input);
    int arr[size];
    for (int i=0; i<size; i++) {
        arr[i] = input[i] - '0';
    }
    printf("%d\n",myFunc(arr, size, m));
}


// 016 分散度 

// 輸入一串整數序列和m分散度，輸出m分散度數量。 
// m分散度定義為，序列中擁有長度為m 且有m 種不同數字的連續子序列之數量。 

// 例如，m = 3，序列{1 2 3 5 4 5 4}，3 分散度數量{1 2 3}, {2 3 5}, {3 5 4}，總共三個。 




// sample input: 
// 1235454 
// 3 


// sample output: 
// 3 

// ---------------- 

// sample input: 
// 1866454122 
// 5 

// sample output: 
// 0