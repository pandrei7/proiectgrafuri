#include "Queue.h"
#include <stdlib.h>

/* Functie ce creeaza un nou nod si ii atribuie valoarea value */
QueueNode* CreateQueueNode(int value)
{
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    *new_node = (QueueNode){value, NULL};
    return new_node;
}

void AddToQueue(Queue *queue, int value)
{
    QueueNode *new_node = CreateQueueNode(value);
    /* Noul nod este adaugat la finalul cozii (capatul din dreapta) daca
       aceasta exista */
    if (queue->left == NULL) {
        queue->left = queue->right = new_node;
    } else {
        queue->right->next = new_node;
        queue->right = new_node;
    }
}

int PopQueue(Queue *queue)
{
    /* Daca coada este deja goala, returnez o valoare speciala (-1) */
    if (queue->left == NULL) {
        return -1;
    }

    /* Elimin nodul din capatul stang al cozii */
    QueueNode *to_delete = queue->left;
    queue->left = to_delete->next;

    /* Salvez valoarea nodului inainte de a-l sterge */
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