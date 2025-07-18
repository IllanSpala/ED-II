#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H
#include <stdio.h>
#include "algoritmos.h"



void IniciaHud(int vetAleatorio[], int vetCrescente[], int vetDecrescente[], int tamanho, FILE* logFile);

void executarTestesParaTamanho(int tamanho, FILE* logFile);

// Funções para gerar e preencher vetores
void geraVetorAleatorio(int vetor[], int tamanho);
void geraVetorCrescente(int vetor[], int tamanho);
void geraVetorDecrescente(int vetor[], int tamanho);

// Funções para imprimir
void printaVetor(int vetor[], int tamanho);
void printaResultado(Metricas metricas, double tempoGasto, FILE* logFile);
void testarAlgoritmo(const char* nomeAlgoritmo, const char* tipoVetor, Metricas (*funcaoSort)(int[], int), int vetor[], int tamanho, FILE* logFile);

#endif