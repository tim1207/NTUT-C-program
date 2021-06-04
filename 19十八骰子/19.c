#include <stdio.h>
#define CHANGE(x, y) { int temp = x; x = y; y = 7-temp; } 
#define SWAP(x, y) { int temp = x; x = y; y = temp; }

int getPoint(int data[4][3]){
    int ans=0;
    int count[7];
    for (int i=0; i<7; i++) {
        count[i]=0;
    }
    for (int i=0; i<4; i++) {
        switch (data[i][1])
        {
        case 1:
            count[1]++;
            break;
        case 2:
            count[2]++;
            break;
        case 3:
            count[3]++;
            break;
        case 4:
            count[4]++;
            break;
        case 5:
            count[5]++;
            break;
        case 6:
            count[6]++;
            break;
        
        default:
            break;
        }
    }
    int count_pair=0;
    
    for (int i = 1; i < 7; i++)
    {
        if(count[i]==4){//4個都一樣
            ans=18;
            break;
        }
        if(count[i]==2){//判斷同
            count_pair++;
        }
        if(count[i]==3)
            ans=0;        
    }
    if(count_pair==2){// 兩同
        ans=data[0][1];
        for(int i=0;i<4;i++){           
            if(ans<data[i][1]){
                ans=data[i][1];
            }
        }
        ans*=2;
    }
    if(count_pair==1){
        for(int i=6;i>0;i--){
            if(count[i]==1)
                ans+=i;
        }
    }
    return ans;
    
}


void roll(int data[], int b) {
    if (b==1) CHANGE(data[0], data[1])
    else if (b==3) CHANGE(data[2], data[1])
    else if (b==2) {
        CHANGE(data[0], data[1]);
        CHANGE(data[0], data[1]);
        CHANGE(data[0], data[1]);
    }
    else if (b==4) {
        CHANGE(data[2], data[1]);
        CHANGE(data[2], data[1]);
        CHANGE(data[2], data[1]);
    }
}
int main(){
    int m=0;
    int a[4];
    int data[4][3];
    for (int i=0; i<4; i++) {
        data[i][0]=4; data[i][1]=1; data[i][2]=2;
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
        for (int j=0; j<4; j++) 
            roll(data[j], a[j]);
    }
    
    //printf("%d %d %d %d \n", data[0][1], data[1][1], data[2][1],data[3][1]);// 上面
    printf("%d\n",getPoint(data));

}








// 十八骰子是一種常見的擲骰子遊戲，用四顆骰子計點。四顆一開始都是點數 1 朝上，點數 4 朝前，點數 2 朝右 (如下左圖所示)，骰子展開如下右圖所示。 

// 接下來 N 次修改操作，每次操作包含四個整數 a, b, c, d 代表四個骰子操作。a, b, c, d意義為： 
// 1. 1 表示向前滾一次。 
// 2. 2 表示向後滾一次。 
// 3. 3 表示向右滾一次。 
// 4. 4 表示向左滾一次。 
// 操作修正完成，請輸出點數，計點方式： 
// 1. 若四顆點數均相同，稱一色，計18點，例如6, 6, 6, 6 或 3, 3, 3, 3。 
// 2. 若四顆點數均不同；或有三顆點數相同，一顆不同，計 0點，例如 1, 2, 3, 4 或 2, 2, 2, 6。 
// 3. 若兩顆點數相同，另兩顆點數也相同，但兩組兩顆點數不同，則點數計算為 - 加總兩顆較大點數，例如 2, 2, 5, 5，加總兩顆較大點數為 5+5=10點。 
// 4. 若兩顆點數相同，另兩顆點數不同，則點數計算為加總兩顆不同點數，例如 2, 2, 4, 5，加總兩顆不同點數為 4+5=9點。 

// Sample Input 
// 1 
// 1 1 1 1 
// Sample Output 
// 18 

// Sample Input 
// 2 
// 1 2 3 4 
// 1 2 3 4 
// Sample Output 
// 18 

// Sample Input 
// 2 
// 1 2 3 4 
// 4 3 2 1 
// Sample Output 
// 0 