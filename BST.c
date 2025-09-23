#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node*right;
};
struct node * create(int d)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=d;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
struct node* insert(struct node* root, int d)
{
    if (root == NULL) {
        return create(d);
    }
    
    if (d < root->data) {
        root->left = insert(root->left, d);
    } else if (d > root->data) {
        root->right = insert(root->right, d);
    }
    
    return root;
}

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node*root)
{
     if(root==NULL)
    {
        return;
    }
   
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct node* search(struct node* root, int key)
{
    if(root==NULL||key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

struct node* inordersuccessor(struct node*root)
{
    struct node* curr=root;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

struct node* delete(struct node* root, int d)
{
    if (root == NULL) 
    {
        return NULL;
    }
    
    if (d < root->data) 
    {
        root->left = delete(root->left, d);
    } 
    else if (d > root->data) 
    {
        root->right = delete(root->right, d);
    } 
    else 
    {
        struct node* temp;
        
        if (root->left == NULL) 
        {
            temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            temp = root->left;
            free(root);
            return temp;
        } 
        else 
        {
            struct node* succ = inordersuccessor(root->right);
            root->data = succ->data;
            root->right = delete(root->right, succ->data);
        }
    }
    return root;
}

int main()
{
    struct node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    printf("Inorder traversal\n");
    inorder(root);
    printf("\nPostorder traversal\n");
    postorder(root);
    printf("\npreorder traversal\n");
    preorder(root);
    int key;
    printf("\nEnter an element to search:");
    scanf("%d",&key);
    struct node * res=search(root,key);
    if(res!=NULL)
    {
        printf("%d element is found",key);
    }
    else
    {
         printf("%d element is not found",key);
    }
    int s;
    printf("\nEnter an element to delete:");
    scanf("%d",&s);
    root=delete(root,s);
    inorder(root);
    return 0;
}
