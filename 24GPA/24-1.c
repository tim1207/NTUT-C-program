/*
題目:
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
#include <stdio.h>
#include <string.h>
#include <math.h>
void main(){
	int i,j,k,l,classes,std_amount,num;
	char* s[]={"A+","A","A-","B+","B","B-","C+","C","C-","F"};
	char* interval[]={"90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","59以下"};
	char* GPAnum[]={"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","0"};
	float Score[]={95,87,82,78,75,70,68,65,60,50};
	scanf("%d\n",&classes);					//輸入課堂數 
	char judge[classes][100];				//儲存成績的樣式是來自於GPA、G或S 
	for(i=0;i<classes;i++){
		scanf("%s",&judge[i]);
	}
	scanf("%d\n",&std_amount);
	int stdnumber[std_amount];
	float total[std_amount];
	for(i=0;i<std_amount;i++)total[i]=0.0; 
	char stdcourse[std_amount][classes][100]; //儲存未轉換前的成績 
	for(i=0;i<std_amount;i++){				//輸入學號與成績 
		scanf("%d\n",&num);
		stdnumber[i]=num;
		for(j=0;j<classes;j++){
			scanf("%s",&stdcourse[i][j]);
		}	
	}
	for(i=0;i<classes;i++){                                  //開始判斷資料是GPA還是G或S
		if(strcmp(judge[i],"G")==0){						 //如果是G就將分數轉換 
				for(k=0;k<std_amount;k++){
					for(j=0;j<10;j++){
						if(strcmp(stdcourse[k][i],s[j])==0){
							total[k]+=Score[j];
						}
					}
				}
	}
		else if(strcmp(judge[i],"S")==0){					//同上 轉換S 
				
				for(k=0;k<std_amount;k++){
					for(j=0;j<10;j++){
						if(strcmp(stdcourse[k][i],interval[j])==0){
							total[k]+=Score[j];
						}
					}
				}
		}
		else if(strcmp(judge[i],"GPA")==0){					//同上 轉換GPA 
		
				for(k=0;k<std_amount;k++){
					for(j=0;j<10;j++){
						if(strcmp(stdcourse[k][i],GPAnum[j])==0){
							total[k]+=Score[j];
						}
					}
				}
		}
    }
	for(i=0;i<3;i++){				//這邊是找出3個連續的最大值 
		int max=0,state=0;			//一開始要預設初始值，不然沿用上次的max就跑不進去fo迴圈了 ，state用來存最大值的位置。 
		for(j=0;j<std_amount;j++){
			if(max<total[j]){
				max=total[j];		//max會一直被取代，直到他是最大 
				state=j;
			}
		}
		printf("%d\n%.f\n",stdnumber[state],round(total[state]/classes)); //將學號與成績印出(round的功能可以四捨五入,不過裡面的資料型態必須是浮點數) 
		total[state]=0;				//將本來的最大值設為零，避免下次要找的會再重複。 
	}		
}


 
