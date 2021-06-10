#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    memset (array,0,sizeof(array));
    for(int i = 0 ;i < n ;i++){
        scanf(" %d",&array[i]);
    }
    int len = 0;
    for(int i =0;i<n;i++)
    {
        int left=1,right=1;
        for(int m = i-1 ,l=1 ; m >= 0 ;m--,l++){
            if(array[i] > array[m])
            {
                left = l;
                break;
            }
            if(m==0)
                left = l+1;
        }
        for(int m = i+1 , l=1 ;m<n;m++,l++){
            if(array[i] > array[m]){
                right = l;
                break;
            }
            if(m == n-1)
                right = l+1;
        }
        //printf("%d:%d,%d\n",i,left,right);
        if(left>=right){
            len+=right;
        }
        else{
            len+=left;
        }
    }
    printf("%d",len);
}

/*
[本題為BFS練習題] 
老師給小明 n 個不重複的數字, 詢問這串數字的"半徑和"是多少 
半徑的定義: 「比我小的數字中離我最近的數字有多近(取最近的)，或是已經到邊際找不到」 

例如一個序列: 
5 7 1 4 3 6 2 

從左到右的半徑分別是 1 + 1 + 3 + 1 + 2 + 1 + 1 = 10 
1.其中數字 5 的左邊是邊際了, 所以是 1 
2.比數字7小的數字為1, 7到1的距離為1, 所以是 1 
3.而要找到比1小的數字要到邊際(5的左邊)才行, 所以距離是3 
4.比數字4小的數字為3, 4到3的距離為1, 所以是 1 
5.比數字3小的數字為1或2, 3到1或2的距離都為2, 所以是 2 
6.比數字6小的數字為2, 6到2的距離為1, 所以是 1 
7.最後是2, 2 的右邊是邊際了, 所以是 1 

輸入說明: 
輸入有兩行 
第一行給定一個數字 n 
第二行有 n 個不重複的數字 

輸出說明: 
輸出一個數字(半徑和) 


input1: 
7 
5 7 1 4 3 6 2 

output1: 
10 
================ 

input2: 
5 
1 2 3 4 5 

output2: 
5
*/

