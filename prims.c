#include<stdio.h>
#define INFI 99

int mst[10][3], adj_matrix[10][10];

void prims(int);

void main() {
    int n;
    printf("\n Enter the number of vertices: ");
    scanf("%d", & n);
    printf("\n Enter the adjacency matrix: ");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", & adj_matrix[i][j]);
    prims(n);
}

void prims(int n) {
    int u[10], lowcost[10], visited[10];
    int min, mincost = 0, i, j, v;
    visited[1] = 1;

    //find low cost edge 
    for (int i = 2; i <= n; i++) {
        visited[i] = 0;
        u[i] = 1;
        lowcost[i] = adj_matrix[1][i];
    }

    for (i = 1; i <= n - 1; i++) {
        min = lowcost[2];
        v = 2;
        for (j = 3; j <= n; j++) {
            if (lowcost[j] < min) {
                min = lowcost[j];
                v = j;
            }
        }

        //save edge 
        mst[i][1] = u[v];
        mst[i][2] = v;
        mincost += lowcost[v];
        visited[v] = 1;
        lowcost[v] = INFI;
        for (j = 2; j <= n; j++)
            if (adj_matrix[v][j] < lowcost[j] && !visited[j]) {
                lowcost[j] = adj_matrix[v][j];
                u[j] = v;
            }
    }
    printf("\n\n The edges of minimum spanning tree are: \n");
    for (i = 1; i <= n - 1; i++)
        printf(" (%d,%d)\n", mst[i][1], mst[i][2]);
    printf("\n The cost of minimum spanning tree is: %d", mincost);
}