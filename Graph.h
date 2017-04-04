#ifndef GRAPH_H
#define GRAPH_H

/* Structura care reprezinta o muchie intr-un graf orientat.
   node este nodul in care se gaseste varful muchiei.
   cost este costul muchiei.
   next este un pointer la urmatorul nod din lista de muchii. Astfel, folosind
   aceasta structura putem reprezenta o lista simplu inlantuita alocata dinamic.
   Muchia porneste din nodul care contine lista de muchii. */
typedef struct EdgeListNode
{
    int node;
    float cost;
    struct EdgeListNode *next;
} EdgeListNode;

/* Structura ce reprezinta nodul unui graf orientat.
   Nodul are un nume (sir de caractere) si o lista de muchii */
typedef struct GraphNode
{
    char *name;
    EdgeListNode *edges;
} GraphNode;

/* Functie care aloca un vector de noduri de lungime nodes (creeaza un graf) */
GraphNode* CreateGraph(int nodes);

/* Functie care adauga muchia (x, y) cu costul cost in graful graph */
void AddEdge(GraphNode *graph, int x, int y, float cost);

/* Functie care seteaza numele nodului cu indicele node la valoarea name */
void SetNodeName(GraphNode *graph, int node, char *name);

/* Functie care elibereaza din memorie graful graph */
void FreeGraph(GraphNode **graph);

#endif // GRAPH_H