//Dijkstra Algorithm
//@uthor: Aadi Kulshreshth
#include<stdio.h>
#define MAX 100
#define INF 999

int MinDistance(int dist[], int visited[], int n)
{
    int min=INF, min_index=-1;

    for(int v=0; v<n; v++)
    {
        if(!visited[v]&& dist[v]<=min)
        {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX], visited[MAX];

    for(int i=0; i<n;i++)
    {
        dist[i]=INF;
        visited[i]=0;
    }

    dist[src]=0;

    for(int c=0; c<n-1; c++)
    {
        int u=MinDistance(dist, visited, n);
        if(u==-1) break;
        visited[u]=1;

        for(int v=0;v<n;v++)
        {
            if(!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", i);
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}
int main()
{
    int graph[MAX][MAX], n, src;

    printf("Enter the number of nodes in the graph:");
    scanf("%d", &n);

    printf("\nEnter the value for thea adjacency matrix (use %d for no edge):\n",INF);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node:");
    scanf("%d", &src);

    if (src < 0 || src >= n) 
    {
        printf("Invalid source node! Enter between 0 and %d.\n", n - 1);
        return 0;
    }   


    dijkstra(graph, n, src);

    return 0;
}