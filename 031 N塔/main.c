#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n) {
    int accu = 1;
    int i;
    for(i = 1; i <= n; i++) {
        accu *= i;
    }
    return accu;
}

int pop(int *arr, int size, int index){
    int result = arr[index];
    for (int i=index; i<size-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[size-1] = 0;
    return result;
}

void path(int vertexCount, int vertexs[vertexCount], int curVertex, int N, int distance[N][N], int sum, int *results, int *resultIndex/*, char *logging */){
    
//Print path for debugging
//    char log = curVertex + '0';
//    char strLog[2];
//    strLog[0] = log;
//    strLog[1] = '\0';
//    char newlog[100] = "";
//    char arrow[3] = "->";
//    strcat(newlog, logging);
//    if(curVertex != 1)
//        strcat(newlog, arrow);
//    strcat(newlog, strLog);
    
    if(vertexCount == 1){
//        log = vertexs[0] + '0';
//        strLog[0] = log;
//        strcat(newlog, arrow);
//        strcat(newlog, strLog);
        
        sum += distance[curVertex-1][vertexs[0]-1];
        results[*resultIndex] = sum;
        *resultIndex += 1;
//        printf("%s: %d\n", newlog, sum);
        return;
    }
    for (int i=0; i<vertexCount; i++) {
        int nextVertexs[vertexCount];
        for (int i=0; i<vertexCount; i++)
            nextVertexs[i] = vertexs[i];

        int newSum = sum + distance[curVertex-1][vertexs[i]-1];
        int nextVertex = pop(nextVertexs, vertexCount, i);
        path(vertexCount-1, nextVertexs, nextVertex, N, distance, newSum, results, resultIndex/*, newlog*/);
    }
    
    
}

int compare(const void *elem1, const void *elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    int distance[N][N];
    int results[factorial(N-1)];
    int vertexs[N-1];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &distance[i][j]);
    for (int i=0; i<N - 1; i++) {
        vertexs[i] = i + 2;
    }
    int *resultIndex = malloc(sizeof(int));
    *resultIndex = 0;
    //char logging[10] = "";
    path(N-1, vertexs, 1, N, distance, 0, results, resultIndex/*, logging*/);
    qsort (results, sizeof(results)/sizeof(*results), sizeof(*results), compare);
    printf("%d\n", results[0]);
    return 0;
}




/*

賴先生騎腳踏車挑戰一日N塔，N<10。 
每一個塔位在編號 1, 2, 3, ...,N 城市中。 
兩兩個城市都有一段距離的公路相連。 
請計算 "從第 1 個" 城市出發，"騎過每一個" 城市的 "最短距離"。 
例如 : 
N = 5，以下是兩兩城市之間公路的距離 : 

--- C1 C2 C3 C4 C5 
C1 0 4 2 3 6 
C2 4 0 3 1 4 
C3 2 3 0 2 5 
C4 3 1 2 0 3 
C5 6 4 5 3 0 

城市 C1 和城市 C1 的距離是 0 (同一個地方)， 
城市 C1 和城市 C2 的距離是 4， 
城市 C1 和城市 C3 的距離是 2， 
城市 C1 和城市 C4 的距離是 3， 
城市 C1 和城市 C5 的距離是 6， 
等等...以此類推 

則從城市 1 出發，騎完所有城市的距離最短是，經由 13245 的距離 = 2+3+1+3= 9。 
---------------------------------------------------------------------------------- 
輸入說明 
第 1 筆資料是 N， 
第 2 筆資料是第 1 個城市和其他城市的公路距離。 
第 3 筆資料是第 2 個城市和其他城市的公路距離。 
.... 
第 N+1 筆資料是第 N 個城市和其他城市的公路距離。 
輸出說明 
輸出從第 1 個城市出發，騎完所有城市最短距離。 
---------------------------------------------------------------------------------- 
sample input : 
5 
0 4 2 3 6 
4 0 3 1 4 
2 3 0 2 5 
3 1 2 0 3 
6 4 5 3 0 

sample output : 
9 
---------------------- 

sample input : 
4 
0 18 52 23 
18 0 12 11 
52 12 0 3 
23 11 3 0 

sample output : 
32

*/
