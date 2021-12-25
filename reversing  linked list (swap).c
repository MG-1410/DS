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

int length (struct node *head)
{
    struct node *ptr=head;
    int count=0;
    while(ptr != NULL)
    {
        ptr=ptr->link;
        count++;
    }
    return count;
}

void reverse(struct node *head)
{
    int i,j;
    struct  node *p,*q;
    int len=length(head);
    i=0,j=len-1;
    p=q=head;
    while(i<j)
    {
        int k=0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        int temp=p->i;
        p->i=q->i;
        q->i=temp;
        i++;
        j--;
        p=p->link;
        q=head;
    }
}

void print(struct node *head)
{
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
    printf("\n");
}

int main()
{
    struct node *head= (struct node *)malloc(sizeof(struct node));
    head->i=14;
    head->link=NULL;
    struct node  *ptr=head;
    ptr=add_at_end(ptr,28);
    ptr=add_at_end(ptr,42);
    ptr=add_at_end(ptr,90);

    printf("Before Reversing: ");
    print(head);
    reverse(head);
    printf("After Reversing: ");
    print(head);
}
