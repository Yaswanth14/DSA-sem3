#include <stdio.h>

int Linear(int arr[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x) return i;
    }
    return -1;
}

int main()
{
    int n,i,arr[100],val,x;
    printf("Enter number of elements: ");
    scanf("%d",&val);
    for(i=0;i<val;i++) scanf("%d",&arr[i]);
    printf("\n Enter element to search: ");
    scanf("%d",&x);

    n = Linear(arr,val,x);
    if(n==-1) printf("Element not found!\n");
    else printf("Element found at index %d\n",n);

    return 0;
}