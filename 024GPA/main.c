#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
float transform(char *way,char* s) {
	char* G[] = { "A+","A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F" };
	char* GPA[] = { "4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","0" };
	char* S[] = { "90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","59�H�U" };
	float table[] = { 95,87,82,78,75,70,68,65,60,50 };
	int idx = -1;
	if (strcmp(way, "G") == 0) {
		for (int i = 0; i < 10; i++) {
			if (strcmp(s, G[i]) == 0) {
				idx = i;
				break;
			}
		}
	}
	else if (strcmp(way, "GPA") == 0) {
		for (int i = 0; i < 10; i++) {
			if (strcmp(s, GPA[i]) == 0) {
				idx = i;
				break;
			}
		}
	}
	else if (strcmp(way, "S") == 0) {
		for (int i = 0; i < 10; i++) {
			if (strcmp(s, S[i]) == 0) {
				idx = i;
				break;
			}
		}
	}
	return table[idx];
}
int main() {
	
	char** gradeWay;
	char** studentName;
	int M, N;
	scanf("%d", &M);
	float *gradeAvg;
	
	gradeWay = (char**)calloc(M, sizeof(char*));
	for (int i = 0; i < M; i++) {
		char s[10];
		scanf("%s", &s);
		gradeWay[i] = (char*)calloc(10, sizeof(char));
		
		strcpy(gradeWay[i], s);
	}
	scanf("%d", &N);
	gradeAvg = (int*)calloc(N, sizeof(float));
	studentName = (char**)calloc(N, sizeof(char*));
	for (int i = 0; i < N; i++) {
		char s[10];
		scanf("%s", &s);
		studentName[i] = (char*)calloc(10, sizeof(char));
		
		strcpy(studentName[i], s);
		for (int j = 0; j < M; j++) {
			memset(s, '\0', 10);
			scanf("%s", &s);
			float grade = transform(gradeWay[j], s);
			gradeAvg[i] += grade;
			//printf("grade:%f\n", grade);
		}
		//printf("sum:%f\n", gradeAvg[i]);
		gradeAvg[i] /= M;
		//printf("%s:%f\n", studentName[i], gradeAvg[i]);
	}
	//改排序
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (gradeAvg[i] < gradeAvg[j]) {
				float tmp = gradeAvg[i];
				gradeAvg[i] = gradeAvg[j];
				gradeAvg[j] = tmp;
				char tmp2[10] = "";
				strcpy(tmp2, studentName[i]);
				strcpy(studentName[i], studentName[j]);
				strcpy( studentName[j], tmp2);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n%d", studentName[i],(int)round(gradeAvg[i]));
		if (i != 2)
			printf("\n");
	}

}
/*
********：必須使用enum定義不同評分制資料型別，使用union定義分數資料型別。***********
一個班級有N位同學(ID)，M門課，每一門課可以設定評分方式。
設定M門課評分制，輸入N位同學M門課成績，根據下表換算，計算每一位同學百分制對照平均成績，
印出前三名ID與平均成績，四捨五入到整數。

等第 GPA 百分制區間 百分制對照
A+ 4.3 90-100 95
A 4.0 85-89 87
A- 3.7 80-84 82
B+ 3.3 77-79 78
B 3.0 73-76 75
B- 2.7 70-72 70
C+ 2.3 67-69 68
C 2.0 63-66 65
C- 1.7 60-62 60
F 0 59以下 50



先輸入有幾門課 M ，並依序設定評分方式 等第 = G, GPA = GPA,百分制區間 = S
在輸入學生數量與學生學號、成績。

範例1.
Input:
2
G
GPA
5
10801
A+
4.3
10802
B+
4.0
10803
B-
3.3
10804
C
2.3
10805
F
0
Ouput:
10801
95
10802
83
10803
74

範例2.

Input:
2
G
S
5
10801
F
59以下
10802
C
63-66
10803
B
73-76
10804
A
85-89
10805
A+
90-100

Output:
10805
95
10804
87
10803
75

*/