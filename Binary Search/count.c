// Find count of element in sorted array O(logN)

#include <stdio.h>

int Search(int a[], int n, int x, int first)
{
    int low = 0, high = n-1, result = -1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(a[mid] == x)
        {
            result = mid;
            if(first) high = mid-1;
            else low = mid+1;
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
    int a[] = {1,2,3,4,5,5,5,5,5,5,7,10};
    int x = 5;
    int firstIndex = Search(a, 12, x, 1);

    if(firstIndex==-1)
    {
        printf("Count of %d is 0",x);
    }
    else
    {
        int lastIndex = Search(a, 12, 5, 0);
        printf("Count of %d is %d\n",x, (lastIndex-firstIndex)+1);
    }
    return 0;
}
