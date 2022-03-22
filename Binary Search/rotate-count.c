// Find the number of times a soted array is rotated (no duplicates!)

#include <stdio.h>

int rCount(int a[], int n)
{
    int low = 0, high = n-1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(a[low]<=a[high]) return low;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        if(a[mid]<=a[prev]&&a[mid]<=a[next]) 
            return mid;
        else if(a[mid]<=a[high])    //right part is sorted
            high = mid-1;
        else                       //left part is sorted
            low = mid+1;
    }
    return -1;
}

int main()
{
    int a[] = {10,2,4,6,8};
    int ans = rCount(a,5);

    if(ans==-1) printf("Error!");
    else printf("Array is rotated %d times\n", ans);

    return 0;
}
