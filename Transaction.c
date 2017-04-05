#include "Transaction.h"
#include <stdlib.h>

/* Functie ce creeaza un nou nod si ii atribuie valoarea value */
TransactionListNode* CreateTransactionListNode(Transaction value)
{
    TransactionListNode *new_node =
         (TransactionListNode*)malloc(sizeof(TransactionListNode));

    (*new_node) = (TransactionListNode){value, NULL};
    return new_node;
}

void AddTransaction(TransactionListNode **list, Transaction value)
{
    TransactionListNode *new_node = CreateTransactionListNode(value);
    /* Tranzactia este adaugata la inceputul listei (la stanga) */
    new_node->next = (*list);
    (*list) = new_node;
}

void FreeTransactionList(TransactionListNode **list)
{
    /* Nodurile sunt eliminate "de la stanga la dreapta" */
    while ((*list) != NULL) {
        TransactionListNode *to_delete = (*list);
        (*list) = to_delete->next;
        free(to_delete);
    }
}

TransactionListNode* ReverseList(TransactionListNode *list)
{
    /* Daca lista are cel mult un nod, lista ramane neschimbata */
    if (list == NULL || list->next == NULL) {
        return list;
    }

    /* Apelez recursiv functia pentru a inversa continuarea listei */
    TransactionListNode *root = ReverseList(list->next);

    /* Leg nodul list de lista inversata */
    list->next->next = list;
    list->next = NULL;
    return root;
}
