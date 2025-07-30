#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE_1 9999 // test value
#define ARRAY_SIZE_2 99999
#define ARRAY_SIZE_3 999999

// estrutura pra armazenar as métricas que serão usadas posteriormente nessa BOMBA
typedef struct{
    long long comparacoes;
    long long trocas;
} Metricas;



// area dos algoritmos
Metricas bubbleSort(int vetor[], int tamanho);
Metricas bubbleSorteComCriterioDeParada(int vetor[], int tamanho);

Metricas insertionSort(int vetor[], int tamanho);
Metricas insertionSortBinario(int vetor[], int tamanho);

Metricas selectionSort(int vetor[], int tamanho);

Metricas mergeSort(int vetor[], int tamanho);

Metricas quickSortCentro(int vetor[], int tamanho);
Metricas quickSortFim(int vetor[], int tamanho);
Metricas quickSortMediana(int vetor[], int tamanho);


Metricas bucketSort(int vetor[], int tamanho);

Metricas shellSort(int vetor[], int tamanho);

Metricas radixSort(int vetor[], int tamanho); 

Metricas heapSort(int vetor[], int tamanho);



#endif 