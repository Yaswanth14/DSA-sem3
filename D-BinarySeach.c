#include <stdio.h>

int Binary(int arr[],int n,int x)
{
    int mid;
    int low = 0, high = n-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==x) return mid; //Found
        else if(arr[mid]>x) high = mid-1;
        else low = mid+1;
    }

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

    ans = Binary(arr,n,x);
    if(ans==-1) printf("Element not found!\n");
    else printf("Element found at index %d\n",ans);

    return 0;
}

