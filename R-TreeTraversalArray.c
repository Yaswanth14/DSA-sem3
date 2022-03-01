// Tree travelsal using arrays(level ordered)| credits:Akhil Nerella :)

#include <stdio.h>

void Inorder(int a[],int i,int n)
{
    if(2*i<=n) Inorder(a,2*i,n);
    printf("%d ",a[i]);
    if(2*i+1<=n) Inorder(a,2*i+1,n);
}

void Preorder(int a[],int i,int n)
{
    printf("%d ",a[i]);
    if(2*i<=n) Preorder(a, 2*i, n);
    if(2*i+1<=n) Preorder(a,2*i+1,n);
}

void Postorder(int a[], int i, int n)
{
    if(2*i<=n) Postorder(a,2*i,n);
    if(2*i+1<=n) Postorder(a,2*i+1,n);
    printf("%d ",a[i]);
}

int main()
{
    int i,n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter vertices: ");
    for(i=1;i<=n;i++) scanf("%d",&a[i]);    //level order

    printf("\nInorder: ");
    Inorder(a,1,n);
    printf("\nPreorder: ");
    Preorder(a,1,n);
    printf("\nPostorder: ");
    Postorder(a,1,n);

    return 0;
}


