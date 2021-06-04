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




// 開發專案時， 
// 專案會被分割為許多項目，分配給多組程式設計師開發。 
// 但這些項目是有順序關係，只有當順序在前的項目完成，才能開始開發順序在後的項目。 
// 用一個有向無環圖，表示這些開發順序。 
// 每個節點代表一個項目，節點內的數字為節點編號， 上方所列數字代表開發這個項目所需天數； 
// 邊表示開發順序。 
// 以下方敘述為例，只有在節點2完成後，才能開始節點4的開發。 
// 同理，只有在節點3與節點4都完成後，才能開始節點5的開發。 
// 一軟體公司的專案準備開始開發，你是公司專案經理，根據開發流程圖， 
// 老闆想知道專案要多久才能完成。 
// ------------------------------------------------------------------ 
// 例子 : 
// 節點1→6天 
// 節點2→5天 
// 節點3→11天 
// 節點4→4天 
// 節點5→8天 

// 節點1→節點2→節點4→節點5 
// ↓ 
// 節點3______________↗ 

// ------------------------------------------------------------------ 
// 輸入 : 
// 第一行是整數，代表後續測試資料組數。 
// 每組測試資料代 表專案有向圖。 
// 每組測試資料的第一行是正整數N，代表專案 共有 N 個工作事項(節點)，N<=100。 
// 接下來N 行測試資料，每一行依序代表一個項目節點(從第1個節點開始)， 
// 第一個正整數表示完成這個項目所需天數， 
// 第二個正整數 K 表示這個節點有K 條指向其他節點的邊， 
// 接下來K 個正整數表示所指向的項目節點編號。 

// 輸出 : 
// 從第1個節點到最後一個節點N總共所需要花費的時間。 
// --------------------------------------------------------------------------- 
// day branch who
// 範例輸入 : 
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

// 範例輸出 : 
// 10 
// 25