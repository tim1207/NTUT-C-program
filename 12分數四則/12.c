#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int gcd(int n1, int n2) {
    if (n2)
        return abs(gcd(n2, n1 % n2));
    else
        return abs(n1);
}
//約分
int* parseFraction(char* num){
    int *result = calloc(2,sizeof(int));
    *(result) = atoi(num); 
    while (*num != '/') {
        num = num + 1;
    }
    num = num + 1; 
    *(result+1) = atoi(num); 
    int gc_d = gcd(*result, *(result+1));
    *result /= gc_d; 
    *(result+1) /= gc_d; 
    return result; 
}

int* addition(int* num1, int* num2){
    int *result = calloc(2,sizeof(int));
    int gc_d = gcd(*(num1+1), *(num2+1)); 
    //通分 
    *num1 *= abs((*(num2+1)/gc_d)); 
    *num2 *= abs((*(num1+1)/gc_d)); 
    //分母通分
    *(num1+1) = *(num2+1) = *(num1+1) * *(num2+1) / gc_d;

    *result = *num1 + *num2;//分子放入
    *(result+1) = *(num1+1);//分母放入
    //化到最簡
    gc_d = gcd(*result, *(result+1));
    *result /= gc_d;
    *(result+1) /= gc_d;
    return result;
}

int* multiply(int* num1, int* num2){
    int *result = calloc(2,sizeof(int));
    *result = *num1 * *num2;
    *(result+1) = *(num1+1) * *(num2+1);
    int gc_d = gcd(*result, *(result+1));
    
    *result /= gc_d;
    *(result+1) /= gc_d;
    return result;
}

void printResult(int* result){
    if(*(result+1) == 0)//分母為零
        printf("ERROR\n");
    else if(*result == 0)
        printf("0\n");//分子為零

    else if(abs(*result) < abs(*(result+1)))//真分數
        printf("%d/%d\n", *result, *(result+1));
    else{//假分數
        int num = *result / *(result+1);
        *result %= *(result+1);
        *result = abs(*result);
        if(*result == 0)
            printf("%d\n", num);
        else
            printf("%d(%d/%d)\n", num, *result, *(result+1));
    }
}


int main() {
    int continueFlag = 1;
    while (continueFlag) {
        char s1[10], s2[10];
        scanf("%s", s1);
        scanf("%s", s2);
        int* num1 = parseFraction(s1);
        int* num2 = parseFraction(s2);
        int* result = calloc(2,sizeof(int));;
        char op;
        scanf(" %c", &op);
        switch (op) {
            case '+':{
                result = addition(num1, num2);
                break;
            }
            case '-':{
                *(num2) *= -1;
                result = addition(num1, num2);
                *(num2) *= -1;
                break;
            }
            case '*':{
                result = multiply(num1, num2);
                break;
            }
            case '/':{
                int temp = *num2;
                *num2 = *(num2+1);
                *(num2+1) = temp;
                if (*(num2+1) < 0){
                    *num2 *= -1;
                    *(num2+1) *= -1;
                }
                result = multiply(num1, num2);
                break;
            }
            default:
                break;
        }
        printResult(result);
        char flag;
        scanf(" %c", &flag);
        if (flag != 'y')
            continueFlag = 0;
    }
    return 0;
}



// 012 
// 分數四則運算 

// 計算兩個分數四則運算 。 

// 輸入說明: 
// ---------------------------- 
// 輸入四行，第一、二行各代表一個分數，第三行代表數學運算符號(+-*/)，第四行代表是否繼續運算(y表示繼續運算、n表示不繼續運算) 

// -------------------- 
// 輸出說明: 
// ---------------------------- 
// 輸出分數結果 

// **輸入分子可能大於分母** 
// 若有輸入分數的分母為0，則輸出ERROR。 
// 若分數大於1，則分數部分要加括號，如一又六分之一輸出為1(1/6) 
// 若為負數，負號在最前面。 
// 若輸出為0，則顯示0 
// 輸出的結果必須化簡為最簡分數 
// ---------------- 
// Sample input: 
// ---------------- 
// 1/2 
// 2/3 
// + 
// y 
// -1/4 
// 1/5 
// * 
// n 


// ---------------- 
// Sample output: 
// ---------------- 
// 1(1/6) 
// -1/20 



// ---------------- 
// Sample input: 
// ---------------- 
// 2/0 
// 2/3 
// - 
// n 


// ---------------- 
// Sample output: 
// ---------------- 
// ERROR

