#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX 1000

typedef struct number{
    int sign;
    int *integer;
    int *fraction;
} num;

void leftShift(int *arr, int size, int n) {
    for(int i=size-1; i>=0; i--){
        arr[i+n] = arr[i];
    }
    for (int i=0; i<n; i++) {
        arr[i] = 0;
    }
}

void print(int *result, int n){
    int flag = 1;
    for (int i=n; i>=0; i--) {
        if (flag) {
            if (*(result+i)) {
                flag = 0;
                printf("%d", *(result+i));
            }
            continue;
        }
        printf("%d", *(result+i));
    }
    if(flag)
        printf("0");
}

void printFrac(int *result, int size, int n){
    int index = -1;
    int flag = 0;
    n = n < size ? n : size;
    for (int i=size-1; i>=size-n; i--) {
        if (result[i] != 0) {
            flag = 1;
            printf(".");
            break;
        }
    }
    if (!flag) {
        return;
    }
    for (int i=size-n; i<size; i++) {
        if (result[i] != 0){
            index = i;
            break;
        }
    }
    for (int i=size-1; i>=index; i--) {
        printf("%d", *(result+i));
    }
}

int* add(int *num1, int size1, int *num2, int size2){
    int *result = (int *)malloc(MAX*2 * sizeof(int));
    for (int i=0; i<size1; i++) {
        *(result+i) = *(num1+i);
    }
    for (int i=size1; i<MAX*2; i++) {
        *(result+i) = 0;
    }
    for (int i=0; i<size2; i++) {
        *(result+i) += *(num2+i);
        if (*(result+i)>9) {
            *(result+i+1) += *(result+i)/10;
            *(result+i) %= 10;
        }
    }
    return result;
}

int compare(int *num1, int size1, int *num2, int size2){
    if (size1>size2)
        return 1;
    if (size1<size2)
        return -1;
    for(int i=size1-1; i>=0; i--){
        if (*(num1+i) > *(num2+i))
            return 1;
        if (*(num1+i) < *(num2+i))
            return -1;
    }
    return 0;
    
}
int comparef(int *num1, int size1, int *num2, int size2){
    for(int i=size1, j=size2; i>=0 && j>=0; i--,j--){
        if (*(num1+i) > *(num2+j))
            return 1;
        if (*(num1+i) < *(num2+j))
            return -1;
    }
    if (size1 > size2) {
        return 1;
    }
    if (size1 < size2) {
        return -1;
    }
    return 0;
}
int* sub(int *num1, int size1, int *num2, int size2, int* sign){
    *sign = 0;
    if (compare(num1, size1, num2, size2)<0) {
        *sign = 1;
        int *temp = num1;
        num1 = num2;
        num2 = temp;
        int tmp = size1;
        size1 = size2;
        size2 = tmp;
    }
    int *result = calloc(MAX, sizeof(int));
    for (int i=0; i<size1; i++) {
        result[i] = *(num1+i);
    }
    for (int i=size1; i<MAX; i++) {
        result[i] = 0;
    }
    for (int i=0; i<size2; i++) {
        result[i] -= *(num2+i);
        if (result[i]<0) {
            result[i+1] -= 1;
            result[i] += 10;
        }
    }
    for (int i=size2; i<size1; i++) {
        if (result[i]<0) {
            result[i+1] -= 1;
            result[i] += 10;
        }
    }
    return result;
}

int* mul(int *num1, int size1, int *num2, int size2){
    int *result = (int*)malloc(sizeof(int)*MAX*4);
    int temp[size1+size2];
    for (int i=0; i<MAX*4; i++)
        *(result+i) = 0;
    for (int i=0; i<size2; i++) {
        for (int k=0; k<size1+size2; k++)
            temp[k] = 0;
        for (int j=0; j<size1; j++) {
            temp[i+j] += *(num1+j) * *(num2+i);
            temp[i+j+1] += temp[i+j] / 10;
            temp[i+j] %= 10;
        }
        result = add(result, MAX*4, temp, size1+size2);
    }
    return result;
}

int main(){
    num num1, num2, result;
    num1.sign = 0;
    num2.sign = 0;
    result.sign = 0;
    int n;
    
    //initialize
    num1.integer = calloc(MAX, sizeof(int));
    num2.integer = calloc(MAX, sizeof(int));
    result.integer = calloc(MAX*2, sizeof(int));
    num1.fraction = calloc(MAX, sizeof(int));
    num2.fraction = calloc(MAX, sizeof(int));
    result.fraction = calloc(MAX*2, sizeof(int));
    memset(num1.integer, 0, sizeof(num1.integer));
    memset(num1.fraction, 0, sizeof(num1.integer));
    memset(num2.integer, 0, sizeof(num1.integer));
    memset(num2.fraction, 0, sizeof(num1.integer));
    memset(result.integer, 0, sizeof(result.integer));
    memset(result.fraction, 0, sizeof(result.fraction));
    int size1_i, size2_i;
    int size1_f = 0;
    int size2_f = 0;
    char *input = (char*)malloc(sizeof(char)*MAX*2+1);
    fgets(input, MAX*2+1, stdin);
    if (input[strlen(input)-1] == '\n'){
        input[strlen(input)-1] = '\0';
    }
    if (input[0] == '-') {
        num1.sign = 1;
        input = (input + 1);
    }
    int size1 = (int)strlen(input);
    
    size1_i = size1;
    int j = 120;
    for (int i=0; i<size1; i++) {
        if (input[i] == '.') {
            size1_i = i;
            size1_f = size1 - i - 1;
            j = i + 1;
            break;
        }
    }
    for (int i=size1_i-1; i>=0; i--) {
            num1.integer[size1_i - 1 - i] = input[i] - '0';
    }
    for (int i=j; i<size1; i++) {
        num1.fraction[i - j] = input[size1 - (i-j) - 1] - '0';
    }

    
    fgets(input, MAX*2+1, stdin);
    if (input[strlen(input)-1] == '\n'){
        input[strlen(input)-1] = '\0';
    }
    if (input[0] == '-') {
        num2.sign = 1;
        input = (input + 1);
    }
    int size2 = (int)strlen(input);

    size2_i = size2;
    j = 120;
    for (int i=0; i<size2; i++) {
        if (input[i] == '.') {
            size2_i = i;
            size2_f = size2 - i - 1;
            j = i + 1;
            break;
        }
    }
    for (int i=size2_i-1; i>=0; i--) {
            num2.integer[size2_i - 1 - i] = input[i] - '0';
    }
    for (int i=j; i<size2; i++) {
            num2.fraction[i - j] = input[size2 - (i-j) - 1] - '0';
    }
    scanf("%d", &n);
    int temp[1] = {0};
        
    //addition
    if ((!num1.sign && !num2.sign)||(num1.sign && num2.sign)) {
        int swapSign = 0;
        if (num1.sign)
            swapSign = 1;

        if(size1_f>size2_f){
            leftShift(num2.fraction, size2_f, size1_f - size2_f);
            size2_f = size1_f;
        } else {
            leftShift(num1.fraction, size1_f, size2_f - size1_f);
            size1_f = size2_f;
        }
        result.fraction = add(num1.fraction, size1_f, num2.fraction, size2_f);
        if (result.fraction[size1_f] == 1) {
            temp[0] = 1;
            result.fraction[size1_f] = 0;
        }
        if (swapSign)
        printf("-");
        result.integer = add(num1.integer, size1_i, num2.integer, size2_i);
        result.integer = add(result.integer, MAX, temp, 1);
        print(result.integer, MAX - 1);
        printFrac(result.fraction, size1_f, n);
        printf("\n");
    } else if ((!num1.sign && num2.sign) || (num1.sign && !num2.sign)) {
        int swapSign = 0;
        if (num1.sign)
            swapSign = 1;
        
        int subSign = 0;
        int lhsIsSmaller = 0;
        temp[0] = 0;
        if(size1_f>size2_f){
            leftShift(num2.fraction, size2_f, size1_f - size2_f);
            size2_f = size1_f;
        } else {
            leftShift(num1.fraction, size1_f, size2_f - size1_f);
            size1_f = size2_f;
        }
        int comp = compare(num1.integer, size1_i, num2.integer, size2_i);
        int compf = comparef(num1.fraction, size1_f, num2.fraction, size2_f);
        if (comp == -1 || (comp == 0 && compf<0)) {
            lhsIsSmaller = 1;
        }
        
        if (compf<0 && !lhsIsSmaller) {
            num1.fraction[size1_f+1] = 1;
            result.fraction = sub(num1.fraction, size1_f+1, num2.fraction, size2_f, &subSign);
            temp[0] = 1;
        } else if (compf>0 && lhsIsSmaller){
            num2.fraction[size2_f+1] = 1;
            result.fraction = sub(num2.fraction, size2_f+1, num1.fraction, size1_f, &subSign);
            temp[0] = 1;
        } else if (!lhsIsSmaller) {
            result.fraction = sub(num1.fraction, size1_f, num2.fraction, size2_f, &subSign);
        } else {
            result.fraction = sub(num2.fraction, size2_f, num1.fraction, size1_f, &subSign);
        }
        
        if (!lhsIsSmaller) {
            result.integer = sub(num1.integer, size1_i, num2.integer, size2_i, &subSign);
        } else {
            result.integer = sub(num2.integer, size2_i, num1.integer, size1_i, &subSign);
        }
        
        result.integer = sub(result.integer, MAX, temp, 1, &subSign);

        if (lhsIsSmaller != swapSign) {
            printf("-");
        }
        print(result.integer, size1_i+1);
        printFrac(result.fraction, size1_f, n);
        printf("\n");
    }
    //substraction
    memset(result.integer, 0, sizeof(num1.integer));
    memset(result.fraction, 0, sizeof(num1.integer));
    if ((!num1.sign && !num2.sign) ||(num1.sign && num2.sign)) {
        int swapSign = 0;
        if (num1.sign){
            swapSign = 1;
            num1.sign = 0;
            num2.sign = 0;
        }
        int subSign = 0;
        int lhsIsSmaller = 0;
        temp[0] = 0;
        if(size1_f>size2_f){
            leftShift(num2.fraction, size2_f, size1_f - size2_f);
            size2_f = size1_f;
        } else {
            leftShift(num1.fraction, size1_f, size2_f - size1_f);
            size1_f = size2_f;
        }
        int comp = compare(num1.integer, size1_i, num2.integer, size2_i);
        int compf = comparef(num1.fraction, size1_f, num2.fraction, size2_f);
        if (comp == -1 || (comp == 0 && compf<0)) {
            lhsIsSmaller = 1;
        }
        
        if (compf<0 && !lhsIsSmaller) {
            num1.fraction[size1_f+1] = 1;
            result.fraction = sub(num1.fraction, size1_f+1, num2.fraction, size2_f, &subSign);
            temp[0] = 1;
        } else if (compf>0 && lhsIsSmaller){
            num2.fraction[size2_f+1] = 1;
            result.fraction = sub(num2.fraction, size2_f+1, num1.fraction, size1_f, &subSign);
            temp[0] = 1;
        } else if (!lhsIsSmaller) {
            result.fraction = sub(num1.fraction, size1_f, num2.fraction, size2_f, &subSign);
        } else {
            result.fraction = sub(num2.fraction, size2_f, num1.fraction, size1_f, &subSign);
        }
        
        if (!lhsIsSmaller) {
            result.integer = sub(num1.integer, size1_i, num2.integer, size2_i, &subSign);
        } else {
            result.integer = sub(num2.integer, size2_i, num1.integer, size1_i, &subSign);
        }
        
        result.integer = sub(result.integer, MAX, temp, 1, &subSign);

        if (lhsIsSmaller) {
            printf("-");
        }
        if (swapSign) {
            num1.sign = 1;
            num2.sign = 1;
        }
        print(result.integer, MAX - 1);
        printFrac(result.fraction, size1_f, n);
        printf("\n");
    } else if ((num1.sign && !num2.sign) || (!num1.sign && num2.sign)) {
        int swapSign = 0;
            if (num1.sign){
                swapSign = 1;
                num1.sign = 0;
                num2.sign = 1;
            }
           if(size1_f>size2_f){
                leftShift(num2.fraction, size2_f, size1_f - size2_f);
                size2_f = size1_f;
            } else {
                leftShift(num1.fraction, size1_f, size2_f - size1_f);
                size1_f = size2_f;
            }
            result.fraction = add(num1.fraction, size1_f, num2.fraction, size2_f);
            if (result.fraction[size1_f] == 1) {
                temp[0] = 1;
                result.fraction[size1_f] = 0;
            }
            if (swapSign)
                printf("-");
            result.integer = add(num1.integer, size1_i, num2.integer, size2_i);
            result.integer = add(result.integer, MAX, temp, 1);
            print(result.integer, MAX);
            printFrac(result.fraction, size1_f, n);
            printf("\n");
            if (swapSign) {
                num1.sign = 1;
                num2.sign = 0;
            }
        }

    //multiply
    memset(result.integer, 0, MAX * 2 * sizeof(*result.integer));
    memset(result.fraction, 0, MAX * 2 * sizeof(*result.fraction));
    if (num1.sign != num2.sign) { // sign_1 xor sign_2
        printf("-");
    }
    int *tempNum1 = calloc(MAX*4, sizeof(int));
    int *tempNum2 = calloc(MAX*4, sizeof(int));
    for (int i=0; i<size1_f; i++) {
        tempNum1[i] = num1.fraction[i];
    }
    for (int i=0; i<size1_i; i++) {
        tempNum1[size1_f + i] = num1.integer[i];
    }
    for (int i=0; i<size2_f; i++) {
        tempNum2[i] = num2.fraction[i];
    }
    for (int i=0; i<size2_i; i++) {
        tempNum2[size2_f + i] = num2.integer[i];
    }
    
    int *tempResult = mul(tempNum1, size1_i + size1_f, tempNum2, size2_i + size2_f);
    for (int i=0; i<size1_f + size2_f; i++) {
        result.fraction[i] = tempResult[i];
    }
    for (int i=0; i<size1_i + size2_i; i++) {
        result.integer[i] = tempResult[size1_f + size2_f + i];
    }
    print(result.integer, size1_i + size2_i - 1);
    printFrac(result.fraction, size1_f + size2_f, n);
    printf("\n");
    return 0;
}
