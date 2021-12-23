#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *link;
};

struct node* add(struct node *ptr , int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}

struct node* add_at_beg(struct node *head,int data)
{
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    temp->link=head;
    head=temp;
    return head;
};
int main()
{
    struct node *head= (struct node *)malloc(sizeof(struct node));
    head->i=14;
    head->link=NULL;
    struct node  *ptr=head;
    ptr=add(ptr,28);
    ptr=add(ptr,42);
    ptr=add(ptr,90);
    head=add_at_beg(head,10);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
}
