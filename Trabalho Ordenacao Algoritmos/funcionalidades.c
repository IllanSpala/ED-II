#include "funcionalidades.h"
#include "algoritmos.h"

// vo limpa essa main

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


// IDEIA DE FAZER DOIS MENOS ENTAO TUDO ABAIXO AQUI É COMO SE FOSSE O PRIMEIRO MENU PORRA


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

    testarAlgoritmo("Quick Sort (Pivo Central)", "Aleatorio", quickSortCentro, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivo Central)", "Crescente", quickSortCentro, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivo Central)", "Decrescente", quickSortCentro, vetorDecrescente, tamanho, logFile);

    testarAlgoritmo("Quick Sort (Pivo no Fim)", "Aleatorio", quickSortFim, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivo no Fim)", "Crescente", quickSortFim, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Quick Sort (Pivo no Fim)", "Decrescente", quickSortFim, vetorDecrescente, tamanho, logFile);

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

    testarAlgoritmo("Heap Sort", "Aleatorio", heapSort, vetorAleatorio, tamanho, logFile);
    testarAlgoritmo("Heap Sort", "Crescente", heapSort, vetorCrescente, tamanho, logFile);
    testarAlgoritmo("Heap Sort", "Decrescente", heapSort, vetorDecrescente, tamanho, logFile);

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
    // Imprime no console (sempre)
    printf("Comparacoes: %lld\n", metricas.comparacoes);
    printf("Trocas: %lld\n", metricas.trocas);
    printf("Tempo gasto: %.10f segundos\n", tempoGasto);
    printf("-----------------------------\n\n");

    // Imprime no arquivo de log SÓ SE o arquivo foi passado
    if (logFile != NULL) {
        fprintf(logFile, "Comparacoes: %lld\n", metricas.comparacoes);
        fprintf(logFile, "Trocas: %lld\n", metricas.trocas);
        fprintf(logFile, "Tempo gasto: %.10f segundos\n", tempoGasto);
        fprintf(logFile, "-----------------------------\n\n");
    }
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

void rodaTUTO() {
    srand(time(NULL));
    int tamanhos_de_teste[] = {ARRAY_SIZE_1, ARRAY_SIZE_2, ARRAY_SIZE_3};
    const char* nomes_tamanhos[] = {"Pequeno", "Medio", "Grande"};

    while (1) { // Laço principal que garante o retorno ao menu
        int menuEscolha = 0;
        printf("\n\n=============== MENU PRINCIPAL ===============\n");
        printf("Bem-vindo ao Testador de Algoritmos de Ordenacao!\n");
        printf("1. Testar TODOS os algoritmos (gera log completo)\n");
        printf("2. Testar UM algoritmo especifico (para os 3 tamanhos)\n");
        printf("3. Sair do programa\n");
        printf("Digite sua escolha: ");
        scanf("%d", &menuEscolha);

        if (menuEscolha == 1) { // Roda tudo e gera log
            FILE* logFile = fopen("logFile.txt", "w");
            if (logFile == NULL) {
                fprintf(stderr, "Erro ao abrir o arquivo de log.\n");
                continue;
            }
            printf("Arquivo logFile.txt aberto para escrita.\n");

            for (int i = 0; i < 3; i++) {
                executarTestesParaTamanho(tamanhos_de_teste[i], logFile);
            }

            fclose(logFile);
            printf("\nTodos os testes foram concluidos. Resultados salvos com sucesso em 'logFile.txt'.\n");

        } else if (menuEscolha == 2) { // Teste unitário para os 3 tamanhos
            int menuEscolha = 0;
            printf("\n--- Teste Unitario: Escolha o Algoritmo ---\n");
            printf(" 1. Bubble Sort            |  2. Bubble Sort (Parada) |  3. Insertion Sort\n");
            printf(" 4. Insertion Binario      |  5. Selection Sort       |  6. Merge Sort\n");
            printf(" 7. Quick Sort (Centro)    |  8. Quick Sort (Fim)     |  9. Quick Sort (Mediana)\n");
            printf("10. Bucket Sort            | 11. Shell Sort           | 12. Radix Sort\n");
            printf("13. Heap Sort\n");
            printf("Digite sua escolha de algoritmo: ");
            scanf("%d", &menuEscolha);

            if (menuEscolha < 1 || menuEscolha > 13) {
                printf("Algoritmo invalido. Retornando ao menu principal.\n");
                continue;
            }

            // Laço para testar o algoritmo escolhido nos 3 tamanhos
            for (int i = 0; i < 3; i++) {
                int tamanho_atual = tamanhos_de_teste[i];
                // Aloca e gera vetores para este teste
                int *vetAleatorio = (int*) malloc(tamanho_atual * sizeof(int));
                int *vetCrescente = (int*) malloc(tamanho_atual * sizeof(int));
                int *vetDecrescente = (int*) malloc(tamanho_atual * sizeof(int));
                geraVetorAleatorio(vetAleatorio, tamanho_atual);
                geraVetorCrescente(vetCrescente, tamanho_atual);
                geraVetorDecrescente(vetDecrescente, tamanho_atual);

                printf("\n--- Testando com Vetor %s (%d elementos) ---\n", nomes_tamanhos[i], tamanho_atual);

                // O switch case direciona para o teste correto
                switch (menuEscolha) {
                    case 1: testarAlgoritmo("Bubble Sort", "Todos", bubbleSort, vetAleatorio, tamanho_atual, NULL); break;
                    case 2: testarAlgoritmo("Bubble Sort com Parada", "Todos", bubbleSorteComCriterioDeParada, vetAleatorio, tamanho_atual, NULL); break;
                    case 3: testarAlgoritmo("Insertion Sort", "Todos", insertionSort, vetAleatorio, tamanho_atual, NULL); break;
                    case 4: testarAlgoritmo("Insertion Sort Binario", "Todos", insertionSortBinario, vetAleatorio, tamanho_atual, NULL); break;
                    case 5: testarAlgoritmo("Selection Sort", "Todos", selectionSort, vetAleatorio, tamanho_atual, NULL); break;   
                    case 6: testarAlgoritmo("Merge Sort", "Todos", mergeSort, vetAleatorio, tamanho_atual, NULL); break;
                    case 7: testarAlgoritmo("Quick Sort (Pivo Central)", "Todos", quickSortCentro, vetAleatorio, tamanho_atual, NULL); break;
                    case 8: testarAlgoritmo("Quick Sort (Pivo no Fim)", "Todos", quickSortFim, vetAleatorio, tamanho_atual, NULL); break;
                    case 9: testarAlgoritmo("Quick Sort (Mediana de 3)", "Todos", quickSortMediana, vetAleatorio, tamanho_atual, NULL); break;
                    case 10: testarAlgoritmo("Bucket Sort", "Todos", bucketSort, vetAleatorio, tamanho_atual, NULL); break;
                    case 11: testarAlgoritmo("Shell Sort", "Todos", shellSort, vetAleatorio, tamanho_atual, NULL); break;
                    case 12: testarAlgoritmo("Radix Sort", "Todos", radixSort, vetAleatorio, tamanho_atual, NULL); break;
                    case 13: testarAlgoritmo("Heap Sort", "Todos", heapSort, vetAleatorio, tamanho_atual, NULL); break;
                }

                free(vetAleatorio);
                free(vetCrescente);
                free(vetDecrescente);
            }

        } else if (menuEscolha == 3) {
            printf("Encerrando o programa.\n");
            break; // Sai do laço while(1)
        } else {
            printf("Escolha invalida. Tente novamente.\n");
        }
    }
}
