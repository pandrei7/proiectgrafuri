#include "Graph.h"
#include "Util.h"
#include <stdlib.h>
#include <string.h>

GraphNode* CreateGraph(int nodes)
{
    GraphNode *graph = (GraphNode*)malloc(nodes * sizeof(GraphNode));
    int i;

    /* Fiecare nod al grafului trebuie initializat */
    for (i = 0; i < nodes; ++i) {
        graph[i].name = NULL;
        graph[i].edges = NULL;
    }
    return graph;
}

/* Functie care creaza o noua muchie (nod al unei liste de muchii) */
EdgeListNode* CreateEdgeListNode(int node, float cost)
{
    EdgeListNode *new_node = (EdgeListNode*)malloc(sizeof(EdgeListNode));
    *new_node = (EdgeListNode){node, cost, NULL};
    return new_node;
}

/* Functia adauga muchia (x, y) la inceputul liste de muchii a nodului x */
void AddEdge(GraphNode *graph, int x, int y, float cost)
{
    EdgeListNode *new_node = CreateEdgeListNode(y, cost);
    new_node->next = graph[x].edges;
    graph[x].edges = new_node;
}

void SetNodeName(GraphNode *graph, int node, char *name)
{
    /* Daca nodul are deja un nume, eliberez memoria ocupata de acesta */
    if (graph[node].name != NULL) {
        free(graph[node].name);
    }

    /* Aloc memorie pentru a retine numele intreg */
    graph[node].name = CreateString(strlen(name));
    strcpy(graph[node].name, name);
}

void FreeGraph(GraphNode **graph)
{
    /* Numarul de noduri al grafului este calculat in limit */
    int limit = sizeof(*graph) / sizeof((*graph)[0]);
    int i;

    for (i = 0; i < limit; ++i) {
        if ((*graph)[i].name != NULL) {
            free((*graph)[i].name);
        }
    }
    free(*graph);
}