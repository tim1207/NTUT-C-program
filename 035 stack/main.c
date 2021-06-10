#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct linklist{
    char name[50];
    int age;
    int year;
    int month;
    int day;
    struct linklist *prev;
}typedef LinkList;
LinkList *root;
void func1(){
    char first[25],last[25];
    
    LinkList *temp=calloc(1,sizeof(LinkList));
    scanf(" \"%[^\n\"]\" %d %d %d %d",&temp->name,&temp->age,&temp->year,&temp->month,&temp->day);
    //last[strlen(last) - 1]='\0';
    //sprintf(temp->name,"%s %s",first,last);
    if(root == NULL){
        root = temp; 
    }else{
        temp->prev = root;
        root = temp;
    }

}
void func2(){
    int target =0;
    scanf(" %d",&target);
    if(root == NULL){
        printf("The Stack is empty\n");        
    }
    else{
        if(target==1){
            printf("%s\n",root->name);
        }else if(target ==2){
            printf("%d\n",root->age);
        }else if(target ==3){
            printf("%d_%d_%d\n",root->year,root->month,root->day);
        }
        root = root->prev;
    }
    
    
}

int main(){
    root = NULL;
    while (1)
    {
        int func = 0;
        scanf("%d",&func);
        if(func==1){
            func1();
            //printf("%s %d %d %d %d\n",root->name,root->age,root->year,root->month,root->day);
        }else if(func==2)
        {
            func2();
        }
        else if(func==3)
            break;
    }
    
}