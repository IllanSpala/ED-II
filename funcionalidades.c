#include "funcionalidades.h"
#include "algoritmos.h"


void IniciaHud(int vetorAleatorio[], int vetorCrescente[], int vetorDecrescente[], int tamanho, FILE* logFile){
    geraVetorAleatorio(vetorAleatorio, tamanho);
    printf(" *****************************************************\n");
    printf(" *********  --- VETOR ALEATORIO   GERADO ---  ******** \n ");

    fprintf(logFile, " *****************************************************\n");
    fprintf(logFile, " ********  --- VETOR ALEATORIO   GERADO ---  ******** \n ");

    geraVetorCrescente(vetorCrescente, tamanho);
    printf("*********  --- VETOR CRESCENTE   GERADO ---  ******** \n ");

    fprintf(logFile, "*********  --- VETOR CRESCENTE   GERADO ---  ******** \n ");
    
    geraVetorDecrescente(vetorDecrescente, tamanho);
    printf("*********  --- VETOR DECRESCENTE GERADO ---  ******** \n ");
    printf("*****************************************************\n");

    fprintf(logFile,"*********  --- VETOR DECRESCENTE GERADO ---  ******** \n ");
    fprintf(logFile,"*****************************************************\n");
}

void executarTestesParaTamanho(int tamanho, FILE* logFile){
    printf("\n==========================================================\n");
    printf("     INICIANDO CONJUNTO DE TESTES PARA N = %d     \n", tamanho);
    printf("==========================================================\n");
    
    fprintf(logFile, "\n==========================================================\n");
    fprintf(logFile, "     INICIANDO CONJUNTO DE TESTES PARA N = %d     \n", tamanho);
    fprintf(logFile, "==========================================================\n");

    int *vetorAleatorio, *vetorCrescente, *vetorDecrescente;
    vetorAleatorio = (int*) malloc(tamanho * sizeof(int));
    vetorCrescente = (int*) malloc(tamanho * sizeof(int));
    vetorDecrescente = (int*) malloc(tamanho * sizeof(int));

    if (vetorAleatorio == NULL || vetorCrescente == NULL || vetorDecrescente == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria para tamanho %d.\n", tamanho);
        return; 
    }
    
    IniciaHud(vetorAleatorio, vetorCrescente, vetorDecrescente, tamanho, logFile);
    
    testarAlgoritmo("Bubble Sort", "Aleatorio", bubbleSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Bubble Sort", "Crescente", bubbleSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Bubble Sort", "Decrescente", bubbleSort, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Bubble Sort com Parada", "Aleatorio", bubbleSorteComCriterioDeParada, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Bubble Sort com Parada", "Crescente", bubbleSorteComCriterioDeParada, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Bubble Sort com Parada", "Decrescente", bubbleSorteComCriterioDeParada, vetorDecrescente, tamanho,logFile);

    testarAlgoritmo("Insertion Sort", "Aleatorio", insertionSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Insertion Sort", "Crescente", insertionSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Insertion sort", "Decrescente", insertionSort, vetorDecrescente, tamanho, logFile);
    
    testarAlgoritmo("Insertion Sort Binario", "Aleatorio", insertionSortBinario, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Insertion Sort Binario", "Crescente", insertionSortBinario, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Insertion Sort Binario", "Decrescente", insertionSortBinario, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Selection Sort", "Aleatorio", selectionSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Selection Sort", "Crescente", selectionSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Selection Sort", "Decrescente", selectionSort, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Merge Sort", "Aleatorio", mergeSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Merge Sort", "Crescente", mergeSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Merge Sort", "Decrescente", mergeSort, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Quick Sort (Pivô Central)", "Aleatorio", quickSortCentro, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivô Central)", "Crescente", quickSortCentro, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivô Central)", "Decrescente", quickSortCentro, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Quick Sort (Pivô no Fim)", "Aleatorio", quickSortFim, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivô no Fim)", "Crescente", quickSortFim, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivô no Fim)", "Decrescente", quickSortFim, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Quick Sort (Mediana de 3)", "Aleatorio", quickSortMediana, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Mediana de 3)", "Crescente", quickSortMediana, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Mediana de 3)", "Decrescente", quickSortMediana, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Bucket Sort", "Aleatorio", bucketSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Bucket Sort", "Crescente", bucketSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Bucket Sort", "Decrescente", bucketSort, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Shell Sort", "Aleatorio", shellSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Shell Sort", "Crescente", shellSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Shell Sort", "Decrescente", shellSort, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Radix Sort", "Aleatorio", radixSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Radix Sort", "Crescente", radixSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Radix Sort", "Decrescente", radixSort, vetorDecrescente, tamanho, logFile);

    printf("\n==========================================================\n");
    printf("     FIM DO CONJUNTO DE TESTES PARA N = %d     \n", tamanho);
    printf("==========================================================\n");
    
    fprintf(logFile, "\n==========================================================\n");
    fprintf(logFile, "     FIM DO CONJUNTO DE TESTES PARA N = %d     \n", tamanho);
    fprintf(logFile, "==========================================================\n");

    free(vetorAleatorio);
    free(vetorCrescente);
    free(vetorDecrescente);
}


// Função auxiliar que gera UM número aleatório
static int numeroRand(int max) {
    if (max <= 0) return 1;
    return (rand() % max) + 1;
}

// Preenche um vetor com números aleatórios
void geraVetorAleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = numeroRand(tamanho);
    }
}

// Preenche um vetor com números em ordem crescente (1, 2, 3, ...)
void geraVetorCrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }
}

// Preenche um vetor com números em ordem decrescente (N, N-1, N-2, ...)
void geraVetorDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void printaVetor(int vetor[], int tamanho) {
   /* COMENTEI SAPORRA PRA PODER RODAR DE VDD
    printf("Vetor de tamanho %d: ", tamanho);
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
   */ 
}    

void printaResultado(Metricas metricas, double tempoGasto, FILE* logFile){
    printf("Comparacoes: %lld\n", metricas.comparacoes);
    printf("Trocas: %lld\n", metricas.trocas);
    printf("Tempo gasto: %.10f segundos\n", tempoGasto);
    printf("-----------------------------\n");
    printf("\n");

    fprintf(logFile, "Comparacoes: %lld\n", metricas.comparacoes);
    fprintf(logFile, "Trocas: %lld\n", metricas.trocas);
    fprintf(logFile, "Tempo gasto: %.10f segundos\n", tempoGasto);
    fprintf(logFile, "-----------------------------\n\n");
}

void testarAlgoritmo(const char* nomeAlgoritmo, const char* tipoVetor, Metricas (*funcaoSort)(int[], int), int vetor[], int tamanho, FILE* logFile){
    printf("-----------------------------\n");
    printf("Testando algoritmo: %s com vetor %s (%d caracteres)\n", nomeAlgoritmo, tipoVetor, tamanho);
    fprintf(logFile, "-----------------------------\n");
    fprintf(logFile, "Testando algoritmo: %s com vetor %s (%d caracteres)\n", nomeAlgoritmo, tipoVetor, tamanho);
    
    // A função printaVetor está comentada
    printaVetor(vetor, tamanho);

    int* vetorCopia = (int*) malloc(tamanho * sizeof(int));
    if (vetorCopia == NULL) {
        fprintf(stderr, "ERRO CRITICO: Falha ao alocar memoria para vetorCopia em testarAlgoritmo.\n");
        return; // Sai da função para evitar que o programa quebre.
    }
    memcpy(vetorCopia, vetor, tamanho * sizeof(int));

    // Marca o tempo de início
    clock_t tempoInicio = clock();
    
    // Chama a função de ordenação na CÓPIA
    Metricas metricas = funcaoSort(vetorCopia, tamanho);
    
    // Marca o tempo de fim
    clock_t tempoFim = clock();
    
    // Calcula o tempo gasto
    double tempoGasto = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    
    // Imprime as métricas e o tempo gasto
    printaResultado(metricas, tempoGasto, logFile);
    
    // libera memory
    free(vetorCopia);
}

