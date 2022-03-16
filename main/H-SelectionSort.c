#include <stdio.h>

void Selection(int arr[],int n)
{
    int i,j,imin,temp;
    for(i=0;i<n;i++)
    {
        imin = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[imin]) imin = j;
        }
        temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }
}

int main()
{
    int n,i,arr[20];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    Selection(arr,n);

    printf("After sorting :");
    for(i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}
