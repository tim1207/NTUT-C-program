#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _term {
    int coefficient;
    int exp;
    struct _term *next;
} term;


void createTerm(term *term) {
    term->coefficient = 0;
    term->exp = -1;
    term->next = NULL;
}

term* readTerms() {
    char input[1000], *terms[500];
    fgets(input, 100, stdin);
    if(input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    if(input[strlen(input)-1] == ' ') {
        input[strlen(input)-1] = '\0';
    }
    char *temp = strtok(input, " ");
    int i=0;
    while(temp != NULL) {
        terms[i] = temp;
        temp = strtok(NULL, " ");
        i++;
    }
    int termCount = i;
    term *cur = (term *) malloc(sizeof(term));
    createTerm(cur);
    cur->exp = termCount-1;
    cur->coefficient = atoi(terms[0]);
    term *head = cur;
    for(int i=1; i<termCount; i++) {
        term *nextTerm = (term *) malloc(sizeof(term));
        createTerm(nextTerm);
        nextTerm->coefficient = atoi(terms[i]);
        nextTerm->exp = (termCount - 1) - i;
        cur->next = nextTerm;
        cur = cur->next;
    }
    return head;
}

void freeList(term *head) {
    term *cur = head->next;
    term *prev = head;
    while(cur) {
        free(prev);
        prev = cur;
        cur = cur->next;
    }
    free(prev);
}

void printTerms(term* num) {
    while(num->coefficient == 0 && num->exp > 0) {
        num = num->next;
    }
    while(num) {
        printf("%d ", num->coefficient);
        num = num->next;
    }
    printf("\n");
}

term* addTerms(term* lhs, term* rhs) {
    term *head = (term *) malloc(sizeof(term));
    createTerm(head);
    term *cur = head;
    //紀錄最高向次方
    if(lhs->exp>rhs->exp) {
        head->exp = lhs->exp;
    } else {
        head->exp = rhs->exp;
    }
    // 取第一位出來
    if(lhs && cur->exp == lhs->exp) {
        cur->coefficient += lhs->coefficient;
        lhs = lhs->next;
    }
    if(rhs && cur->exp == rhs->exp) {
        cur->coefficient += rhs->coefficient;
        rhs = rhs->next;
    }
    while(lhs || rhs) {
        term *nextTerm = (term *) malloc(sizeof(term));
        createTerm(nextTerm);
        nextTerm->exp = cur->exp - 1;
        cur->next = nextTerm;
        cur = nextTerm;
        if (lhs && cur->exp == lhs->exp) {
            cur->coefficient += lhs->coefficient;
            lhs = lhs->next;
        }
        if (rhs && cur->exp == rhs->exp) {
            cur->coefficient += rhs->coefficient;
            rhs = rhs->next;
        }
    }
    return head;
}
term* substractTerms(term* lhs, term* rhs) {
    term *head = (term *) malloc(sizeof(term));
    createTerm(head);
    term *cur = head;
    if(lhs->exp>rhs->exp) {
        head->exp = lhs->exp;
    } else {
        head->exp = rhs->exp;
    }
    
    if(lhs && cur->exp == lhs->exp) {
        cur->coefficient += lhs->coefficient;
        lhs = lhs->next;
    }
    if(rhs && cur->exp == rhs->exp) {
        cur->coefficient -= rhs->coefficient;
        rhs = rhs->next;
    }
    while(lhs || rhs) {
        term *nextTerm = (term *) malloc(sizeof(term));
        createTerm(nextTerm);
        nextTerm->exp = cur->exp - 1;
        cur->next = nextTerm;
        cur = nextTerm;
        if (lhs && cur->exp == lhs->exp) {
            cur->coefficient += lhs->coefficient;
            lhs = lhs->next;
        }
        if (rhs && cur->exp == rhs->exp) {
            cur->coefficient -= rhs->coefficient;
            rhs = rhs->next;
        }
    }
    return head;
}

term* multiplyTerms(term *lhs, term *rhs) {
    term *result = (term *) malloc(sizeof(term));
    createTerm(result);
    result->exp = 0;
    while(rhs) {
        term *temp = (term *) malloc(sizeof(term));
        term *cur = temp;
        term *lhsPtr = lhs;
        cur->exp = lhsPtr->exp + rhs->exp;
        cur->coefficient = lhsPtr->coefficient * rhs->coefficient;
        lhsPtr = lhsPtr->next;
        while (lhsPtr) {
            term *nextTerm = (term *) malloc(sizeof(term));
            createTerm(nextTerm);
            nextTerm->exp = lhsPtr->exp + rhs->exp;
            nextTerm->coefficient = lhsPtr->coefficient * rhs->coefficient;
            cur->next = nextTerm;
            cur = cur->next;
            lhsPtr = lhsPtr->next;
        }
        result = addTerms(result, temp);
        freeList(temp);
        rhs = rhs->next;
    }
    return result;
}

int main() {
    term *num1 = readTerms();
    term *num2 = readTerms();
    printTerms(addTerms(num1, num2));
    printTerms(substractTerms(num1, num2));
    printTerms(multiplyTerms(num1, num2));
}



/*
***本題務必使用 Link List***

輸入兩個多項式，輸出相加、相減、相乘的結果。例如:

2x^4 + 3x^3 + x -1
x^5 - x^3 + 4x^2 - 3x +2
結果：
x^5 + 2x^4 + 2x^3 + 4x^2 - 2x + 1
-x^5 + 2x^4 + 4x^3 - 4x^2 + 4x - 3
2x^9 + 3x^8 - 2x^7 + 6x^6 + 5x^5 - 6x^4 + 11x^3 - 7x^2 + 5x - 2

輸入說明
輸入兩筆資料，分別代表兩個多項數。
每一筆輸入 n 個整數，第一個代表 n-1次方的係數，第 n 個代表 0 次方係數。

輸出說明
兩個多項式計算後從最高次方到0次方的係數，計算結果為0的係數也需印出。


Sample Input
2 3 0 1 -1
1 0 -1 4 -3 2

Sample Output
1 2 2 4 -2 1
-1 2 4 -4 4 -3
2 3 -2 6 5 -6 11 -7 5 -2
*/
