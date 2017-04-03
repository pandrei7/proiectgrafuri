#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define STRING_LIMIT 5000
#define INFINITE (1 << 30)
#define EPSILON 0.001

typedef struct IntFloatPair
{
    int first;
    float second;
} IntFloatPair;

char* CreateString(int size);
void ReadLine(char *s, int limit, FILE *fin);

int* IntVector(int size, int init_value);
float* FloatVector(int size, float init_value);

int Smaller(float a, float b);
int Equal(float a, float b);

#endif // UTIL_H