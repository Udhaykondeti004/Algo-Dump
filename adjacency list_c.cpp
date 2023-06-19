#include<stdio.h>
int main()
{
    int i,j;
    int n,e;
    int s,end;
    scanf("%d",&n);
    int mat[n][n];
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
        for(j=0;i<n;j++)
        {
            mat[i][j] = 0;
        }
    }
    for(i=0;i<e;i++)
    {
        scanf("%d",&s);
        scanf("%d",&end);
        mat[s][end] = 1;
        mat[end][s] = 1;
    }
    for(i=0;i<n;i++)
    {
        printf("Adjacency list of vertex %d\n",i);
        printf("head ");
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==1)
            {
                printf("-> %d",j);
            }
        }
        printf("\n");
    }
    return 0;
}
