#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

double f1(double x, double a){
    return sqrt(a - pow(x, 2));
}
double f2(double x, double a){
    return (a * pow(x, 3) + 7 * x) / sqrt(a+x);
}

double myFunc(double (*function)(double x, double a), double a, double p, double q, unsigned long long n){
    double h = (q-p)/n;
    double result = 0;
    double x = p+h;
    result = fabs(function(p, a)) + fabs(function(q, a));
    for(int i=1; i<n; i++){
        result += 2 * fabs(function(x, a));
        x += h;
    }
    result *= fabs(h) / 2;
    return result;
}

int main(){
    int continueFlag = 1;
    while (continueFlag) {
        double a, p ,q, prev, cur, err;
        cur = INT_MAX;
        int mode;
        unsigned long long n = 1;
        double (*function)(double, double);
        scanf("%d", &mode);
        
        
        switch (mode) {
            case 0:
                function = NULL;
                continueFlag = 0;
                break;
            case 1:
                function = f1;
                break;
            case 2:
                function = f2;
                break;
            default:
                function = NULL;
                break;
        }
        if (!continueFlag)
            break;
        
        scanf("%lf%lf%lf%lf", &a, &p, &q, &err);
        err = pow(10, err * (-1));
        //err=0.000001;
        
        do {
            prev = cur;
            cur = myFunc(function, a, p, q, n);
            n *= 2;
        } while (fabs(cur - prev) > err);
        
        printf("%.12lf\n", cur);
    }
    return 0;
}



// 使用切割面積加總法公式(將函式切成N個梯形)， 

// 計算函式f(x)從f(p)到f(q)之間的面積 

// T = (h/2)(f(p) + f(q) + 2 f(xi)) , 

// h = (q-p)/n，h 是 double。 

// x 值從區間起始 p 到區間終點 q 的面積， 

// n 為 切割數，初始設定 n=1，每次不符合所期待的精確度err時*2( n=n*2 )。 

// err為精確小數位數，例如 err=6，即 "目前"與"上一次"兩次切割， 

// 計算出的面積值的差小於 10 的負6次方，亦即小於 0.000001。 

// f1(x) =((a-x^2))^(1/2), a 為常數。 f2(x) = (ax^3 + 7x)/(a+x)^(1/2), a 為常數。 

// 輸入說明： 
// 輸入 1 代表計算 f1(x) 面積，輸入 2 代表計算 f2(x)面積， 
// 接著依序，輸入 a, p, q, err，輸入0為停止輸入。 

// 此題測試資料為連續輸入一至多筆資料(有可能一次輸入包含多組測資)。 

// 答案需輸出到小數點第12位 

// 範例一. 
// Input: 
// 1 
// 4 
// -2 
// 1 
// 9 
// 0 
// Output: 
// 5.054815608319 

// 範例二. 
// Input: 
// 2 
// 1 
// 0 
// 3 
// 9 
// 0 
// Output: 
// 29.752380952687

