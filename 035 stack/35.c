#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _data{
    char name[50];
    int age;
    int year;
    int month;
    int day;
    struct _data *next;
} data;

void push(data **head, data *data) {
    data->next = *head;
    *head = data;
}

data* pop(data **head) {
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
    input = (char *) malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';
    if(input[strlen(input)-1] == ' ')
        input[strlen(input)-1] = '\0';
    while (input[0] != '"')
        input++;
    strcpy(newData->name, strtok(input, "\""));
    input = strtok(NULL, "\"");
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
                push(&head, d);
                break;
            }
            case 2:{
                data *d = pop(&head);
                int input;
                scanf("%d", &input);
                char c = getchar();
                while(c != EOF && c != '\n')
                    c = getchar();
                if (!d) {
                    printf("The Stack is empty\n");
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
***此題務必使用 Link List*** 

實作stack 
在一端進行後進先出（LIFO, Last In First Out）的原理運作。 
兩種基本操作：push 和 pop 
push：將數據放入堆疊的頂端（串列形式），堆疊頂端top指標加一。 
pop：將頂端數據資料輸出（回傳），堆疊頂端top指標減一。 

每一次push和pop的一筆資料都包含姓名、年齡、生日(年、月、日) 

輸入說明: 
1 代表 push，再依序輸入姓名、年齡、生日(年、月、日)，參數之間以空白相隔 
2 代表 pop，再輸入一個數字，進行不同的操作，操作數字如下: 
1:印出該次pop的資料中的姓名 
2:印出該次pop的資料中的年齡 
3:印出該次pop的資料中的生日(年、月、日之間以底線連結) 
若stack中為空則印出 The Stack is empty\n 
3 結束程式。 

Sample Input 

1 "Marry Hu" 19 1989 7 16 
1 "Tom Chen" 22 1996 10 19 
2 1 
1 "Billy Wu" 15 2005 3 18 
2 3 
2 2 
1 "Lucas Su" 24 1993 5 21 
2 3 
2 1 
3 

Sample Output 

Tom Chen 
2005_3_18 
19 
1993_5_21 
The Stack is empty 

*/