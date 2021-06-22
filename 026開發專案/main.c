#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void input(char* s) {
	//setbuf(stdin, NULL);
	fgets(s, 100, stdin);
	if (s[strlen(s) - 1] == '\n') {
		s[strlen(s) - 1] = '\0';
	}
}
typedef struct node
{
	int id; 	
	int day;
	int edges;
	struct node **Next;
} Node;
int bfs(Node* node, int n,int length) {

	if (node->id == n - 1) { //最後一個
		return length;
	}
	int max = 0;
	
	for (int i = 0; i < node->edges; i++) {
		if (node->Next[i] != NULL) {
			length += node->Next[i]->day;
			int result = bfs(node->Next[i], n, length);
			if ( result > max) {
				max =  result;
			}
			length -= node->Next[i]->day; //平行時所走的路
		}
	}

	return max;
}
int main() {
	int Datas=0;
	scanf("%d", &Datas);
	
	int* ans = (int*)calloc(Datas, sizeof(int));
	for (int i = 0; i < Datas;i++) {
		int N=0;
		scanf("%d\n" ,&N);
		
		Node** nodes = (Node**)calloc(N, sizeof(Node*));
		for (int j = 0; j < N; j++)// 初始化
		{
			nodes[j] = (Node *)calloc(1, sizeof(Node));
			nodes[j]->day = 0;
			nodes[j]->edges = 0;
			nodes[j]->id = j;
			nodes[j]->Next = NULL; // (Node**)calloc(N, sizeof(Node*));
		}
		for (int j = 0; j < N; j++) {
			char s[100]="";
			//setbuf(stdin, NULL);
			gets(s);
			char *split = strtok(s, " ");
			//printf("%s",split);
			nodes[j]->id = j;
			nodes[j]->day = atoi(split);
			split = strtok(NULL, " ");
			nodes[j]->edges = atoi(split);
			//printf(" %s",split);
			if (nodes[j]->edges == 0) {
				continue;
			}
			nodes[j]->Next = (Node**)calloc(nodes[j]->edges , sizeof(Node*));
			split = strtok(NULL, " ");
			//printf(" %s\n",split);
			for(int e = 0 ; split != NULL ;e++ )
			{
				int edge = atoi(split)-1;

				
				//nodes[edge] = (Node*)calloc(1, sizeof(Node));;
				
				nodes[j]->Next[e] = nodes[edge];
				
				split = strtok(NULL, " ");
			}
		}
		ans[i] = bfs(nodes[0], N, nodes[0]->day);
		printf("%d\n", ans[i]);
		


	}
}
/*

開發專案時，
專案會被分割為許多項目，分配給多組程式設計師開發。
但這些項目是有順序關係，只有當順序在前的項目完成，才能開始開發順序在後的項目。
用一個有向無環圖，表示這些開發順序。
每個節點代表一個項目，節點內的數字為節點編號， 上方所列數字代表開發這個項目所需天數；
邊表示開發順序。
以下方敘述為例，只有在節點2完成後，才能開始節點4的開發。
同理，只有在節點3與節點4都完成後，才能開始節點5的開發。
一軟體公司的專案準備開始開發，你是公司專案經理，根據開發流程圖，
老闆想知道專案要多久才能完成。
------------------------------------------------------------------
例子 :
節點1→6天
節點2→5天
節點3→11天
節點4→4天
節點5→8天

節點1→節點2→節點4→節點5
↓
節點3______________↗

------------------------------------------------------------------
輸入 :
第一行是整數，代表後續測試資料組數。
每組測試資料代 表專案有向圖。
每組測試資料的第一行是正整數N，代表專案 共有 N 個工作事項(節點)，N<=100。
接下來N 行測試資料，每一行依序代表一個項目節點(從第1個節點開始)，
第一個正整數表示完成這個項目所需天數，
第二個正整數 K 表示這個節點有K 條指向其他節點的邊，
接下來K 個正整數表示所指向的項目節點編號。

輸出 :
從第1個節點到最後一個節點N總共所需要花費的時間。
---------------------------------------------------------------------------

範例輸入 :
2
2
8 1 2
2 0
5
6 2 2 3
5 1 4
11 1 5
4 1 5
8 0

範例輸出 :
10
25
*/