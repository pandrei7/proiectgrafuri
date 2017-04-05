#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include "List.h"
#include "Transaction.h"

/* Functie care returneaza o lista (pointer catre primul nod al listei)
   de noduri ce alcatuiesc un ciclu de cost negativ in graful graph, vizibil
   din nodul start. Daca graful nu contine cicluri de cost negativ, functia
   returneaza NULL. Nodes este numarul de noduri ale grafului.
   Functia foloseste algoritmul Bellman-Ford pentru a detecta un ciclu de
   cost negativ. */
ListNode* FindNegativeCycle(GraphNode *graph, int nodes, int start);

TransactionListNode* TopoSort(GraphNode *graph, int nodes);

#endif // ALGORITHMS_H