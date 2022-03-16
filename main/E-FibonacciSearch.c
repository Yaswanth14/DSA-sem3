#include <stdio.h>

int min(int x,int y)
{
    return (x<=y)?x:y;
}

int Fibo(int arr[], int x, int n)
{
    int k2 = 0, k1 = 1;
    int k = k1+k2;

    while(k<n)
    {
        k2 = k1;
        k1 = k;
        k = k1+k2;
    }

    int offset = -1;

    while(k>1)
    {
        int i = min(offset+k2,n-1);
        if(arr[i]<x)
        {
            k = k1;
            k1 = k2;
            k2 = k-k1;
            offset = i;
        }
        else if(arr[i]>x)
        {
            k = k2;
            k1 = k1-k2;
            k2 = k-k1;
        }
        else return i;
    }
    if(k1&&arr[offset+1]==x)    return offset+1;
    return -1;
}

int main()
{
    int i,arr[100],n,x,ans;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter element to search: ");
    scanf("%d",&x);

    ans = Fibo(arr,x,n);
    if(ans==-1) printf("Element not found!\n");
    else printf("Element found at index %d\n",ans);

    return 0;
}

