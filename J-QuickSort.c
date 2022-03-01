#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i=l,j=h;

    while(i<j)
    {
        do{
            i++;
        } while(a[i]<=pivot);

        do
        {
            j--;
        } while (a[j]>pivot);

        if(i<j)
        {
            swap(&a[i],&a[j]);
        }      
    }

    swap(&a[l],&a[j]);

    return j;
}

void QuickSort(int *a,int l,int h)
{
    int j;
    if(l<h)
    {
        j = Partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

int main()
{
    int i,n,a[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    QuickSort(a,0,n);

    printf("After sorting :");
    for(i=0;i<n;i++) printf("%d ",a[i]);

    return 0;
}
