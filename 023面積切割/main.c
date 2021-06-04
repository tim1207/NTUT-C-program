#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

double f1(double a, double x) {
    return fabs(sqrt(a - x * x));
}
double f2(double a, double x) {
    return fabs((a * pow(x, 3) + 7 * x) / sqrt(a + x));
}
double A(double (*f)(double a ,double x) , double n, double a, double p, double q) {
    double h = (q - p) / n;
    double x = p + h;
    double area = 0;

   
    area = f(a, p) + f(a, q);
    for (int i = 1; i < n; i++) {
        area += 2 * f(a, x);
        x += h;
    }
 

  
    return area * fabs(h) / 2.0;


}
int main()
{

     //int f=1,n=1,err=9;
    
     //double a=4,p=-2,q=1;
    while (1)
    {
        unsigned long long n = 1;
        double f=0, a=0, p=0, q=0, err=0;
        //double a = 1, p = 0, q = 3, f = 2, err = 9;
        scanf("%lf", &f);
        if (f == 0)
            break;
        scanf("%lf%lf%lf%lf", & a, & p, & q, & err);
        
        double (*func)(double, double) = f == 1 ? f1 : f2;
        err = pow(10, err * -1);
        double lastCalc = INT_MAX ,currentCalc =INT_MAX;
        do {
            lastCalc = currentCalc;
            currentCalc = A(func, n, a, p, q);
            n *= 2;
        } while (fabs(currentCalc - lastCalc) > err);
        printf("%.12lf\n", currentCalc);
      
    }
   


    return 0;
}
/*
023
使用切割面積加總法公式(將函式切成N個梯形)，

計算函式f(x)從f(p)到f(q)之間的面積， x 值從區間起始 p 到區間終點 q

f1(x) =((a-x^2))^(1/2) ; f2(x) = (ax^3 + 7x)/(a+x)^(1/2), a 為常數(可能有小數)。

選定這兩個函數之一，使用梯形法來估計從x=p到x=q的面積

梯形面積公式如下，若一個函數圖形切成n塊，則梯形法的估計為:

A(n) = ((q-p)/2n)[f(p)+2f(p+x)+2f(p+2x)+...+2f(q-x)+f(q)]，其中x = (q-p) / n

初始設定 n=1，每次不符合所期待的精確度err時*2( n=n*2 )。

err為精確小數位數，例如 err=6，即 "目前"與"上一次"兩次切割，

計算出的面積值的差小於 10 的負6次方，亦即小於 0.000001。


輸入說明：
輸入 1 代表計算 f1(x) 面積，輸入 2 代表計算 f2(x)面積，
接著依序，輸入 a, p, q, err，輸入0為停止輸入。

此題測試資料為連續輸入一至多筆資料(有可能一次輸入包含多組測資)。

答案需輸出到小數點第12位

範例一.
Input:
1
4
-2
1
9
0
Output:
5.054815608319

範例二.
Input:
2
1
0
3
9
0
Output:
29.752380952687

範例三.
Input:
1
100
-10
10
6
1
100
-1
8
8
0
Output:
157.079632241407
80.348069141438
*/