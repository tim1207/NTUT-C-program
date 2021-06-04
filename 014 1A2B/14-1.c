#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void intro(void);  //介紹文函數 
void prepare(void);  //準備工作之函數 
void ask(void);  //電腦問之函數 
void answer(void);  //人類答幾a幾b之函數 
void think(void);  //電腦思考之函數（其實就是從答案庫中排除不可能的答案）
void menu(void);  //選單之函數 
int answerBase[5040][4];  /*答案庫，會裝入所有重複的四位數，從1234到9876
                            5040是因為10*9*8*7，4是因為每組答案是一個四位數*/ 
int isOver,restart;  //當作布林值，判斷是否遊戲結束以及是否要繼續玩
int remain;  //答案庫裡面的答案數 
int a,b;  //拿來裝使用者回答的幾a幾b
int randNum;  //裝亂數，隨機從答案庫裡面拿答案 
int main(void){
    intro(); 
    while(1==1){
        prepare(); 
        while(!isOver){
            ask();
            answer();
            if(isOver) break;
            think();
            printf("------------------\n");
        }
        menu(); 
        if(!restart) break;
    }
    getchar();
    return 0;
}
/****** 準備工作之函數 ******/
void prepare(void){
    int i,tmp,unit_1,unit_10,unit_100,unit_1000;
    remain=5040; 
    tmp=0;  //tmp只是一個拿來計數變數 
    isOver=0;  //判斷結束與否 
    for(i=0;i<10000;i++){  //這個for產生答案庫 
        unit_1 = (i/1)%10;  //以下四行把四位數拆成四個各位數分別存到四個變數 
        unit_10 = (i/10)%10;
        unit_100 = (i/100)%10;
        unit_1000 = (i/1000)%10;
        if(unit_1!=unit_10 && unit_1!=unit_100 && unit_1!=unit_1000 && unit_10!=unit_100 && unit_10!=unit_1000 && unit_100!=unit_1000){
            answerBase[tmp][0] = unit_1000;
            answerBase[tmp][1] = unit_100;
            answerBase[tmp][2] = unit_10;
            answerBase[tmp][3] = unit_1;
            tmp++;
        }
    }
}
/****** 電腦問之函數 ******/
void ask(void){
    int i;
    printf("請問是");
    srand(time(0));
    while(1==1){
        randNum=0;
        for(i=0;i<4;i++){
            randNum *= 10;
            randNum += rand()%10;
        }
        if(randNum<remain) break;
    }
    for(i=0;i<4;i++) printf("%d",answerBase[randNum][i]);
    printf("?\n");
}
/****** 人類答之函數 ******/
void answer(void){
    char input[500];
    int right=0;  //當布林值，判斷是否正確的輸入 
    do{  //取得a,b值 
        do{  //取得a值
            printf("A:");
            fgets(input,sizeof(input),stdin);
            *(input+strlen(input)-1)='\0';
            if(strlen(input)==1 && *input-'0'<= 9 && *input-'0'>=0){
                a = *input-'0';
                right = 1;
            }else printf("輸入錯誤\n\n");
        }while(!right);
        do{  //取得b值 
            printf("B:");
            fgets(input,sizeof(input),stdin);
            *(input+strlen(input)-1)='\0';
            if(strlen(input)==1 && *input-'0'<= 9 && *input-'0'>=0){
                b = *input-'0';
                right = 1;
            }else printf("輸入錯誤\n\n");
        }while(!right);
        
        if(a+b>4){  //如果a和b相加大於4當然就錯啦～ 
            printf("輸入錯誤\n\n");
            right = 0;
        }
    }while(!right);
    if(a==4){
        printf("耶～答對了！\n");
        isOver=1;
    }else if(remain==1){  //如果答案庫只剩一個答案，但是這答案還是錯的，就是玩家作弊！ 
        printf("你作弊！= =+\n");
        isOver=1;
    }
}
/****** 電腦思考之函數 ******/
void think(void){
     int i,j,k,aa,bb;
     int refer[4];
     for(i=0;i<4;i++){
         refer[i]=answerBase[randNum][i];
     }
     for(i=0;i<remain;i++){
         aa = bb = 0;  //填裝a值和b值，但要區別於之前的人類輸入的a值b值 
         for(j=0;j<4;j++){  //以下兩個for用來比對第i個答案和亂數取的答案的是幾a幾b 
             for(k=0;k<4;k++){
                 if(answerBase[i][j]==refer[k]){
                     if(j==k) aa++;
                     else bb++; 
                 }
             }
         }
         if(!((aa==a)&&(bb==b))){  //把a值b值相等的答案保留下來 
             for(j=i;j<remain;j++){  //開始搬運 
                 for(k=0;k<4;k++){
                     answerBase[j][k]=answerBase[j+1][k];
                 }
             }
             remain--;
             i--;
         }
     }
     if(remain==0){  //發現沒有答案符合玩家想的數字，就是玩家作弊！
        printf("你作弊！= =+\n");
        isOver=1;
     }
}
/****** 選單之函數 ******/
void menu(void){
    char input[500];
    int right = 0;
    do{
        printf("是否重新？y/n");
        fgets(input,sizeof(input),stdin);
        *(input+strlen(input)-1)='\0';
        if(strlen(input)==1 && (*input == 'y' || *input == 'Y')){
            printf("\n------------------\n"); 
            restart = 1;
            right = 1;
        }else if(strlen(input)==1 && (*input == 'n' || *input == 'N')){
            printf("遊戲結束，拜拜～～");
            restart = 0;
            right = 1; 
        }else printf("輸入錯誤\n\n");
    }while(!right);    
}
/****** 介紹函數 ******/
void intro(void){
    printf("***************************************************\n");
    printf("***************************************************\n");
    printf("**                                               **\n");
    printf("**  猜數字遊戲(猜人)                               **\n");
    printf("**                                              **\n");
    printf("**  遊戲規則：                                    **\n");
    printf("**  1.每回合會猜一個四位數字                        **\n");
    printf("**  2.A的次數代表猜對了幾個數字且位置正確             **\n");
    printf("**  3.B的次數代表猜對了幾個數字但位置不對             **\n");
    printf("**  4.你必須告訴A和B的值                           **\n");
    printf("**  5.七回合內必可猜出答案                          **\n");
    printf("**  6.Enjoy！                                    **\n");
    printf("**                                               **\n");
    printf("***************************************************\n");
    printf("***************************************************\n");
}