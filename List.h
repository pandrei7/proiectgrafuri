#ifndef LIST_H
#define LIST_H

typedef struct ListNode
{
    int value;
    struct ListNode *next;
} ListNode;

void AddToList(ListNode **list, int value);
void FreeList(ListNode **list);

#endif // LIST_H