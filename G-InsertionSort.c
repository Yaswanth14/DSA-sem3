#include <stdio.h>

void Insertion(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp = arr[i];
        j = i-1;

        while(j>=0&&temp<=arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int n,i,arr[20];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    Insertion(arr,n);

    printf("After sorting :");
    for(i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}

