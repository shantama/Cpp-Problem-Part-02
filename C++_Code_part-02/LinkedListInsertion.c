#include<stdio.h>
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
        printf(" Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
//case:1 insertion at beginning
struct node * InsertionAtBegin(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
//case:2 insertion in between
struct node *insertAtindex(struct node*head,int data,int index)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(i !=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
//case:3 insertion at end
struct node * InsertionAtEnd(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
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
    printf("Linked list:\n");
    LinkedListTraversal(head);
    head=InsertionAtBegin(head,5);
    printf("\nInsertion at beginning list:\n");
    LinkedListTraversal(head);
    head=insertAtindex(head,56,2);
    printf("\ninsertion between to node list:\n");
    LinkedListTraversal(head);
    head=InsertionAtEnd(head,67);
    printf("\ninsertion at end list:\n");
    LinkedListTraversal(head);

    return 0;
}

