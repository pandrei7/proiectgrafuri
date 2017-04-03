#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode
{
    int value;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *left, *right;
} Queue;

void AddToQueue(Queue *queue, int value);
int PopQueue(Queue *queue);
void EmptyQueue(Queue *queue);

#endif // QUEUE_H