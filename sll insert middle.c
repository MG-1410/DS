#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *link;
};

struct node* add_at_end(struct node *ptr , int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}

struct node* add_at_pos(struct node *head,int data,int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    struct node *ptr=head;
    while(pos != 2)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
};
int main()
{
    struct node *head= (struct node *)malloc(sizeof(struct node));
    head->i=14;
    head->link=NULL;
    struct node  *ptr=head;
    ptr=add_at_end(ptr,28);
    ptr=add_at_end(ptr,42);
    ptr=add_at_end(ptr,90);
    add_at_pos(head,10,3);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
}
