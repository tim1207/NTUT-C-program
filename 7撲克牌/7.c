#include <stdio.h>
#include <ctype.h>

double point(){
    char input;
    scanf(" %c", &input);
    fflush(stdin);
    if(isdigit(input)){
        if(input == '1'){
            scanf("%*d");
            return 10;
        }
        else
        return input - '0';
    } else if (input == 'A'){
        return 1;
    } else {
        return 0.5;
    }
}

int main(){
    double A = point() + point() + point();
    double B = point() + point() + point();
    
    if(A>10.5)
        A = 0;
    if(B>10.5)
        B=0;
    
    printf("%.1lf\n%.1lf\n",A ,B);
    
    if(A>B){
        printf("A wins.\n");
    } else if(B>A){
        printf("B wins.\n");
    } else {
        printf("It's a tie.\n");
    }
    return 0;
}


// 007 
// 撲克牌 
// A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K 
// A~10 點數為 1~10，J, K, Q 為 0.5。 
// A, B 兩個人各發三張撲克牌，加總點數越接近 10.5 的贏；超過 10.5 ，爆掉且分數為 0。 
// 程式： 
// 輸入：A, B 兩個人的三張撲克牌。 
// 輸出：兩個人的點數，以及A wins.或B wins.或It's a tie.。 

// Sample Input： 
// A 
// 2 
// 3 
// 2 
// 3 
// 4 
// Sample Output： 
// 6.0 
// 9.0 
// B wins. 

// Sample Input： 
// A 
// 2 
// 3 
// A 
// 2 
// 3 
// Sample Output： 
// 6.0 
// 6.0 
// It's a tie.