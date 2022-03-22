// Find last occurence of an element in array O(logN)

#include <stdio.h>

int FindFirst(int a[], int n, int x)
{

    int low = 0;
    int high = n-1;
    int result = -1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(x==a[mid])
        {
            result = mid;
            low = mid+1;
        }
        else if(x<a[mid])
            high = mid-1;
        else 
            low = mid+1;
    }
    return result;
}

int main()
{
    int a[] = {1,2,3,4,5,5,5,5,5,6,7,10};
    int x = 5;
    int n = FindFirst(a,12,x);
    if(n==-1) printf("Element not found");
    else printf("Last occurence of %d is at %d.\n",x,n);

    return 0;
}
