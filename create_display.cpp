#include<bits/stdc++.h>
#include<iostream>
#define NULL 0
using namespace std;

struct linked_list
{
    int number;
    struct linked_list *next;
};
typedef struct linked_list node;

int main()
{
   
    node *head;
    head = (node*)malloc(sizeof(node));
    void create(node *p);
    void print(node *p);
    int count(node *p);
    create(head);
    printf("\n");
    print(head);
    printf("\nNumber of items = %d\n", count(head));
    return 0;
}
void create(node *list){
    printf("Input a number\n");
    printf("(type 0 at end):\n");
    scanf("%d", &list->number);

    if(list->number==0)
    {
        list->next = NULL;
    }
    else{
        list->next = (node*)malloc(sizeof(node));
        create(list->next);
    }
}
void print(node *list){
    if(list->next != NULL){
        printf("%d-->",list->number);
        if(list->next->next == NULL)
            printf("%d",list->next->number);
        print(list->next);
    } return;
}
int count(node *list){
    if(list->next == NULL)
        return (0);
    else 
        return (1+count(list->next));
}