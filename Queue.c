#include "Queue.h"
#include <stdlib.h>

QueueNode* CreateQueueNode(int value)
{
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    *new_node = (QueueNode){value, NULL};
    return new_node;
}

void AddToQueue(Queue *queue, int value)
{
    QueueNode *new_node = CreateQueueNode(value);
    if (queue->left == NULL) {
        queue->left = queue->right = new_node;
    } else {
        queue->right->next = new_node;
        queue->right = new_node;
    }
}

int PopQueue(Queue *queue)
{
    if (queue->left == NULL) {
        return -1;
    }

    QueueNode *to_delete = queue->left;
    queue->left = to_delete->next;

    int value = to_delete->value;
    free(to_delete);
    return value;
}

void EmptyQueue(Queue *queue)
{
    while (queue->left != NULL) {
        PopQueue(queue);
    }
}