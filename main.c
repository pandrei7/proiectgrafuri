#include "Algorithms.h"
#include "Graph.h"
#include "List.h"
#include "Transaction.h"
#include "Util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Functie care afiseaza linii noi pentru a "goli" ecranul */
void CleanScreen()
{
    int i;
    for (i = 0; i < 50; ++i) {
        printf("\n");
    }
}

/* Functie care afiseaza meniul principal */
void PrintMenu()
{
    printf("Banca MFB 2017\n");
    printf("Program inutil administrare v2.20\n\n\n");

    printf("1. Verificare curs valutar (ajuta-ma sa ma imbogatesc)\n");
    printf("2. Gaseste ordinea tranzactiilor\n");
    printf("3. Ajutor\n");
    printf("0. Iesi\n");
}

/* Functie care afiseaza instructiuni legate de folosirea programului */
void ShowHelp()
{
    printf("---Ajutor-----\n");
    printf("Prima optiune iti permite sa verifici daca exista un mod de ");
    printf("a-ti inmulti banii\npe loc, doar cumparand valuta.\n\n");

    printf("Cea de-a doua optiune stabileste ordinea in care un set de ");
    printf("tranzactii financiarear trebui sa se petreaca pentru a nu ");
    printf("exista erori.\n\n");

    printf("Fiecare optiune din meniu are propriul fisier de intrare. Mai ");
    printf("multe informatii\nsunt disponibile la selectarea unei optiuni.\n");
    printf("Atentie! Nu modificati fisierele de intrare in timp ce programul ");
    printf("le proceseaza.\n");
    printf("Apasa Enter pentru a reveni.\n");
    scanf("%*c");
}

/* Functie care afiseaza instructiuni pentru optiunea 1 din meniu */
void ShowExchangeRatesHelp()
{
    printf("---Curs valutar-----\n");
    printf("Introdu datele in fisierul \"curs.txt\", astfel:\n");
    printf("Pe prima linie, n, numarul de unitati monetare.\n");
    printf("Pe urmatoarele n linii, numele unitatilor monetare, in ordine.\n");
    printf("Pe urmatoarele linii pana la finalul fisierului, triplete ");
    printf("de forma: x y cost,\nunde x si y sunt indicii ai unor unitati ");
    printf("monetare, iar cost este rata de schimb a unitatii x in y.\n");
    printf("Apasa Enter cand esti gata.\n");
    scanf("%*c");
}

/* Functie care executa optiunea 1 din meniu */
void RunExchangeRates()
{
    CleanScreen();
    ShowExchangeRatesHelp();

    FILE *fin = fopen("curs.txt", "r");
    int nodes, i, x, y;
    float cost;
    char str_aux[STRING_LIMIT];

    fscanf(fin, "%d%*c", &nodes);
    GraphNode *graph = CreateGraph(nodes);

    /* Citesc numele nodurilor din graf */
    for (i = 0; i < nodes; ++i) {
        ReadLine(str_aux, STRING_LIMIT, fin);
        SetNodeName(graph, i, str_aux);
    }

    /* Citesc muchiile grafului */
    while (fscanf(fin, "%d%d%f", &x, &y, &cost) != EOF) {
        AddEdge(graph, x - 1, y - 1, -log10f(cost));
        AddEdge(graph, y - 1, x - 1, -log10f(1 / cost));
    }
    fclose(fin);

    /* Semafor care imi va spune daca graful are vreun ciclu negativ */
    char has_negative_cycle = 0;

    /* Din moment ce functia FindNegative cycle gaseste doar cicluri "vizibile"
       din nodul de plecare transmis ca parametru, pentru a ma asigura ca nu
       exista cicluri negativem trebuie sa apelez functia din fiecare nod*/
    for (i = 0; i < nodes && !has_negative_cycle; ++i) {
        ListNode *res = FindNegativeCycle(graph, nodes, i);
        if (res != NULL) {
            printf("Am gasit un ciclu profitabil.\n");
            ListNode *it = res;

            while (it != NULL) {
                printf("%s ", graph[it->value].name);
                it = it->next;
                printf(" -> ");
            }
            printf("%s\n", graph[res->value].name);

            has_negative_cycle = 1;
            FreeList(&res);
        }
    }
    FreeGraph(&graph);

    if (!has_negative_cycle) {
        printf("Cursul valutare pare corect. Verifica mai tarziu.\n");
    }
    printf("Apasa Enter pentru a continua.\n");
    scanf("%*c");
}

/* Functie care afiseaza instructiuni pentru optiunea 2 din meniu */
void ShowTransactionsHelp()
{
    printf("---Tranzactii-----\n");
    printf("Introdu datele in fisierul \"tranzactii.txt\", astfel:\n");
    printf("Pe prima linie, n, numarul de conturi bancare.\n");
    printf("Pe urmatoarele n linii, numele conturilor bancare, in ordine.\n");
    printf("Pe urmatoarele linii pana la finalul fisierului, triplete ");
    printf("de forma: x y cost,\nunde x si y sunt indici ai unor conturi, ");
    printf("iar cost este suma transferata din\ncontul x in y.\n");
    printf("Apasa Enter cand esti gata.\n");
    scanf("%*c");
}

/* Functie care executa optiunea 2 din meniu */
void RunTransactions()
{
    CleanScreen();
    ShowTransactionsHelp();

    FILE *fin = fopen("tranzactii.txt", "r");
    int nodes, i, x, y;
    float cost;
    char str_aux[STRING_LIMIT + 5];

    fscanf(fin, "%d%*c", &nodes);
    GraphNode *graph = CreateGraph(nodes);

    /* Citesc numele nodurilor din graf */
    for (i = 0; i < nodes; ++i) {
        ReadLine(str_aux, STRING_LIMIT, fin);
        SetNodeName(graph, i, str_aux);
    }

    /* Citesc muchiile grafului */
    while (fscanf(fin, "%d%d%f", &x, &y, &cost) != EOF) {
        AddEdge(graph, x - 1, y - 1, cost);
    }
    fclose(fin);

    /* Daca reusesc sa sortez topologic graful, afisez tranzactiile in ordine.
       Altfel, graful nu este aciclic */
    TransactionListNode *res = TopoSort(graph, nodes);
    if (res == NULL) {
        printf("Graful nu este aciclic. Verifica tranzactiile manual.\n");
    } else {
        TransactionListNode *it = res;
        i = 0;

        while (it != NULL) {
            Transaction trans = it->value;
            it = it->next;

            ++i;
            printf("%d) %s -> %s : %.2f\n", i, graph[trans.node1].name,
                    graph[trans.node2].name, trans.sum);
        }
        FreeTransactionList(&res);
    }
    FreeGraph(&graph);

    printf("Apasa Enter pentru a continua.\n");
    scanf("%*c");
}

int main()
{
    int choice;
    do {
        CleanScreen();
        PrintMenu();

        scanf("%d%*c", &choice);
        if (choice == 1) {
            RunExchangeRates();
        } else if (choice == 2) {
            RunTransactions();
        } else if (choice == 3) {
            CleanScreen();
            ShowHelp();
        } else if (choice != 0) {
            /* Utilizatorul nu a introdus o optiune din meniu */
            printf("Indice optiune gresit: %d. ", choice);
            printf("Apasa Enter ca sa incerci din nou.\n");
            scanf("%*c");
        }
    } while (choice != 0); /* 0 este indicele optiune de iesire */

    printf("Programul se inchide...\n");
    return 0;
}
