#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
int cmp(char first[],char second[]){

    for(int i = MAX-1; i >= 0; i--){
        if(first[i] > second[i]) return 1;
        else if(first[i] < second[i]) return -1;
    }
    return 0;

}
void input(char n[],char *sign)
{
    char s[MAX];
    scanf("%s",s);
    for(int i = 0 ; i < MAX ;i++)
        n[i] =0;
    int l = strlen(s);
    for(int i = 0 ; i < l ; i++)
    {
        n[i]= s[l-i-1]-'0';
        if(s[l-i-1] == '-'){
            *sign = '-';
            n[i]=0;
        }
    }

}
void add(char first[],char second[],char result[])
{
    for(int i = 0 ; i < MAX ;i++)
        result[i] = first[i]+second[i];
    for(int i = 0 ; i < MAX ;i++)
    {
        if(result[i] >= 10)
        {
            result[i+1] += result[i] /10;
            result[i] = result[i] % 10;
        }
    }

}
void Mul(char first[] ,char second[],char result[]){
    for(int i = 0;i<MAX*2;i++)
        result[i]=0;
    for(int i = 0 ; i <MAX;i++){
        for(int j = 0 ;j<MAX ;j++){
            result[i+j] += first[j]*second[i];
            if(result[i+j]>=10)
            {
                result[i+j+1]+= result[i+j]/10;
                result[i+j] = result[i+j]%10;
            }

        }
    }
}
void _Sub(char first[],char second[],char result[]){
    for(int i =0;i<MAX;i++)
        result[i]=0;
    for(int i = 0 ; i < MAX;i++){
        result[i] += first[i]-second[i];
        if(result[i] < 0 )
        {
            result[i] +=10;
            result[i+1]--;
        }
    }
}
void Sub(char first[],char second[],char rst[]){
    int compare = cmp(first,second);
    if(compare == -1){
        _Sub(second,first,rst);
        printf("-");

    }else if(compare == 1){
        _Sub(first,second,rst);

    }else{
        printf("0");
    }
}
void Print(char n[],int nLen)
{
    int i ;

    for( i = nLen-1 ;i>=0;i--)
        if(n[i]!=0)break;
    for(; i>=0 ;i--)
        printf("%d",n[i]);


}
int main()
{
   int totalLen;
    char a[MAX],b[MAX];
    char aSign='+',bSign='+';
    char rst[MAX+1]={0},rst_mul[MAX*2]={0};
 
    int choose;
    scanf("%d",&choose);
    totalLen = strlen(a) > strlen(b) ? strlen(a):strlen(b);
    input(a,&aSign);
    input(b,&bSign);
    switch (choose)
    {
    case 1:
        if(aSign == '+' && bSign=='+'  )
            add(a,b,rst);
        else if(aSign == '-' && bSign=='-')
        {
            add(a,b,rst);
            printf("-");
        }
        else if (aSign =='+' && bSign=='-')
            Sub(a,b,rst);
        
        else if (aSign =='-' && bSign=='+')
            Sub(b,a,rst);
        Print(rst,MAX);
        break;
    case 2:
        if(aSign == '+' && bSign=='+'  )
            Sub(a,b,rst);
        else if(aSign == '-' && bSign=='-')
            Sub(b,a,rst);
        else if (aSign =='+' && bSign=='-')
            add(a,b,rst);
        else if (aSign =='-' && bSign=='+'){
            add(a,b,rst);
            printf("-");
        }
        Print(rst,MAX);
        break;
    case 3:
        if(aSign == '+' && bSign=='+'  )
            Mul(a,b,rst_mul);
        else if(aSign == '-' && bSign=='-')
            Mul(a,b,rst_mul);
        else if (aSign =='+' && bSign=='-'){
            Mul(a,b,rst_mul);
            printf("-");
        }
        else if (aSign =='-' && bSign=='+'){
            Mul(a,b,rst_mul);
            printf("-");
        }
        Print(rst_mul,MAX*2);
        break;
    
    default:
        break;

    }
    return 0;
}

/*
015 大數相加

輸入大數運算的模式，
以1代表大數相加；2代表大數相減；3代表大數相乘。
再輸入兩個20位數以上的整數做運算，
並輸出計算過後的結果。

sample input:
1
10000000000000000001
99999999999999999999

sample output:
110000000000000000000

--------------------------------

sample input:
2
10000100001000010000
100001000010000100001

sample output:
-90000900009000090001

--------------------------------

sample input:
3
10000100000000000001
12121212121212121212

sample output:
121213333333333333344242412121212121212

*/