#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/* Limita pentru lungimea unui sir de caractere */
#define STRING_LIMIT 5000

/* O constanta foarte mare */
#define INFINITE (1 << 30)

/* Constanta folosita pentru compararea numerelor cu zecimale */
#define EPSILON 0.001

/* Structura ce contine o variabila de tip int si una de tip float */
typedef struct IntFloatPair
{
    int first;
    float second;
} IntFloatPair;

/* Functie ce aloca un sir de caractere de lungime egala cu size */
char* CreateString(int size);

/* Functie ce citeste un sir de caractere din fisierul fin si elimina
   caracterul '\n' de la final (daca exista) */
void ReadLine(char *s, int limit, FILE *fin);

/* Functie ce aloca un vector de int-uri de lungime size si initializeaza
   fiecare valoare cu init_value */
int* IntVector(int size, int init_value);

/* Functie ce aloca un vector de float-uri de lungime size si initializeaza
   fiecare valoare cu init_value */
float* FloatVector(int size, float init_value);

/* Functie ce verifica daca parametrii de tip float a si b sunt egali */
int Equal(float a, float b);

/* Functie ce verifica daca parametrul a este mai mic decat b */
int Smaller(float a, float b);

#endif // UTIL_H