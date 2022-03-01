#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node *temp,*x,*y;


//Function to create new node 
struct Node *GetNew(int data)
{
    struct Node *NewNode = malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

int height(struct Node *node)
{
    if(node==NULL) return 0;
    return node->height;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int getBalanceFactor(struct Node *node)
{
    if(node==NULL) return 0;
    return height(node->left)-height(node->right);
}

void Inorder(struct Node* root)
{
    if(root == NULL) return;

    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Preorder(struct Node* root)
{
    if(root==NULL) return;

    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct Node* root)
{
    if(root==NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

struct Node *LRotate(struct Node *node)
{
    x = node->right;
    y = x->left;

    x->left = node;
    node->right = y;

    return x;
}

struct Node *RRotate(struct Node *node)
{
    x = node->left;
    y = x->right;

    x->right = node;
    node->left = y;
}

struct Node *Insert(struct Node *root, int data)
{
    int balance;
    if(root == NULL) root = GetNew(data);
    else if(data<=root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);

    root->height = 1+max(height(root->left),height(root->right));
    balance = getBalanceFactor(root);

    if(balance>1&&data<(root->left)->data) return RRotate(root);
    if(balance<-1&&data>(root->right)->data) return LRotate(root);

    if(balance>1 && data>(root->left)->data) return RRotate(root);
    if(balance<-1 && data<(root->left)->data) return LRotate(root);

    return root;
}

void Search(struct Node *root, int data)
{
    if(root == NULL) printf("Element not Found!\n");
    else if(root->data==data) printf("Element found!\n");
    else if(data<=root->data) return Search(root->left,data);
    else return Search(root->right,data);
}

struct Node *FindMax(struct Node *ptr)
{
    while(ptr->right!=NULL) ptr = ptr->right;
    return ptr;
}

struct Node* Delete(struct Node *root, int data)
{
    int balance;

    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else //Element Found
    {
        if(root->left==NULL && root->right==NULL) //No Child
        {
            free(root);
            root = NULL;
        }
        else if(root->left==NULL) //Only 1 Child (right)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right==NULL) //Only 1 Child (left)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else //2 Children
        {
            struct Node *temp = FindMax(root->left);
            int val = temp->data;
            root->data = val;    //Replacing with Maximum of left sub-tree
            root->left = Delete(root->left,temp->data);
        }
    }

    root->height = 1+max(height(root->left),height(root->right));
    balance = getBalanceFactor(root);

    if(balance>1&&data<(root->left)->data) return RRotate(root);
    if(balance<-1&&data>(root->right)->data) return LRotate(root);

    if(balance>1 && data>(root->left)->data) return RRotate(root);
    if(balance<-1 && data<(root->left)->data) return LRotate(root);

    return root;
}



int main()
{
    int choice,item;
    struct Node *root = NULL;
    

    printf("1. Insert, 2. Delete, 3. Search, 4. Inorder Traversal, 5. Preorder, 6.Postorder, 7. Exit\n");
    
    while(1)
    {
        int op,val;
        printf("\nEnter your choice: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d",&val);
            root = Insert(root,val);
            printf("Done!");
            break;

        case 2:
            printf("Enter element to delete: ");
            scanf("%d",&val);
            root = Delete(root,val);
            printf("Done!");
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d",&val);
            Search(root,val);
            break;

        case 4:
            printf("Inorder traversal : ");
            Inorder(root);
            break;

        case 5:
            printf("Preorder traversal: ");
            Preorder(root);
            break;

        case 6:
            printf("Postorder traversal: ");
            Postorder(root);
            break;

        case 7:
            exit(1);
            break;
        
        default:
            printf("Something went wrong!!");
            break;
        }
    }

    return 0;  
}
