#include <stdio.h>
#include <math.h>
int main()
{   
    //printf("Input\n");
    int a,b,c;
    //printf("第一個數(int)"); 
    scanf("%d",&a);
    //printf("第二個數(int)");
    scanf("%d",&b);
    //printf("第三個數(int)"); 
    scanf("%d",&c);

    double x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);
    double x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);
    //printf("\nOutput\n");
    printf("%.1f\n" ,x1); 
    printf("%.1f\n" ,x2); 
    return 0;
}


// 001. 一元二次方程式 

// 一元二次方程式，aX^2 + bx + c = 0，輸入a, b, c, 求 方程式的兩個實根。 

// --------------- 
// 輸入說明 

// 第一個數(int) a 
// 第二個數(int) b 
// 第三個數(int) c 

// --------------- 
// 輸出說明 

// 第一個實根 x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a) 
// 第二個實根 x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a) 

// x1, x2 輸出到小數點第一位 
// print("%.1f" %x1); 

// --------------- 
// Input 
// 1 
// -2 
// 1 

// Output 
// 1.0 
// 1.0 

// --------------- 
// Input 
// 1 
// -4 
// 4 

// Output 
// 2.0 
// 2.0


