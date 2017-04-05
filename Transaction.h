#ifndef TRANSACTION_H
#define TRANSACTION_H

/* Structura ce reprezinta o tranzactie.
   node1 este indicele nodului care transfera o suma de bani,
   node2 este destinatarul, iar sum este suma transferata */
typedef struct Transaction
{
    int node1, node2;
    float sum;
} Transaction;

/* Structura ce reprezinta un nod al unei liste de tranzactii alocata dinamic */
typedef struct TransactionListNode
{
    Transaction value;
    struct TransactionListNode *next;
} TransactionListNode;

/* Functie ce adauga tranzactia value in lista list */
void AddTransaction(TransactionListNode **list, Transaction value);

/* Functie ce elibereaza memoria ocupata de lista list */
void FreeTransactionList(TransactionListNode **list);

/* Functie ce inverseaza lista list (sensul muchiilor) si returneaza
   adresa nodului de inceput al noii liste */
TransactionListNode* ReverseList(TransactionListNode *list);

#endif // TRANSACTION_H