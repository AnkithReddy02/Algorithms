#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    
    temp->left = temp->right = NULL;
    
    temp->data = data;
    
    return temp;
}
struct node *insert_bst_Minimum_Height(int a[],int start ,int end,struct node* root)
{
    if(start>end)
    {
        return NULL;
    }
    
    int middle = (start+end)/2;
    
    root = newnode(a[middle]);
    
    root->left = insert_bst_Minimum_Height(a,start,middle-1,root->left);
    
    root->right = insert_bst_Minimum_Height(a,middle+1,end,root->right);
    
    return root;
}
struct node *insert_bst_Maximum_Height(int data ,struct node* root)
{
    if(root==NULL)
    {
        return newnode(data);
    }
    
    if(root->data > data)
    {
        root->left = insert_bst_Maximum_Height(data,root->left);
    }
    else
    {
        root->right = insert_bst_Maximum_Height(data,root->right);
    }
    return root;
}
void Inorder(struct node * root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Preorder(struct node* root)
{
    if(!root)
    {
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(struct node *root)
{
    if(!root)
    {
        return ;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void print_bst(struct node *root)
{
    printf("Inorder of Maximum_Height Tree : ");
    Inorder(root);
    printf("\nPreorder of Maximum_Height Tree : ");
    Preorder(root);
    printf("\nPostorder of Maximum_Height Tree : ");
    Postorder(root);
}
void delete_bst(struct node *root)
{
    if(!root)
    {
        return;
    }
    delete_bst(root->left);
    delete_bst(root->right);
    free(root);
}
int height_bst(struct node * root) // height of single node is considered as 1 ;
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height_bst(root->left),height_bst(root->right));
}
int main()
{
    printf("Enter Number of nodes to Create BST : ");
    int n;
    cin >> n;
    
    printf("Enter %d values to insert into BST : ",n);
    int a[n];
    
    struct node * root = NULL;
    
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    sort(a,a+n);
    
    for(int i=0;i<n;i++)
    {
       root =  insert_bst_Maximum_Height(a[i],root);
    }
    
     printf("\nPrinting Traversal for Maximum_Height_Bst(height : %d) :\n\n ",height_bst(root));
    
    print_bst(root);
    
    delete_bst(root); // frreing bst
    
    root = NULL;
    
   root = insert_bst_Minimum_Height(a,0,n-1,root);
    
   printf("\n\nPrinting Traversal for Minimum_Height_Bst(height_bst : %d) : \n\n",height_bst(root));
    
     print_bst(root);
     
     delete_bst(root);
     
      root = NULL;
    
    
    
}

