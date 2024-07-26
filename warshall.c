#include<stdio.h>
#define MAX 10

int dist[MAX][MAX],n;

void warshall()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
}

int main()
{
    int i, j;
    printf("Enter the number of vertices :\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for( j=1;j<=n;j++)
            scanf("%d",&dist[i][j]);
    warshall();
    printf("\nTrasitive closure of digraph is :\n");
    for( i=1;i<=n;i++)
    {
        for( j=1;j<=n;j++)
        {
            printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}