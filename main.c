#include "Algorithms.h"
#include "Graph.h"
#include "List.h"
#include "Util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void PrintPath(GraphNode *graph, IntFloatPair *res, int node)
{
    if (res[node].first != -1) {
        PrintPath(graph, res, res[node].first);
    }
    printf("%s (%f)\n", graph[node].name, pow(10, -res[node].second));
}

int main()
{
    FILE *fin = fopen("test.txt", "r");
    int n, i, x, y;
    char str_aux[STRING_LIMIT];
    float cost;

    fscanf(fin, "%d%*c", &n);
    GraphNode *graph = CreateGraph(n);

    for (i = 0; i < n; ++i) {
        ReadLine(str_aux, STRING_LIMIT, fin);
        SetNodeName(graph, i, str_aux);
    }

    while (fscanf(fin, "%d%d%f", &x, &y, &cost) != EOF) {
        AddEdge(graph, x - 1, y - 1, -log10f(cost));
        AddEdge(graph, y - 1, x - 1, -log10f(1 / cost));
    }

    int choice;
    scanf("%d", &choice);

    ListNode *res = FindNegativeCycle(graph, n, choice - 1);
    if (res == NULL) {
        printf("Graful nu are niciun ciclu negativ.\n");
    } else {
        printf("Am gasit ciclu negativ.\n");
    }

    ListNode *it = res;
    while (it) {
        printf("%s\n", graph[it->value].name);
        it = it->next;
    }

    if (res != NULL) {
        FreeList(&res);
    }
    FreeGraph(&graph);

    return 0;
}
