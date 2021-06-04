#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum Score_type{ G = 1, GPA, S };

union Score{
    char G[5];
    double GPA;
    char S[50];
} score;


typedef struct Student{
    int id;
    double avg;
} Stu;

int GtoInt(){
    fgets(score.G, 5, stdin);
    if(score.G[strlen(score.G)-1] == '\n'){
        score.G[strlen(score.G)-1] = '\0';
    }
    if(score.G[strlen(score.G)-1] == ' '){
        score.G[strlen(score.G)-1] = '\0';
    }
    if(!strcmp("A+", score.G))
        return 95;
    if(!strcmp("A", score.G))
        return 87;
    if(!strcmp("A-", score.G))
        return 82;
    if(!strcmp("B+", score.G))
        return 78;
    if(!strcmp("B", score.G))
        return 75;
    if(!strcmp("B-", score.G))
        return 70;
    if(!strcmp("C+", score.G))
        return 68;
    if(!strcmp("C", score.G))
        return 65;
    if(!strcmp("C-", score.G))
        return 60;
    if(!strcmp("F", score.G))
        return 50;

    
    return 50;
}

int GPAtoInt(){
    scanf("%lf", &score.GPA);
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    
    if(score.GPA >= 4.3)
        return 95;
    if(score.GPA >= 4.0)
        return 87;
    if(score.GPA >= 3.7)
        return 82;
    if(score.GPA >= 3.3)
        return 78;
    if(score.GPA >= 3.0)
        return 75;
    if(score.GPA >= 2.7)
        return 70;
    if(score.GPA >= 2.3)
        return 68;
    if(score.GPA >= 2.0)
        return 65;
    if(score.GPA >= 1.7)
        return 60;
    if(score.GPA >= 0)
        return 50;
    
    return 50;
}

int StoInt(){
    fgets(score.S, 50, stdin);
    if(score.S[strlen(score.S)-1] == '\n'){
        score.S[strlen(score.S)-1] = '\0';
    }
    if(score.S[strlen(score.S)-1] == ' '){
        score.S[strlen(score.S)-1] = '\0';
    }
    if(!strcmp("90-100", score.S))
        return 95;
    if(!strcmp("85-89", score.S))
        return 87;
    if(!strcmp("80-84", score.S))
        return 82;
    if(!strcmp("77-79", score.S))
        return 78;
    if(!strcmp("73-76", score.S))
        return 75;
    if(!strcmp("70-72", score.S))
        return 70;
    if(!strcmp("67-69", score.S))
        return 68;
    if(!strcmp("63-66", score.S))
        return 65;
    if(!strcmp("60-62", score.S))
        return 60;
    if(!strcmp("59以下", score.S))
        return 50;
    
    return 50;
}

int compare(const void *p, const void *q) {
    Stu l = *(Stu *)p;
    Stu r = *(Stu *)q;
    return r.avg - l.avg;
}


int main(){
    int M = 0;
    int studentCount = 0;
    scanf("%d\n", &M);
    int measure[M];
    for(int i=0; i<M; i++){
        char input[5];
        fgets(input, 5, stdin);
        if(input[strlen(input)-1] == '\n'){
            input[strlen(input)-1] = '\0';
        }
        if (input[0] == 'S') {
            measure[i] = S;
        } else if (!strcmp(input, "GPA")) {
            measure[i] = GPA;
        } else {
            measure[i] = G;
        }
    }
    scanf("%d", &studentCount);
    Stu students[studentCount];
    for (int i=0; i<studentCount; i++) {
        scanf("%d", &students[i].id);
        while(getchar() != '\n');
        int total = 0;
        for (int j=0; j<M; j++) {
            switch (measure[j]){
                case G:
                    total += GtoInt();
                    break;
                case GPA:
                    total += GPAtoInt();
                    break;
                case S:
                    total += StoInt();
                    break;
                default:
                    break;
            }
        }
        students[i].avg = (double)total / M;
    }
    qsort((void*)students, studentCount,sizeof(students[0]), compare);
    for (int i=0; i<3; i++) {
        printf("%d\n%.0f\n", students[i].id, round(students[i].avg));
    }
    return 0;
}


// ********：必須使用enum定義不同評分制資料型別，使用union定義分數資料型別。*********** 
// 一個班級有N位同學(ID)，M門課，每一門課可以設定評分方式。 
// 設定M門課評分制，輸入N位同學M門課成績，根據下表換算，計算每一位同學百分制對照平均成績， 
// 印出前三名ID與平均成績，四捨五入到整數。 

// 等第 GPA 百分制區間 百分制對照 
// A+   4.3 90-100   95 
// A    4.0 85-89    87 
// A-   3.7 80-84    82 
// B+   3.3 77-79    78 
// B    3.0 73-76    75 
// B-   2.7 70-72    70 
// C+   2.3 67-69    68 
// C    2.0 63-66    65 
// C-   1.7 60-62    60 
// F    0   59以下    50 



// 先輸入有幾門課 M ，並依序設定評分方式 等第 = G, GPA = GPA,百分制區間 = S 
// 在輸入學生數量與學生學號、成績。 

// 範例1. 
// Input: 
// 2 
// G 
// GPA 
// 5 
// 10801 
// A+ 
// 4.3 
// 10802 
// B+ 
// 4.0 
// 10803 
// B- 
// 3.3 
// 10804 
// C 
// 2.3 
// 10805 
// F 
// 0 
// Ouput: 
// 10801 
// 95 
// 10802 
// 83 
// 10803 
// 74 

// 範例2. 

// Input: 
// 2 
// G 
// S 
// 5 
// 10801 
// F 
// 59以下 
// 10802 
// C 
// 63-66 
// 10803 
// B 
// 73-76 
// 10804 
// A 
// 85-89 
// 10805 
// A+ 
// 90-100 

// Output: 
// 10805 
// 95 
// 10804 
// 87 
// 10803 
// 75


