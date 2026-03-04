//DFS
//@uthor: Aadi kulshreshth
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
    int vertex;
    struct node* next;
};

struct Graph
{
    int numvertices;
    struct node** adjlists;
    int *visited;
};

struct node* createnode(int v)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=v;
    newnode->next=NULL;
    return newnode;
}

struct Graph* creategraph(int vertices)
{
    struct Graph* graph=malloc(sizeof(struct Graph));
    graph->numvertices=vertices;
    graph->adjlists = malloc(vertices *sizeof(struct node*));
    graph->visited = malloc(vertices *sizeof(int));

    for(int i=0;i<vertices;i++)
    {
        graph->adjlists[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct node* newnode=createnode(dest);
    newnode->next=graph->adjlists[src];
    graph->adjlists[src]=newnode;

    newnode=createnode(src);
    newnode->next=graph->adjlists[dest];
    graph->adjlists[dest]=newnode;
}

void DFS(struct Graph* graph, int vertex)
{
    struct node* adjList=graph->adjlists[vertex];
    struct node* temp=adjList;

    graph->visited[vertex]=1;
    printf("%d ", vertex);

    while(temp!=NULL)
    {
        int connectedvertex=temp->vertex;

        if(graph->visited[connectedvertex]==0)
            DFS(graph, connectedvertex);
        
        temp=temp->next;
    }
}

int main()
{
    struct Graph* graph=creategraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 2);

    printf("DFS from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
