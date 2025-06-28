include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void LinkedListTraversal(struct node *ptr)
{
    while(ptr !=NULL)
    {
        printf(" Element: %d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=23;
    third->next=fourth;

    fourth->data=2;
    fourth->next=NULL;

    LinkestListTraversal(head);
    return 0;
}
