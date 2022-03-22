// Find element in circularly sorted array O(logN) (no duplicates!!)

#include <stdio.h>

int circularSearch(int a[], int n, int x)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;

        if(x==a[mid]) return mid;
        else if(a[mid]<=a[high])
        {
            if(x>a[mid]&&x<=a[high])
                low = mid+1;
            else 
                high = mid-1;
        }
        else
        {
            if(a[low]<=x&&x<a[mid])
                high = mid-1;
            else 
                low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {10,2,4,6,8};
    int ans = circularSearch(a,5,8);

    if(ans==-1) printf("Element not found\n");
    else printf("element found at index %d\n", ans);

    return 0;
}


