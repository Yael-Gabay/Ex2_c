#ifndef MY_MAT
#define MY_MAT

#include <stdio.h>
#define LEN 10
#define TRUE 1
#define FALSE 0

void initMat(int arr[][LEN]);
void FloydWarshallAlgo(int arr[][LEN]);
int min(int a, int b);
void hasRoute(int arr[][LEN]);
void shortPath(int arr[][LEN]);


#endif