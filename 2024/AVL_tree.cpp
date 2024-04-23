/*

Data Structures Lab : Semester 2 - IIITG

*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node*left,*right;
	int height;
};

struct node* newnode(int key)
{
	struct node* node = (struct node*)calloc(1,sizeof(struct node));
	node->key = key;
	node->height = 1;
	return node;
}

int max(int a,int b)
{
	return a > b?a:b;
}

int findheight(struct node* root)
{
	if(root == NULL)
	return 0;
	int l = findheight(root->left);
	int r = findheight(root->right);
	
	return max(l,r)+1;
}

int isbalancedhelper(struct node* node,int *isbalanced)
{
	if(node == NULL)
	return 0;
	int l = isbalancedhelper(node->left,isbalanced);
	int r = isbalancedhelper(node->right,isbalanced);
	int balancefactor = l-r;
	if(balancefactor >1 || balancefactor < -1)
	{
		*isbalanced = 0;
	}
	return max(l,r)+1;
}

int isbalanced(struct node* node)
{
	int isbalanced = 1;
	 isbalancedhelper(node,&isbalanced);
	 return isbalanced;
}

int getheight(struct node* node)
{
	return node == NULL?0:node->height;
}

struct node* rotateright(struct node* node)
{
	printf("rotateright(%d)\n",node->key);
	struct node* x = node;
	struct node* y = node->left;
	struct node* t2 = y->right;
	y->right = x;
	x->left = t2;
	x->height = max(getheight(x->left),getheight(x->right))+1;
	y->height = max(getheight(y->left),getheight(y->right))+1;
	return y;
}

struct node* rotateleft(struct node* node)
{
	printf("rotateleft(%d)\n",node->key);
	struct node* x = node;
	struct node* y = node->right;
	struct node* t2 = y->left;
	y->left = x;
	x->right = t2;
	x->height = max(getheight(x->left),getheight(x->right))+1;
	y->height = max(getheight(y->left),getheight(y->right))+1;
	return y; 
}

struct node* insertionbst(struct node* node,int key)
{
	if(node == NULL)
	{
		return newnode(key);
	}
	if(key > node->key )
	{
		node->right = insertionbst(node->right,key);
	}
	else if(key < node->key )
	{
		node->left = insertionbst(node->left,key);
	}
	else
	{
		printf("duplicate element : ");
		return node;
	}
	node->height = max(getheight(node->left),getheight(node->right))+1;
	return node;
}

struct node* insertion_avl(struct node* node,int key)
{
	if(node == NULL)
	return newnode(key);
	if(key > node->key)
	node->right = insertion_avl(node->right,key);
	else if(key < node->key)
	node->left = insertion_avl(node->left,key);
	else
	{
		printf("duplicate element \n");
		return node;
	}
	node->height = max(getheight(node->left),getheight(node->right))+1;
	int balancefactor = getheight(node->left) - getheight(node->right);
	if(balancefactor > 1 && key < node->left->key)
	{
		return rotateright(node);	
	}
	if(balancefactor > 1 && key > node->left->key)
	{
		node->left = rotateleft(node->left);
		return rotateright(node);
	}
	if(balancefactor <-1 && key > node->right->key)
	{
		return rotateleft(node);
	}
	if(balancefactor <-1 && key < node->right->key)
	{
		node->right = rotateright(node->right);
		return rotateleft(node);
	}
	return node;
}

struct node* findminnode(struct node* node)
{
	for(;node->left != NULL;node=node->left)
	;
	return node;
}

int getbalancefactor(struct node* node)
{
	return (node == NULL)?0:getheight(node->left)-getheight(node->right);
}

struct node* deletebst(struct node* node,int key)
{
	if(node == NULL)
	return NULL;
	if(key > node->key)
	node->right = deletebst(node->right,key);
	if( key < node->key)
	node->left = deletebst(node->left,key);
	else
	{
		if(node->right == NULL && node->left == NULL)
		{
			free(node);
			return NULL;
		}
		else if(node->left && node->right == NULL)
		{
			struct node*temp = node;
			node = node->left;
			free(node);
		}
		else if(node->right && node->left == NULL)
		{
			struct node *temp = node;
			node = node->right;
			free(node);
		}
		else
		{
			struct node* temp = findminnode(node->right);
			node->key = temp->key;
			node->right = deletebst(node->right,temp->key);
		}
		node->height = max(getheight(node->left),getheight(node->right))+1;
		return node;
	}

	return node;
}

struct node* deleteavl(struct node* node,int key)
{
	if(node == NULL)
	return NULL;
	if(key > node->key)
	node->right = deleteavl(node->right,key);
	else if(key < node->key)
	node->left = deleteavl(node->left,key);
	else
	{
		if(node->left == NULL && node->right == NULL)
		{
			free(node);
			return NULL;
		}
		else if(node->left && node->right == NULL)
		{
			struct node* temp = node;
			node = node->left;
			free(temp);
		}
		else if(node->right && node->left == NULL)
		{
			struct node* temp = node;
			node = node->right;
			free(temp);
		}
		else
		{
			struct node* temp = findminnode(node->right);
			node->key = temp->key;
			node->right = deleteavl(node->right,key);
		}
	}
		node->height = max(getheight(node->left),getheight(node->right))+1;
		int balancefactor = getbalancefactor(node);
		if(balancefactor >1 && key < node->left->key)
		{
			return rotateright(node);
		}
		 if(balancefactor <1 && key > node->left->key)
		{
			node->left = rotateleft(node->left);
			return rotateright(node);
		}
		 if(balancefactor <-1 && key > node->right->key)
		{
			return rotateleft(node);
		}
		if(balancefactor <-1 && key < node->right->key) 
		{
			node->right = rotateleft(node->right);
			return rotateleft(node);
		}		
	return node;
}
void preordertraversal(struct node* node)
{
	if( node == NULL)
	return;
	printf("%d",node->key);
	preordertraversal(node->left);
	preordertraversal(node->right);
}

int main()
{
	int choice,k;
	struct node* root = NULL,*root1 = NULL;
	while(1)
	{
		printf("");
		printf("\nenter the choice to select operation : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the no to insert into bst : ");
				scanf("%d",&k);
				root = insertionbst(root,k);
				break;
			case 2:
			    printf("enter the no to delete from bst : ");
				scanf("%d",&k);
				root = deletebst(root,k);
				break;
			case 3:
			    printf("enter the no to insert into avl : ");
				scanf("%d",&k);
				root1 = insertion_avl(root1,k);
				break;
			case 4:
			    printf("enter the no to delete from avl : ");
				scanf("%d",&k);
				root1 = deleteavl(root1,k);
				break;
			case 5 :
				printf("preordertraversal of bst : ");
			    preordertraversal(root);
				break;			
			case 6 :
			    printf("preordertraversal of avl : ");
				preordertraversal(root1);
				break;
			default :
			printf("enter the right choice\n ");
			break;			
		}
	}
}

