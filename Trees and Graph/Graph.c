//GRAPH
//@uthor: Aadi Kulshreshth
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int vertex;
    struct node *next;
};

struct graph 
{
    int numvertex;
    struct node **adjLists;
};

struct node* CreateNode(int v) 
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct graph* CreateGraph(int vertices) 
{
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numvertex = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct graph* graph, int src, int dest) 
{
    if (src >= graph->numvertex || dest >= graph->numvertex) 
    {
        printf("Invalid vertex!\n");
        return;
    }

    struct node *newnode = CreateNode(dest);
    newnode->next = graph->adjLists[src];
    graph->adjLists[src] = newnode;

    newnode = CreateNode(src);
    newnode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newnode;
}

void deleteEdge(struct graph* graph, int src, int dest) 
{
    if (src >= graph->numvertex || dest >= graph->numvertex) 
    {
        printf("Invalid vertex!\n");
        return;
    }

    struct node *temp = graph->adjLists[src];
    struct node *prev = NULL;


    while (temp && temp->vertex != dest) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp) 
    {
        if (prev)
            prev->next = temp->next;
        else
            graph->adjLists[src] = temp->next;
        free(temp);
    }

    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp && temp->vertex != src) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp) 
    {
        if (prev)
            prev->next = temp->next;
        else
            graph->adjLists[dest] = temp->next;
        free(temp);
    }

    printf("Edge %d - %d deleted.\n", src, dest);
}

void printGraph(struct graph *graph) 
{
    for (int i = 0; i < graph->numvertex; i++) 
    {
        struct node *temp = graph->adjLists[i];
        printf("\nAdjacency list of vertex %d:\n %d", i, i);
        while (temp) 
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() 
{
    int v = 4;
    struct graph *graph = CreateGraph(v);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    printf("\nDeleting edge 1 - 2...\n");
    deleteEdge(graph, 1, 2);

    printf("\nGraph after deleting edge:\n");
    printGraph(graph);

    return 0;
}

