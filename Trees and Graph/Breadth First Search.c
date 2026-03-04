//Breadth First Search
//@uthor: Aadi Kulshreshth
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
    int vertex;
    struct node* next;
};

struct graph
{
    int numVertices;
    struct node** adjlists[MAX];
    int visited[MAX];
};

struct node* createnode(int v)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=v;
    newnode->next=NULL;
    return newnode;
}

struct graph* creategraph(int vertices)
{
    struct graph *graph=(struct graph*)malloc(sizeof(struct graph));
    graph->numVertices=vertices;
    for(int i=0;i<vertices;i++)
    {
        graph->adjlists[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}

void addedge(struct graph *graph, int src, int dest)
{
    struct node *newnode=createnode(dest);
    if (graph->adjlists[src] == NULL)
        graph->adjlists[src] = newnode;
    else 
    {
        struct node* temp = graph->adjlists[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    newnode = createnode(src);
    if (graph->adjlists[dest] == NULL)
        graph->adjlists[dest] = newnode;
    else 
    {
        struct node* temp = graph->adjlists[dest];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void BFS(struct graph *graph, int startvertex)
{
    int queue[MAX];
    int front=0, rear=0;

    graph->visited[startvertex]=1;
    queue[rear++]=startvertex;

    while(front!=rear)
    {
        int currentvertex=queue[front++];
        printf("%d ", currentvertex);

        struct node *temp=graph->adjlists[currentvertex];
        while(temp)
        {
            int adjvertex=temp->vertex;
            if(!graph->visited[adjvertex])
            {
                queue[rear++]=adjvertex;
                graph->visited[adjvertex]=1;
            }
            temp=temp->next;
        }
    }
}

int main()
{
    struct graph *graph=creategraph(6);

    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 2, 4);
    addedge(graph, 3, 5);
    addedge(graph, 4, 5);

    printf("BFS from vertex 0:\n");
    BFS(graph, 0);

    return 0;
}
