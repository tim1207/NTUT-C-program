#include <stdio.h>

int main(){
    int cources[3][4] = {{0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    
    for(int i=0; i<3; i++){
        int hours;
        scanf("%d%d", &cources[i][0], &hours);
        for(int j=1; j<=hours; j++){
            scanf("%d",&cources[i][j]);
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(cources[0][i] == cources[1][j] && cources[0][i]){
                printf("%d and %d conflict on %d\n", cources[0][0], cources[1][0], cources[0][i]);
            }
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(cources[0][i] == cources[2][j] && cources[0][i]){
                printf("%d and %d conflict on %d\n", cources[0][0], cources[2][0], cources[0][i]);
            }
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(cources[1][i] == cources[2][j] && cources[1][i]){
                printf("%d and %d conflict on %d\n", cources[1][0], cources[2][0], cources[1][i]);
            }
        }
    }
}

// 005 
// 檢查三門課程是否衝堂， 
// 依序輸入課程編號(數字)、 
// 上課小時數(1-3小時)、 
// 上課時間(星期1-5, 第1-9節) 

// 輸入說明 
// 1001 (第一門課課程編號) 
// 3 (3小時) 
// 11 (星期1 第1節課) 
// 59 (星期5 第9節課) 
// 25 (星期2 第5節課) 
// 2020 (第二門課課程編號) 
// 2 
// 25 
// 16 
// 2030 (第三門課課程編號) 
// … 

// 輸出說明 (兩課程編號衝突在哪幾節) 
// 1001 and 2020 conflict on 25 

// Sample Input： 
// 1001 
// 3 
// 11 
// 12 
// 13 
// 1002 
// 3 
// 21 
// 22 
// 23 
// 1003 
// 3 
// 31 
// 32 
// 13 
// Sample Output： 
// 1001 and 1003 conflict on 13 

// Sample Input： 
// 1001 
// 1 
// 11 
// 1002 
// 3 
// 21 
// 22 
// 11 
// 1003 
// 3 
// 31 
// 32 
// 33 
// Sample Output： 
// 1001 and 1002 conflict on 11 