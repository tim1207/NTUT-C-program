#include <stdio.h>
void check_AB(char x[], char y[], int *A, int *B){
    
    *A=0;
    *B=0;
    for( int i = 0; i < 4; i++ ) {
           
        for( int j = 0; j < 4; j++ ){
            if( y[i] == x[j] ) 
            {
                if(i==j)
                    (*A)++;
                else
                    (*B)++;
            }
                    
        }
    }
    //printf("%d,%d\n",*A,*B);
}
int check(char data[]){
    int flag=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=j && data[i]==data[j])
                return 0;
        }
    }
    return 1;
}
    

int main(){
    char ans[5];
    int check_ans=0;
    while(check_ans==0){
        gets(ans);
        check_ans=check(ans);
    }
    
    //printf("%s\n",ans);
    int win=0;
    int count=0;
    int a=0,b=0;
    while(win!=1 && count<7){
        
        char guess[5];
        
        int check_guess=0;
        while(check_guess==0){
            gets(guess);
            check_guess=check(guess);
        }
        count++;
        if(count==7) break;
        //printf("%s\n",guess);
        check_AB(ans,guess,&a,&b);
        if(a==4) {
            printf("win\n");
            win=1;
        }
        else{
            if(count>0){
                printf("%dA%dB\n",a,b);
            }
            //printf("%d\n",count);
        }
    }
    return 0;
}

// 014 1A2B 

// 小明和小萱在玩猜數字遊戲， 
// 由小明先輸入四個數字為謎底， 
// 小萱輸入想要猜的四個數字。 
// 若猜中數字則顯示win 
// 若猜錯則顯示XAYB（X表示位置和數字皆正確的個數，而Y表示數字正確而位置不對的個數） 
// ＊＊＊最多猜六次＊＊＊ 


// sample input1: 
// 1234 
// 5678 
// 1234 

// sample output1: 
// 0A0B 
// win 


// ------------------ 

// sample input2: 
// 0487 
// 0234
// 1498 
// 2378 
// 3294 
// 3681 
// 5412 

// sample output2: 
// 1A1B 
// 1A1B 
// 0A2B 
// 0A1B 
// 1A0B 
// 1A0B

