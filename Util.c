#include "Util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CreateString(int size)
{
    return (char*)malloc(size * sizeof(char));
}

void ReadLine(char *s, int limit, FILE *fin)
{
    fgets(s, limit, fin);
    s[strcspn(s, "\r\n")] = '\0';
}

int* IntVector(int size, int init_value)
{
    int *vec = (int*)malloc(size * sizeof(int));
    int i;

    for (i = 0; i < size; ++i) {
        vec[i] = init_value;
    }
    return vec;
}

float* FloatVector(int size, float init_value)
{
    float *vec = (float*)malloc(size * sizeof(float));
    int i;

    for (i = 0; i < size; ++i) {
        vec[i] = init_value;
    }
    return vec;
}

int Equal(float a, float b)
{
    return (fabs(a - b) < EPSILON);
}

int Smaller(float a, float b)
{
    return (a < b) && !Equal(a, b);
}