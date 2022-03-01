// DFS uses stack for traversal.Here we used recursion which internally uses stack for operation. Bingo!!
// Credit: Code With Harry

#include<stdio.h>
int visited[4] = {0,0,0,0};
int AdjMat[4][4];

void DFS(int);

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
    DFS(start);

    return 0;
}

void DFS(int a)
{
    printf("%d -> ",a);
    visited[a] = 1;
    
    for(int j=0;j<4;j++)
    {
        if(AdjMat[a][j]==1&&!visited[j]) DFS(j);
    }
}
