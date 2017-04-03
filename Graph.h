#ifndef GRAPH_H
#define GRAPH_H

typedef struct EdgeListNode
{
    int node;
    float cost;
    struct EdgeListNode *next;
} EdgeListNode;

typedef struct GraphNode
{
    char *name;
    EdgeListNode *edges;
} GraphNode;

GraphNode* CreateGraph(int nodes);
void AddEdge(GraphNode *graph, int x, int y, float cost);
void SetNodeName(GraphNode *graph, int node, char *name);
void FreeGraph(GraphNode **graph);

#endif // GRAPH_H