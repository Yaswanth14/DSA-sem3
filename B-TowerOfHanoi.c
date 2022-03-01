#include <stdio.h>

void Tower(int n ,char* A, char* B, char* C)
{
    if(n==1)
    {
        printf("Move 1 from %c to %c\n",*A,*C);
        return;
    }

    Tower(n-1,A,C,B);
    printf("Move %d from %c to %c\n",n,*A,*C);
    Tower(n-1,B,A,C);
}

int main()
{
    int n;
    printf("Enter number of rods: ");
    scanf("%d",&n);
    Tower(n,"A","B","C");

    return 0;
}

