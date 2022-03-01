#include <stdio.h>

int fact(int n)
{
    if(n==0) return 1;
    else return n*fact(n-1);
}

int main()
{
    int n,ans;
    printf("Enter a number: ");
    scanf("%d",&n);
    ans = fact(n);
    printf("Factorial of %d = %d",n,ans);

    return 0;
}

