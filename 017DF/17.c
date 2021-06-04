#include <stdio.h>
#include <string.h>
char readQueue(char* str){
    char result = str[0];
    //左移動
    for (int i=0; i<strlen(str); i++) {
        str[i] = str[i+1];
    }
    return result;
}

int myFunc(int length, int arr[length][length], int curSize, char *input, int i, int j){
    switch (readQueue(input)) {
        case '0':
            return 0;
            break;
        case '1':
            for (int y = j; y < j + curSize; y++)
                for (int x = i; x < i + curSize; x++)
                    arr[y][x] = 1;           //printf("%d,%d\n", y, x);
            
            return pow(curSize, 2);
            break;
        case '2':{
            int topLeft     = myFunc(length, arr, curSize/2, input, i, j);
            int topRight    = myFunc(length, arr, curSize/2, input, i+curSize/2, j);
            int bottomLeft  = myFunc(length, arr, curSize/2, input, i, j+curSize/2);
            int bottomRight = myFunc(length, arr, curSize/2, input, i+curSize/2, j+curSize/2);
            return topLeft + topRight + bottomLeft + bottomRight;
            break;
        }
        default:
            return 0;
            break;
    }
}










int main(){
    char input[300];
    int length;
    scanf("%s", input);
    scanf("%d", &length);
    int arr[length][length];
    memset(arr, 0, sizeof(arr));
    int count =  myFunc(length, arr, length, input, 0, 0);
    for (int i=0; i<length; i++)
        for (int j=0; j<length; j++)
            if(arr[i][j])
                printf("%d,%d\n", i, j);
    if(!count)
        printf("all white\n");
}

















// DF - expression是儲存圖片資訊的表達方式。 
// 在一個n*n方陣中，若方格是白色記為0；黑色記為1； 
// 若方格可分為更小方格(左上、右上、左下、右下)，則記2，再依序(左上→右上→左下→右下)記錄這四個方格的資訊。 
// 以下圖為例 : 
// 第一張圖全為白，所以輸出為0。 
// 第二張圖全為黑，所以輸出為1。 
// 第三張圖因為有黑有白，所以記為2，接著繼續切，從左上開始，全為白，記為0，再來右上，有黑有白繼續切，記為2，接著繼續從右上那塊往下做，從左上開始，全為白，記為0，再來右上(白)，記0，左下(黑)，記1，右下(白)，記0，接著回到外面那塊的左下(黑)，記1，再來右下(白)，記0。最後輸出為202001010。 

// □□□□ 
// □□□□ 
// □□□□ 
// □□□□ 
// 0 

// ■■■■ 
// ■■■■ 
// ■■■■ 
// ■■■■ 
// 1 

// □□|□□ 
// □□|■□ 
// -------- 
// ■■|□□ 
// ■■|□□ 
// 202001010 

// 輸入：給定DF - expression的輸入、這張圖像寬度(必為2的非負整數次方) 
// 輸出：這張圖中黑色格子的座標位置(輸出座標順序由左而右、由上到下，最左上為0,0)，如無黑色格子則輸出all white。 

// Sample Input 
// 1 
// 2 

// Sample Output 
// 0,0 
// 0,1 
// 1,0 
// 1,1 
// ------------------------------- 
// Sample Input 
// 202001010 
// 4 

// Sample Output 
// 1,2 
// 2,0 
// 2,1 
// 3,0 
// 3,1

