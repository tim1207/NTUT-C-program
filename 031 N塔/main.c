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
