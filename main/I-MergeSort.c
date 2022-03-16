#include <stdio.h>

void Merge(int arr[],int lb,int mid, int ub)
{
    int i,j,k,b[100];
    i=lb;
    j = mid+1;
    k = lb;

    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<=ub;k++) arr[k] = b[k]; 
}

void MergeSort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid = (lb+ub)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
    }
}

int main()
{
    int i,n,arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    MergeSort(arr,0,n-1);

    printf("After sorting :");
    for(i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;

}
