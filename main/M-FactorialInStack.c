#include <stdio.h>
#include <stdlib.h>
#define max 30

int stack[max],n=-1;//

void push(int);
int pop();
void display();

int factorial(int num)
{
    if(num==1)
    {
        push(1);
        int res = 1;
        while(n>=0) res = res*pop();
        return res;
    }
    else{
        push(num);
        return factorial(num-1);
    }
}

int main()
{
    int val;
    printf("Enter a value: ");
    scanf("%d",&val);

    if(val==0) printf("Factorial of 0 is 1\n");
    else printf("Factorial of %d is %d\n",val,factorial(val));

    return 0;
}

void push(int x)
{
    if(n==max-1)
    {
        printf("Overflow!");
        exit(1);
    }
    else
    {
        n++;
        stack[n]=x;
    }
}

int pop()
{
    if(n==-1)//
    {
        printf("Stack is empty!\n");
        exit(1);
    }
    else
    {
        int res = stack[n];
        n--;
        return res;
    }
}

void display()
{
    int i;
    for(i=stack[n];i>=0;i--) printf("%d ",stack[i]);
    printf("\n");
}


