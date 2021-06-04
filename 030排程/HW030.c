#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 999

typedef struct _job {
    int machine;
    int timeCost;
} job;

typedef struct _work {
    int jobCount;
    job *jobs;
    int progress;
    int time;
} work;

int max(int a, int b) {
    return a>b?a:b;
}


int main() {
    int machineCount, workCount;
    int totalJob = 0;
    scanf("%d%d", &machineCount, &workCount);
    int *machinesTime = (int *) malloc(machineCount * sizeof(int));
    work works[workCount];
    for(int i=0; i<machineCount; i++)
        machinesTime[i] = 0;
        
    for (int i=0; i<workCount; i++) {
        works[i].progress = 0;
        works[i].time = 0;
        works[i].jobs = (job *) malloc(100 * sizeof(job));
        scanf("%d", &works[i].jobCount);
        totalJob += works[i].jobCount;
        for (int j=0; j<works[i].jobCount; j++) {
            scanf("%d%d", &works[i].jobs[j].machine, &works[i].jobs[j].timeCost);
        }
    }
    
    for (int i=0; i<totalJob; i++) {
        int time[workCount];
        int target = 0;
        for (int j=0; j<workCount; j++) {
            if (works[j].progress < works[j].jobCount) {
                time[j] = works[j].jobs[works[j].progress].timeCost + max(works[j].time, machinesTime[works[j].jobs[works[j].progress].machine]);
            } else {
                time[j] = N;
            }
            if (time[j] < time[target]) {
                target = j;
            }
        }
        int cost = works[target].jobs[works[target].progress].timeCost;
        machinesTime[works[target].jobs[works[target].progress].machine] = cost + max(machinesTime[works[target].jobs[works[target].progress].machine], works[target].time);
        works[target].time = machinesTime[works[target].jobs[works[target].progress].machine];
        works[target].progress++;
    }
    int totalTime = 0;
    for (int i=0; i<workCount; i++) {
        totalTime += works[i].time;
    }
    printf("%d\n", totalTime);
    return 0;
}




// ***請務必使用struct進行解題*** 

// 有M個工作要在N台機器上加工，每個工作i包含若干個工序Oij， 
// 這些工序須依序加工，也就是前一道工序Oi(j-1)完成後才可開始下一道工序Oij。 
// 每道工序oij可用一個有序對(kij,tij)表示它需在機器kij上面花費tij小時完成。 
// 每台機器一次只能處理一道工序。 
// 所謂一道工序Oij的「最早完成時間的cij*｣是指考慮目前排程中機器kij之可用性 
// 以及前一道工序Oi(j-1)(若該工序存在)之完成時間後可得的最早完成時間。 
// 工廠經理安排所有工廠經理安排所有工序的排程規則如下： 

// 針對每一個工作的第一個尚未排程的工序，計算出此工序的「最早完成時間｣， 
// 然後挑選出最早完成時間最小的工序納入排程，如果有多個完成時間都是最小， 
// 則挑選其中工作編號最小之工序。 
// 一個工序一旦納入排程就不會再更改，重複以上步驟直到所有工序皆納入排程。 

// ------------------------------------------------------------------------ 
// for example : 

// 工作1(以○代表) o11 = (2, 4) o12 = (1, 1) 
// 此工作有兩道工序，第一道需要在機器2執行4小時， 第二道需要在機器1執行1小時。 

// 工作2(以■代表) o21 = (0, 2) o22 = (2, 2) o23 = (0, 1) 
// 有三道工序，第一道需要在機器0執行2小時，餘類推。 

// 工作3(以●代表) o31 = (0, 7) 有一道工序需要在機器0執行7小時。 

// 排程過說明如下: 
// 1. 在開始時，每個工作都是考慮第一道工序， 
// 三個工作第1道工序需要的時間分別是 t11 = 4、t21 = 2、t31 = 7， 
// 這也是它們的最早完成時間， 也就是c11=4、c21=2、c31=7， 
// 因此會先排o21。 
// ==================================== 
// 機器0→■■□□□□□□□□□□□□--------------工作一○ 
// 機器1→□□□□□□□□□□□□□□--------------工作二■ 
// 機器2→□□□□□□□□□□□□□□--------------工作三● 
// ==================================== 

// 2. 接下來， 三個工作要考慮的順序分別是第1、2、1個工序， 
// 即 o11、o22和o31。 
// –(1) o11 需要機器2執行4小時，而機器 2可以開始加工的時間點是0；o11沒有前一道工序。 
// ------因此，這工序可以開始的時間 是 max(0, 0) = 0。是故，其最早完成時間 c11= max(0,0)+ 4 = 4。 
// –(2) o22 需機器2執行2小時，而機器2可開始加工時間點是0； 
// ------o22前一道工序o21完成時間是2。因此，這工序可以開始的時 間是max(0, 2) = 2。 
// ------最早完成時間 c22=max(0,2)+2= 4。 
// –(3) o31 需機器0執行 7小時，而機器0可開始加工的時間點是 2； 
// ------o31沒有前一道工序。因此，這工序可開始的時間是max(2, 0) = 2。 
// ------其最早完成時間c31* = max(2, 0) + 7 = 9。 

// 因此，由於c11* 和 c22* 都是最小，根據規則，工作編號小的先 排，所以會排 o11。 
// ==================================== 
// 機器0→■■□□□□□□□□□□□□--------------工作一○ 
// 機器1→□□□□□□□□□□□□□□--------------工作二■ 
// 機器2→○○○○□□□□□□□□□□--------------工作三● 
// ==================================== 

// 3. 三個工作目前要考慮的順序分別第2、2、1個工序 。 
// ----依照類似推論，可得到c12 = 5，c22 = 6，c31 = 9，因此排o12。工作1的工序均已排完，所以它的完成時間是5。 
// 4. 剩下工作2與 3。c22 = 6，c31 = 9，因此先排o22。 
// 5. c23=7而c31 = 9，因此排o23，工作2的工序已排完，所以它的 完成時間是7。 
// 6. 剩下工作3，因為機器0的下一個可以開始時間是7，o31的完 成時間是7+7=14。 

// ==================================== 
// 機器0→■■□□□□■●●●●●●●--------------工作一○ 
// 機器1→□□□□○□□□□□□□□□--------------工作二■ 
// 機器2→○○○○■■□□□□□□□□--------------工作三● 
// ==================================== 
// 三個工作完成時間分別是5、7、14，輸出答案 5+7+14=26。 

// ------------------------------------------------------------------------ 

// 輸入格式 
// 第一行有兩個整數N與 M，代表N台機器與M個工作 ， 
// 接下 來有M個工作資訊 ， 輸入順序即是工作編號順序。 
// 每個工作 資訊包含兩行，第一是整數P，代表到工序數量； 
// 第二行是 2*P個整數 ，每兩個一組依序代表一道 工序的機器編號與需求 時間。 
// 機器的編號由0開始 。參數N、M、P 以及每個工序的 需求時間都是不超過100的正整數。 

// 輸出格式 
// 輸出每個"工作"的完成時間的總和 。 
// ------------------------------------------------------------------------ 
// 範例輸入一 : 
// 3 3 
// 2 
// 2 4 1 1 
// 3 
// 0 2 2 2 0 1 
// 1 
// 0 7 

// 範例輸出一 : 
// 26 

// 範例輸入二 : 
// 2 3 
// 1 
// 0 4 
// 1 
// 1 5 
// 1 
// 1 3 

// 範例輸出二 : 
// 15 
