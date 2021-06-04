#include <stdio.h>
#include <string.h>
#define CHANGE(x, y) { int temp = x; x = y; y = 7-temp; } 
void rotate(int data[3][3][3]){
    int right[3],mid[3],left[3];
    // save value 
    for(int i=0;i<3;i++)
        right[i] = data[i][0][1];// 上1
    for(int i=0;i<3;i++)
        mid[i]=data[i][1][1];// 上2
    for(int i=0;i<3;i++)
        left[i]=data[i][2][1];// 上2
    // give value
    for(int i=0;i<3;i++)
        data[2][i][1]=right[i];  // 上 right
    for(int i=0;i<3;i++)
        data[1][i][1]=mid[i];// 上 mid
    for(int i=0;i<3;i++)
        data[0][i][1]=left[i];// 上 left
    
}
void roll(int data[3][3][3],int opcode){
    switch (opcode)
    {
    case 10:
        for(int i=0;i<3;i++)
            CHANGE(data[0][i][1],data[0][i][0]);
        break;
    case 11:
    for(int i=0;i<3;i++)
            CHANGE(data[1][i][1],data[1][i][0]);
        break;
    case 12:
    for(int i=0;i<3;i++)
            CHANGE(data[2][i][1],data[2][i][0]);
        break;
    //wrong
    case 20:
        rotate(data);
    for(int i=0;i<3;i++)
            CHANGE(data[i][0][0],data[i][0][2]);
        break;
    
    case 21:
    for(int i=0;i<3;i++)
            CHANGE(data[i][1][0],data[i][1][2]);
        break;
    case 22:
    for(int i=0;i<3;i++)
            CHANGE(data[i][2][0],data[i][2][2]);  
        break;
     
    default:
        break;
    }   
}
// 1
// 001 101 201
// 011 111 211
// 021 121 221
// 4           |2
// 000 100 200 |002 102 202
// 010 110 210 |012 112 212 
// 020 120 220 |022 122 222
int main(){
    int m=0;
    int a[4];
    int data[3][3][3];
    for (int i=0; i<3; i++) {//初始化
        for(int j=0;j<3;j++){
            data[i][j][0]=4; data[i][j][1]=1; data[i][j][2]=2;
        }       
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int opcode;
        scanf("%d", &opcode);
            roll(data, opcode);
        // printf("上\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][0][1]);// 上1
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][1][1]);// 上2
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][2][1]);// 上2
        // printf("\n");

        // printf("前\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][0][0]);// 正1
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][1][0]);// 正2
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][2][0]);// 正2
        // printf("\n");

        // printf("右\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][0][2]);// 右1
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][1][2]);// 右2
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][2][2]);// 右2
        // printf("\n");
    }

        //printf("上\n");
        for(int i=0;i<3;i++)
            printf("%d ", data[i][0][1]);// 上1
        printf("\n");
        for(int i=0;i<3;i++)
            printf("%d ", data[i][1][1]);// 上2
        printf("\n");
        for(int i=0;i<3;i++)
            printf("%d ", data[i][2][1]);// 上2
        printf("\n");

        // printf("前\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][0][0]);// 正1
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][1][0]);// 正2
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][2][0]);// 正2
        // printf("\n");

        // printf("右\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][0][2]);// 右1
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][1][2]);// 右2
        // printf("\n");
        // for(int i=0;i<3;i++)
        //     printf("%d ", data[i][2][2]);// 右2
        // printf("\n");
}
// 魔術方塊有六面，一開始白色朝前，藍色朝上，紅色2 朝右 如連結所示(https://imgur.com/kzYkXZ8)，展開如連結所示(https://imgur.com/7JnAXUZ)。 

// 顏色編號，1: 藍色，2: 紅色，3: 黃色，4: 白色，5: 橘色，6:綠色。 
// 接下來 M 次修改操作，每次操作包含一個整數 a，意義為： 
// 1. 10 表示直欄(column)最左邊向前轉一次。 
// 2. 11 表示直欄(column)中間向前轉一次。 
// 3. 12 表示直欄(column)最右邊向前轉一次。 
// 4. 20 表示橫列(row)最上面向左轉一次。 
// 5. 21 表示橫列(row)中間向左轉一次。。 
// 6. 22 表示橫列(row)最下面向左轉一次。。 

// 操作修正完成，請輸出朝上9格的顏色編號。 

// Sample Input 
// 1 
// 10 
// Sample Output 
// 4 1 1 
// 4 1 1 
// 4 1 1 

// Sample Input 
// 3 
// 10 
// 20 
// 10 
// Sample Output 
// 2 4 4 
// 6 1 1 
// 6 1 1 

// Sample Input 
// 4 
// 10 
// 21 
// 12 
// 20 
// Sample Output 
// 4 4 4 
// 1 1 1 
// 4 2 4

