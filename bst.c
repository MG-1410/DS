#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root= NULL;

void insert (int data)
{
	struct node *t,*p;
	t= (struct node *)malloc (sizeof(struct node));
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	p=root;
	if(root == NULL)
	{
		root=t;
	}
	else
	{
		struct node *current;
		current=root;
		while(current)
		{
			p=current;
			if(t->data > current->data)
			{
				current=current->right;
			}
			else
			{
				current=current->left;
			}
		}
		if(t->data > p->data)
		{
			p->right=t;
		}
		else
		{
			p->left=t;
		}
	}
}

 void inorder(struct node *t)
{
	if(t == NULL){
		return;
	}
	inorder(t->left);
	printf("%d ",t->data);
	inorder(t->right);
}	

void preorder(struct node *t)
{
	if(t == NULL){
		return;
	}
	printf("%d ",t->data);
	preorder(t->left);
	preorder(t->right);
}

void postorder(struct node *t)
{
	if(t == NULL){
		return;
	}
	postorder(t->left);
	postorder(t->right);
	printf("%d ",t->data);
 }

int main()
{
	insert(100);
	insert(200);
	insert(150);
	insert(20);
	insert(300);
	insert(30);
	insert(10);
	printf("Inorder traversal: ");
	inorder(root);
	printf("\nPreorder traversal: ");
	preorder(root);
	printf("\nPostorder traversal: ");
	postorder(root);
	return 0;
}
