#ifndef QUEUE_H
#define QUEUE_H

/* Structura ce reprezinta un nod al unei cozi alocate dinamic */
typedef struct QueueNode
{
    int value;
    struct QueueNode *next;
} QueueNode;

/* Structura ce reprezinta o coada alocata dinamic.
   Structura contine cate un pointer catre fiecare capat al cozii. */
typedef struct Queue
{
    QueueNode *left, *right;
} Queue;

/* Functie ce adauga un nou nod cu valoarea value la inceputul cozii queue */
void AddToQueue(Queue *queue, int value);

/* Functie ce elimina primul nod din coada queue si ii returneaza valoarea */
int PopQueue(Queue *queue);

/* Functie ce elibereaza memoria ocupata de coada queue */
void EmptyQueue(Queue *queue);

#endif // QUEUE_H