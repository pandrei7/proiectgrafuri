#include "Algorithms.h"
#include "Graph.h"
#include "List.h"
#include "Queue.h"
#include "Util.h"
#include <stdlib.h>

/* Functie care reconstituie un ciclu de cost negativ pe baza vectorilor
   pred si costs, calculati de functia FindNegativeCycle. Functia returneaza
   o lista cu indicii nodurilor din ciclu.
   Nodes reprezinta numarul nodurilor din graf, iar start, nodul din care
   incepe constructia ciclului */
ListNode* RetraceCycle(int *pred, float *costs, int nodes, int start)
{
    ListNode *list = NULL; /* Lista ce va fi returnata */
    char *visited = CreateString(nodes); /* Vector de vizitati */

    /* Initializez vectorul de vizitati cu valoarea fals(0) */
    int i;
    for (i = 0; i < nodes; ++i) {
        visited[i] = 0;
    }

    /* Introduc noduri in lista ciclului pana cand nodul pe care vreau sa
       in introduc se gaseste deja in lista */
    while (!visited[start]) {
        visited[start] = 1;
        AddToList(&list, start);

        /* Setez nodul urmator ca fiind predecesorul celui curent */
        start = pred[start];
    }
    return list;
}

ListNode* FindNegativeCycle(GraphNode *graph, int nodes, int start)
{
    float *costs = FloatVector(nodes, INFINITE);
    int *predecessors = IntVector(nodes, -1);
    int *times_relaxed = IntVector(nodes, 0);
    char has_negative_cycle = 0;

    Queue queue = (Queue){NULL, NULL};
    AddToQueue(&queue, start);
    costs[start] = 0; /* Costul pana in nodul de start este 0 */

    while (queue.left != NULL) {
        start = PopQueue(&queue);

        /* Daca nodul curent a fost relaxat de cel putin nodes ori (numarul de
           noduri ale grafului), el face parte dintr-un ciclu de cost negativ */
        ++times_relaxed[start];
        if (times_relaxed[start] >= nodes) {
            has_negative_cycle = 1;
            break; /* Ies fortat din while pentru a reconstrui ciclul. */
        }

        /* Actualizez costurile tuturor vecinilor nodului curent. */
        EdgeListNode *it = graph[start].edges;
        while (it != NULL) {
            int next = it->node;
            float new_cost = costs[start] + it->cost;

            /* Verific daca noul cost este mai bun. */
            if (Smaller(new_cost, costs[next])) {
                costs[next] = new_cost;
                predecessors[next] = start;
                AddToQueue(&queue, next);
            }
            it = it->next;
        }
    }

    /* Daca exista vreun ciclu de cost negativ, while-ul a fost oprit in timp ce
       in coada se gasesc inca elemente. De aceea, ea trebuie golita manual. */
    EmptyQueue(&queue);

    if (!has_negative_cycle) {
        return NULL;
    }
    return RetraceCycle(predecessors, costs, nodes, start);
}