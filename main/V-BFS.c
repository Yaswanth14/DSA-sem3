#include<stdio.h>
int queue[4];
int visited[4] = {0,0,0,0};
int AdjMat[4][4];

int front = -1, rear = -1;

void enque(int a)
{
    if(rear == 3); //We are doing this only for 4 elements
    else
    {
        if(front==-1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = a;
    }
}

int deque()
{
    if(front>rear || front==-1); //queue empty
    else
    {
        front++;
        return queue[front-1];
    }
}

int isEmpty()
{
    if(front>rear || front==-1) return 1;
    return 0;
}

void BFS(int v)
{
    printf("%d -> ",v);
    visited[v] = 1;
    enque(v); // to explore 
    
    while(!isEmpty()){
        
    int val = deque();
    for(int i=0;i<4;i++)
    {
        if(AdjMat[v][i]==1&&!visited[i])
        {
            printf("%d -> ", i);
            visited[i] = 1;
            enque(i);
        }
    }
    }
}

int main()
{
    int i,j,start;
    printf("Enter values is Adjacency Matrix(0/1): \n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Enter (%d , %d): ",i,j);
            scanf("%d",&AdjMat[i][j]);
        }
    }

    printf("Enter vertex to start from (0/1/2/3): ");
    scanf("%d",&start);
    BFS(start);

    return 0;
}
