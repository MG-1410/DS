#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *link;
}*top=NULL;

void push (int data)
{
    struct node *temp=(struct node *)malloc (sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack overflow");
    }
    temp->i=data;
    temp->link=top;
    top=temp;
}

int pop()
{
    struct node *ptr=top;
    int a;
    ptr=ptr->link;
    a=top->i;
    free(top);
    top=ptr;
    return a;
}

int isEmpty()
{
    if(top ==NULL)
    {
        return 0;
    }
    return 1;
}

void print()
{
    struct node *ptr=top;
    printf("The elements are: ");
    while (ptr != NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
    printf("\n");
}

int main()
{
    int choice,n;
    while(1){
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Print\n");
    printf("4.Quit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("The elements to be pushed is: ");
        scanf("%d",&n);
        push(n);
        break;

    case 2:
        n=pop();
        printf("The deleted element is: %d",n);
        break;

    case 3:
        print();
        break;

    case 4:
        exit(1);

    default:
        printf("Invalid Command");
        break;
    }
    printf("\n\n");
    }
}
