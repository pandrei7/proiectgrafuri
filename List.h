#ifndef LIST_H
#define LIST_H

/* Structura ce reprezinta nodul unei liste simplu inlantuite alocate dinamic */
typedef struct ListNode
{
    int value;
    struct ListNode *next;
} ListNode;

/* Functie ce adauga un nod nou cu valoare value la inceputul listei list */
void AddToList(ListNode **list, int value);

/* Functie ce elibereaza memoria ocupata de lista list */
void FreeList(ListNode **list);

#endif // LIST_H