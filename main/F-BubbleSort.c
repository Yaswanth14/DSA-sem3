#include <stdio.h>

void Bubble(int arr[],int n)
{
    int i,j,temp;

    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("After sorting :");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
}

int main()
{
    int n,i,arr[20];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    Bubble(arr,n);

    return 0;
}
