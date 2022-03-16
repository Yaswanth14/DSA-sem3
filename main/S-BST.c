#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};


//Function to create new node 
struct BstNode *GetNew(int data)
{
    struct BstNode *NewNode = malloc(sizeof(struct BstNode));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}


void Inorder(struct BstNode* root)
{
    if(root == NULL) return;

    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Preorder(struct BstNode* root)
{
    if(root==NULL) return;

    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct BstNode* root)
{
    if(root==NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}


struct BstNode *Insert(struct BstNode *root, int data)
{

    if(root == NULL) root = GetNew(data);
    else if(data<=root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);

    return root;
}

void Search(struct BstNode *root, int data)
{
    if(root == NULL) printf("Element not Found!\n");
    else if(root->data==data) printf("Element found!\n");
    else if(data<=root->data) return Search(root->left,data);
    else return Search(root->right,data);
}

struct BstNode *FindMax(struct BstNode *ptr)
{
    while(ptr->right!=NULL) ptr = ptr->right;
    return ptr;
}

struct BstNode* Delete(struct BstNode *root, int data)
{
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
            struct BstNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right==NULL) //Only 1 Child (left)
        {
            struct BstNode *temp = root;
            root = root->left;
            free(temp);
        }
        else //2 Children
        {
            struct BstNode *temp = FindMax(root->left);
            int val = temp->data;
            root->data = val;    //Replacing with Maximum of left sub-tree
            root->left = Delete(root->left,temp->data);
        }
    }
    return root;
}



int main()
{
    int choice,item;
    struct BstNode *root = NULL;
    

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
