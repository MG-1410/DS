#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *link;
};


int enqueue(struct node *head,struct node **tail,int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    head->link=temp;
    *tail=temp;
    return temp;
}

struct node* dequeue(struct node *head)
{
    struct node *ptr=head;
    ptr=ptr->link;
    free(head);
    head=ptr;
    return head;
};

void print(struct node *head)
{
    struct node *ptr=head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    struct node *tail=NULL;
    head->i=100;
    head->link=NULL;
    struct node *ptr=head;
    ptr=enqueue(ptr,&tail,5);
    ptr=enqueue(ptr,&tail,10);
    ptr=enqueue(ptr,&tail,15);
    ptr=enqueue(ptr,&tail,20);
    head=dequeue(head);
    head=dequeue(head);
    print(head);
}
