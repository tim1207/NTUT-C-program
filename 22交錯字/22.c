#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STR_N 300


int isCapital(char c){
    if(c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int main(){
    int k;
    scanf("%d", &k);
    while (getchar()!='\n');
    char s[STR_N] = "";
    fgets(s, STR_N, stdin);
    int max = 0;
    int cur = 0;
    int streak = 0;
    int capFlag = isCapital(s[0]);
    int length = strlen(s);
    
    for(int i=0; i<length; i++){
        if(isCapital(s[i])==capFlag){
            streak++;
        } 
        else if(streak == k){
            capFlag = !capFlag;
            streak = 1;
        } 
        else if(streak < k){
            capFlag = !capFlag;
            streak = 1;
            cur = 0;
        }
        if(streak == k){
            cur += k;
            if(cur>max)
                max=cur;
        } 
        else if (streak > k){
            if(i+1 < length && isCapital(s[i+1]) != capFlag){
                cur = k;
                streak = k;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}





// 一個字串如果全由大寫英文字母組成，我們稱為大寫字串；如果全由小寫字母組成則稱為小寫字串。字串的長度是它所包含字母的個數，在本題中，字串均由大小寫英文字母組成。假設k是一個自然數，一個字串被稱為「k-交錯字串」，如果它是由長度為k的大寫字串與長度為k的小寫字串交錯串接組成。 
// 舉例來說，「StRiNg」是一個 1 -交錯字串,因為它是一個大寫一個小寫交替出現；而「heLLow」是一個 2 -交錯字串，因為它是兩個小寫接兩個大寫再接兩個小寫。但不管k是多少，「aBBaaa」、「BaBaBB」、「aaaAAbbCCCC」都不是k-交錯字串。本題的目標是對於給定k值，在一個輸入字串找出最長一段連續子字串滿足k-交錯字串的要求。例如k=2且輸入「aBBaaa」，最長的k-交錯字串是「BBaa」，長度為4。又如k=1且輸入「BaBaBB」，最長的k-交錯字串是「BaBaB」，長度為5。 
// 請注意，滿足條件的子字串可能只包含一段小寫或大寫字母而無交替，也可能不存在滿足條件的子字串。 
// ---------------------------------------------------------------------------------- 
// 輸入說明 
// 第一行為 k 
// 第二行為一字串 
// ------------------------------------------------- 
// 輸出說明 
// 輸出在輸入字串中最長的一段連續子字串有滿足k-交錯字串之字串長度 
// ---------------------------------------------------------------------------------- 
// sample input : 
// 1 
// aBBdaaa 

// sample output : 
// 2 
// ---------------------- 
// sample input : 
// 3 
// DDaasAAbbCC 

// sample output : 
// 3 
// ---------------------- 
// sample input : 
// 2 
// aafAXbbCDCCC 

// sample output : 
// 8 
// ---------------------- 
// sample input : 
// 3 
// DDaaAAbbCC 

// sample output : 
// 0