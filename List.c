#include "List.h"
#include <stdlib.h>

ListNode* CreateListNode(int value)
{
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    *new_node = (ListNode){value, NULL};
    return new_node;
}

void AddToList(ListNode **list, int value)
{
    ListNode *new_node = CreateListNode(value);
    if ((*list) != NULL) {
        new_node->next = (*list);
    }
    (*list) = new_node;
}

void FreeList(ListNode **list)
{
    while ((*list) != NULL) {
        ListNode *to_delete = (*list);
        (*list) = to_delete->next;
        free(to_delete);
    }
}