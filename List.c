#include "List.h"
#include <stdlib.h>

/* Functie ce creeaza un nod nou si ii atribuie valoarea value */
ListNode* CreateListNode(int value)
{
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    *new_node = (ListNode){value, NULL};
    return new_node;
}

void AddToList(ListNode **list, int value)
{
    ListNode *new_node = CreateListNode(value);
    /* Daca lista mai are noduri, atasez new_node la inceputul acesteia */
    if ((*list) != NULL) {
        new_node->next = (*list);
    }
    (*list) = new_node;
}

void FreeList(ListNode **list)
{
    /* Eliberez fiecare nod din lista, "de la stanga la dreapta" */
    while ((*list) != NULL) {
        ListNode *to_delete = (*list);
        (*list) = to_delete->next;
        free(to_delete);
    }
}