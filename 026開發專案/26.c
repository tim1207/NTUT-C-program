#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue_t{
    int* array;
    int size;
    int index;
}queue;

void init( queue* q){
    q->array = calloc(10000, sizeof(int)); 
    q->index = 0;
    q->size = 0;
}

void printQueue( queue* q){
    for(int i = q->index; i < q->size; i++)
        printf("%d ", q->array[i]);
}

int front( queue* q){
 return q->array[q->index];
}

void pop( queue* q){
    q->index += 1;
}

void push( queue* q, int element){
    q->array[q->size] = element;
    q->size += 1;
}

int empty( queue* q){
    if(q->size == q->index) 
        return 1;
    else 
        return 0;
}

int max(int a, int b){
    return a > b ? a : b;
}

void CostTime(int** array, int* origCostTime, int* costTime, int* nodeCount, int* soFarTime, int* visited){
     queue* q = calloc(1, sizeof( queue));
    init(q);
    push(q, 1);
    while(!empty(q)){
        int top = front(q);
        int mx = 0;
            for(int i = 0; i < nodeCount[top]; i++){
                costTime[array[top][i]] = max(origCostTime[array[top][i]] + costTime[top], costTime[array[top][i]]);
                if(visited[array[top][i]]) 
                    continue;
                    push(q, array[top][i]);
                visited[array[top][i]] = 1;
            }
        pop(q); 
    }
}

int main(){
    int testtime;
    scanf("%d", &testtime);
    while(testtime--){
        int** array = calloc(100, sizeof(int*));
        int* origCostTime = calloc(100, sizeof(int));
        int* costTime = calloc(100, sizeof(int));
        int* nodeCount = calloc(100, sizeof(int));
        int* soFarTime = calloc(100, sizeof(int));
        int* visited = calloc(100, sizeof(int));
        for(int i = 0; i < 100; i++)
            array[i] = calloc(100, sizeof(int));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int k;
            scanf("%d", &k);
            origCostTime[i] = k;
            costTime[i] = k;
            int m;
            scanf("%d", &m);
            nodeCount[i] = m;
            for(int j = 0; j < m; j++)
                scanf("%d", &array[i][j]); 
        }
        CostTime(array, origCostTime, costTime, nodeCount, soFarTime, visited);
        visited = calloc(100, sizeof(int));
        CostTime(array, origCostTime, costTime, nodeCount, soFarTime, visited);
        int mx = 0;
        for(int i = 1; i <= n; i++)
            mx = max(mx, costTime[i]);
        printf("%d\n", mx);
    }
}




// ?????????????????? 
// ??????????????????????????????????????????????????????????????????????????? 
// ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????? 
// ?????????????????????????????????????????????????????? 
// ????????????????????????????????????????????????????????????????????? ????????????????????????????????????????????????????????? 
// ???????????????????????? 
// ???????????????????????????????????????2??????????????????????????????4???????????? 
// ????????????????????????3?????????4?????????????????????????????????5???????????? 
// ???????????????????????????????????????????????????????????????????????????????????????????????? 
// ????????????????????????????????????????????? 
// ------------------------------------------------------------------ 
// ?????? : 
// ??????1???6??? 
// ??????2???5??? 
// ??????3???11??? 
// ??????4???4??? 
// ??????5???8??? 

// ??????1?????????2?????????4?????????5 
// ??? 
// ??????3______________??? 

// ------------------------------------------------------------------ 
// ?????? : 
// ?????????????????????????????????????????????????????? 
// ????????????????????? ????????????????????? 
// ??????????????????????????????????????????N??????????????? ?????? N ???????????????(??????)???N<=100??? 
// ?????????N ?????????????????????????????????????????????????????????(??????1???????????????)??? 
// ????????????????????????????????????????????????????????? 
// ?????????????????? K ?????????????????????K ?????????????????????????????? 
// ?????????K ??????????????????????????????????????????????????? 

// ?????? : 
// ??????1??????????????????????????????N????????????????????????????????? 
// --------------------------------------------------------------------------- 
// day branch who
// ???????????? : 
// 2 
// 2 
// 8 1 2 
// 2 0 
// 5 
// 6 2 2 3 
// 5 1 4 
// 11 1 5 
// 4 1 5 
// 8 0 

// ???????????? : 
// 10 
// 25