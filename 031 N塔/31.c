#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
void input(char *s){
    memset(s,'\0',500);
    fgets(s,500,stdin);
    if( s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}
int bfs(int **map,int *arrive,int n,int city ,int distance){
   
    int finish = 1;

    for(int i = 0 ; i < n ;i++)
        if(arrive[i] == 0){finish = 0;break;}
    if(finish == 1 )
        return distance;
  
    int min = INT_MAX;
    for(int i = 0 ; i < n;i++)
    {
        
        if(map[city][i] != 0 && arrive[i] == 0 ){
            arrive[i] = 1;
            printf("%d -> %d distance:%d\n",city+1,i+1,map[city][i]);
            int temp = bfs(map,arrive,n,i,distance+map[city][i]);
            printf("temp: %d\n",temp);
            arrive[i] = 0;
            if(min > temp){
                min = temp;
            }
        }
        // for(int j=0;j<n;j++){
        //     printf("%d ",arrive[j]);
        // }
        // printf("\n");
    }
    return min;
}
int main(){
    int n;
    int **map,*arrive;
    map = calloc(n,sizeof(int*));
    arrive = calloc(n,sizeof(int));
    scanf("%d\n",&n);
    char s[500];
    input(s);
    for(int i = 0 ; i < n ;i++)
    {
        arrive[i] = 0;
        map[i] = calloc(n,sizeof(int));
        input(s);
        char *split;
        split = strtok(s," ");
        split = strtok(NULL," ");
        int j = 0;
        while ( split != NULL)
        {
            map[i][j] = atoi(split);
            j++;
            split = strtok(NULL," ");
        }
        
    }
    arrive[0] = 1;
    // for(int i=0;i<n;i++)
    //     printf("%d ",arrive[i]);
    // printf("\n");
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d",bfs(map,arrive,n,0,0));
}
/*
賴先生騎腳踏車挑戰一日N塔，N<10。
每一個塔位在編號 1, 2, 3, ...,N 城市中。
每兩個城市都有一段距離的公路相連。
先輸入一個正整數N，
再輸入各個城市距離的對照表(第一行和第一列為城市之間對應關係，其他數字為兩個城市之間的距離)，
請輸出從第 1 個城市出發，騎過每一個城市的最短距離為多少?

範例一：
---------------------------------------------------
input:
5
0 1 2 3 4 5
1 0 4 2 3 6
2 4 0 3 1 4
3 2 3 0 2 5
4 3 1 2 0 3
5 6 4 5 3 0
---------------------------------------------------
output:
9
---------------------------------------------------
說明：
五個城市兩兩城市之間公路的距離：
城市 1 和城市 2 的距離是 4
城市 1 和城市 3 的距離是 2
城市 1 和城市 4 的距離是 3
城市 1 和城市 5 的距離是 6
城市 3 和城市 4 的距離是 2
城市 5 和城市 4 的距離是 3
.......以此類推
最短路徑：1 -> 3 -> 2 -> 4 -> 5
最短距離：2 + 3 + 1 + 3 = 9
---------------------------------------------------

範例二：
---------------------------------------------------
input:
6
0 1 2 3 4 5 6
1 0 4 2 3 6 3
2 4 0 3 1 4 5
3 2 3 0 2 5 3
4 3 1 2 0 3 3
5 6 4 5 3 0 2
6 3 5 3 3 2 0
---------------------------------------------------
output:
11


*/
