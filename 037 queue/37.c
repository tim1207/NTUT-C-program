#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _data{
    char name[100];
    int age;
    int year;
    int month;
    int day;
    struct _data *next;
} data;

void enqueue(data **head, data *d) {
    if (!*head) {
        *head = d;
    } else {
        data *prev = *head;
        data *cur = (*head)->next;
        while (cur) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = d;
    }
    
}

data* dequeue(data **head) {
    if (!*head) {
        return NULL;
    }
    data *result = *head;
    *head = (*head)->next;
    result->next = NULL;
    return result;
}

data* readData() {
    data *newData = (data *) malloc(sizeof(data));
    char *input;
    input = (char *) malloc(1000 * sizeof(char));
    fgets(input, 1000, stdin);
    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';
    if(input[strlen(input)-1] == ' ')
        input[strlen(input)-1] = '\0';
    while (input[0] != '"')
        input++;
    strcpy(newData->name, strtok(input, "“\""));
    input = strtok(NULL, "“\"");
    sscanf(input, "%d%d%d%d", &newData->age, &newData->year, &newData->month, &newData->day);
    newData->next = NULL;
    return newData;
}

int main(){
    int flag = 1;
    data *head = NULL;
    while (flag) {
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1:{
                data *d = readData();
                enqueue(&head, d);
                break;
            }
            case 2:{
                data *d = dequeue(&head);
                int input;
                scanf("%d", &input);
                char c = getchar();
                while(c != EOF && c != '\n')
                    c = getchar();
                if (!d) {
                    printf("The Queue is empty\n");
                    break;
                }
                switch (input) {
                    case 1:
                        puts(d->name);
                        break;
                    case 2:
                        printf("%d\n", d->age);
                        break;
                    case 3:
                        printf("%d_%d_%d\n", d->year, d->month, d->day);
                        break;
                    default:
                        break;
                }
                break;
            }
            case 3:
                flag = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}



/*
使用 Link List 實作queue 

在一端進行先進先出（FIFO, First In First Out）的原理運作。 
兩種基本操作：enqueue 和 dequeue， 

enqueue:將資料放入佇列的尾端（串列形式），佇列尾端tail指標加一。 
pop：將頂端數據資料輸出（回傳），佇列頂端top指標減一。 
每一次push和pop的一筆資料都包含姓名、年齡、生日(年、月、日) 

輸入說明: 
1 代表 euqueue，再依序輸入姓名、年齡、生日(年、月、日)，參數之間以空白相隔 
2 代表 dequeue，再輸入一個數字，進行不同的操作，操作數字如下: 
3 結束程式 

dequeue後的數字: 
1:印出該次dequeue的資料中的姓名 
2:印出該次dequeue的資料中的年齡 
3:印出該次dequeue的資料中的生日(年、月、日之間以底線連結) 
若queue中為空則印出 The Queue is empty 

範例一: 
Input: 
1 "Marry Hu" 19 1989 7 16 
1 "Tom Chen" 22 1996 10 19 
2 1 
1 "Billy Wu" 15 2005 3 18 
2 3 
2 2 
1 "Seafood" 24 1993 5 21 
2 3 
2 1 
3 

Output: 
Marry Hu 
1996_10_19 
15 
1993_5_21 
The Queue is empty 

範例二: 
Input: 
1 "Tome Hu" 19 1989 7 16 
2 3 
2 1 
1 "Mike Lee" 25 1995 10 9 
2 2 
2 3 
3 

Output: 
1989_7_16 
The Queue is empty 
25 
The Queue is empty

*/
