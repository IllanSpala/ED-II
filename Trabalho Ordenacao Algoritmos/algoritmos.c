#include "algoritmos.h"

typedef struct No { // para usar no bucketSort 
    int valor;
    struct No* proximo;
} No;



Metricas bubbleSort(int vetor[], int tamanho){
    Metricas metricas = {0,0}; // inicializei as métricas
    int i, j, temp;

    for( i = 0; i < tamanho -1; i++){ // loop externo
        for( j = 0; j < tamanho - 1 - i; j++){ // loop interno
            metricas.comparacoes++; // incrementa a comparação
            if(vetor[j] > vetor[j+1]){
                // aqui ocorre a troca dos elementos
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                metricas.trocas++; // incrementa a troca
            }
        }
    }
    return metricas; // retorna as métricas
}

Metricas bubbleSorteComCriterioDeParada(int vetor[], int tamanho){
    Metricas metricas = {0,0}; // inicializei as métricas
    int i, j, temp;
    int trocou; // boolean para verificar se houve troca mas não é boolean 
    
    for ( i = 0; i < tamanho - 1; i++){
        trocou = 0; // falso aka 0
        for ( j = 0; j < tamanho - 1 - i; j++){
            metricas.comparacoes++; // incrementa a comparação
            if(vetor[j] > vetor[j+1]){
                // aqui ocorre a troca dos elementos
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                trocou = 1; // verdadeiro aka 1
                metricas.trocas++; // incrementa a troca
            }
        }
        // Se não houve troca, o vetor já está ordenado
        if (trocou == 0){
            return metricas; // sai da função
        }
    }
    return metricas; // retorna as métricas
}

Metricas insertionSort(int vetor[], int tamanho){
    Metricas metricas = {0,0}; 
    int i, j, temp; 

    for (i = 1; i < tamanho; i++){
        temp = vetor[i]; // guardei o elemento atual
        j = i - 1;

            while(j >= 0 && (metricas.comparacoes++, vetor[j] > temp)){
                vetor[j+1] = vetor[j]; // move o elemento maior uma posição à frente
                metricas.trocas++; // incrementa a troca
                j--; // decrementa o índice j
            }

        vetor[j + 1] = temp; // colocou o elemento atual na posição correta
        if(i != j + 1) { // se houve troca
            metricas.trocas++; // incrementa a troca
        }
    }
    return metricas; // retorna as métricas
}

Metricas insertionSortBinario(int vetor[], int tamanho){
    Metricas metricas = {0,0};
    int i, j, temp, left, right, mid;

    for(i = 1; i < tamanho; i++){
        temp = vetor[i];
        left = 0;
        right = i - 1;
        
        while(left <= right){
            metricas.comparacoes++; // incrementa a comparação
            mid = left + (right - left) / 2; // calcula o meio

            if(temp < vetor[mid]){
                right = mid - 1; // procura na esquerda
            } else{
                left = mid + 1; // procura na direita
            }
        }

        // AGORA É DESLOCAR ESSA PORRA

        for(j = i - 1; j >= left; j--){
            vetor[j + 1] = vetor[j]; // move o elemento maior uma posição à frente
            metricas.trocas++; // incrementa a troca
        }

        // DESLOCAR O TEMP PARA POSICAO CORRETA
        vetor[left] = temp; // coloca o elemento atual na posição correta

        if (i != left){
            metricas.trocas++; // incrementa a troca
        }      
    }
    return metricas; // retorna as métricas
}

Metricas selectionSort(int vetor[], int tamanho){
    Metricas metricas = {0, 0};
    int i, j, minIndex, temp;

    for(i = 0; i < tamanho - 1; i++){
        minIndex = i; // temos o primeiro indice supostamente como menor elemento
        for(j = i + 1; j < tamanho; j++){
            metricas.comparacoes++; // incrementa a comparação
            if(vetor[j] < vetor[minIndex]){
                minIndex = j; // atualiza o índice do menor elemento
            }
        }
        if(minIndex != i){ // se o menor elemento não é o atual
            temp = vetor[i];
            vetor[i] = vetor[minIndex]; // troca os elementos
            vetor[minIndex] = temp;
            metricas.trocas++; // incrementa a troca
    }
  }
    return metricas; // retorna as métricas
}

static Metricas merge(int vetor[], int inicio, int meio, int fim){
    Metricas metricas = {0, 0};
    int i, j, k;
    int n1 = meio - inicio + 1; // subvetor esquerdo
    int n2 = fim - meio; // subvetor direito

    int* L = (int*)malloc(n1 * sizeof(int)); // aloca o subvetor esquerdo
    int* R = (int*)malloc(n2 * sizeof(int)); // aloca o subvetor direito

    for (i = 0; i < n1; i++){
        L[i] = vetor[inicio + i]; // copia o subvetor esquerdo
        metricas.trocas++; // incrementa a troca
    }
    for(j = 0; j < n2; j++){
        R[j] = vetor[meio + 1 + j]; // copia o subvetor direito
        metricas.trocas++; // incrementa a troca
    }

    //reset nos indices
    i = 0;
    j = 0;
    k = inicio; // inicial do vetor intercalado

    //intercalando os vetores temporarios nos originais 
    while(i < n1 && j < n2){
        metricas.comparacoes++; // incrementa a comparação
        if(L[i] <= R[j]){
            vetor[k] = L[i]; // coloca o menor elemento no vetor original
            i++;
        } else {
            vetor[k] = R[j]; // coloca o menor elemento no vetor original
            j++;
        }
        metricas.trocas++; 
        k++;
    }

    // Copia os elementos restantes do subvetor esquerdo, se houver
    while(i < n1){
        vetor[k] = L[i];
        metricas.trocas++;
        i++;
        k++;
    }

    // Copia os elementos restantes do subvetor direito, se houver
    while(j < n2){
        vetor[k] = R[j];
        metricas.trocas++;
        j++;
        k++;
    }

    //libera memoria alocada
    free(L);
    free(R);

    return metricas; // retorna as métricas
}

static Metricas mergeSortRecursivo(int vetor[], int inicio, int fim){
    Metricas metricas_total = {0, 0};
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2; // encontra o meio

        // Chama recursivamente para a metade esquerda
        Metricas metricas_esquerda = mergeSortRecursivo(vetor, inicio, meio);
        Metricas metricas_direita = mergeSortRecursivo(vetor, meio + 1, fim);

        // Intercala os dois subvetores
        Metricas metricas_intercalacao = merge(vetor, inicio, meio, fim);

       //soma as metricas
        metricas_total.comparacoes = metricas_esquerda.comparacoes + metricas_direita.comparacoes + metricas_intercalacao.comparacoes;
        metricas_total.trocas = metricas_esquerda.trocas + metricas_direita.trocas + metricas_intercalacao.trocas;
    }
    return metricas_total; // retorna as métricas totais
}

Metricas mergeSort(int vetor[], int tamanho){ // funciona como um codificador, para int vetor[] e int tamanho
    return mergeSortRecursivo(vetor, 0, tamanho - 1); // chama a função recursiva
}

static void trocar(int* a, int* b, Metricas* metricas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    metricas->trocas++;
}

static int particionar(int vetor[], int inicio, int fim, Metricas* metricas) {
    int pivo = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        metricas->comparacoes++;
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j], metricas);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim], metricas);
    return (i + 1);
}

static void quickSortRecursivo(int vetor[], int inicio, int fim, Metricas* metricas, int tipoPivo) {
    // CORREÇÃO: Trocamos o 'if' por um laço 'while' para otimizar a recursão
    while (inicio < fim) {
        if (tipoPivo == 2) { 
            int meio = inicio + (fim - inicio) / 2;
            metricas->comparacoes += 2; 
            if (vetor[inicio] > vetor[meio]) trocar(&vetor[inicio], &vetor[meio], metricas);
            if (vetor[inicio] > vetor[fim]) trocar(&vetor[inicio], &vetor[fim], metricas);
            if (vetor[meio] > vetor[fim]) trocar(&vetor[meio], &vetor[fim], metricas);
            trocar(&vetor[meio], &vetor[fim], metricas);
        } else if (tipoPivo == 0) { 
            int meio = inicio + (fim - inicio) / 2;
            trocar(&vetor[meio], &vetor[fim], metricas);
        }
        
        int pi = particionar(vetor, inicio, fim, metricas);

        // fazemos a chamada recursiva apenas para a menor partição e o laço 'while' cuida da maior.
        
        if ((pi - inicio) < (fim - pi)) { // Se a partição da esquerda for menor
            quickSortRecursivo(vetor, inicio, pi - 1, metricas, tipoPivo);
            inicio = pi + 1; // Continua o laço para a partição da direita (maior)
        } else { // Se a partição da direita for menor (ou igual)
            quickSortRecursivo(vetor, pi + 1, fim, metricas, tipoPivo);
            fim = pi - 1; // Continua o laço para a partição da esquerda (maior)
        }
    }
}

Metricas quickSortCentro(int vetor[], int tamanho) {
    Metricas metricas = {0, 0};
    quickSortRecursivo(vetor, 0, tamanho - 1, &metricas, 0); // Pivô Central
    return metricas;
}

Metricas quickSortFim(int vetor[], int tamanho) {
    Metricas metricas = {0, 0};
    quickSortRecursivo(vetor, 0, tamanho - 1, &metricas, 1); // Pivô Final
    return metricas;
}

Metricas quickSortMediana(int vetor[], int tamanho) {
    Metricas metricas = {0, 0};
    quickSortRecursivo(vetor, 0, tamanho - 1, &metricas, 2); // Mediana de 3
    return metricas;
}

static No* inserirNoBalde(No* cabeca, int valor, Metricas* metricas) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) exit(1); // Falha na alocação

    novoNo->valor = valor;
    metricas->trocas++; // Conta a movimentação do vetor para a estrutura do balde

    // Se o balde está vazio ou o novo elemento deve ser o primeiro
    if (cabeca == NULL || (metricas->comparacoes++, cabeca->valor >= valor)) {
        novoNo->proximo = cabeca;
        return novoNo;
    }

    // Procura a posição correta para inserir na lista
    No* atual = cabeca;
    while (atual->proximo != NULL && (metricas->comparacoes++, atual->proximo->valor < valor)) {
        atual = atual->proximo;
    }

    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;

    return cabeca;
}

Metricas bucketSort(int vetor[], int tamanho) {
    Metricas metricas = {0, 0};
    if (tamanho <= 0) return metricas;

    // passo 1 Encontrar o valor máximo no vetor (necessário para a distribuição)
    int maxValor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maxValor) {
            maxValor = vetor[i];
        }
    }
    // Adiciona 1 para evitar divisão por zero se o maxValor for 0
    maxValor++;

    // passo 2 Criar os baldes. Usaremos 'tamanho' como o número de baldes.
    int num_baldes = tamanho;
    No** baldes = (No**)calloc(num_baldes, sizeof(No*));
    if (!baldes) exit(1); // Garante que a memória foi alocada

    // passo 3 Distribuir (Scatter) os elementos do vetor nos baldes
    for (int i = 0; i < tamanho; i++) {
        // Fórmula de distribuição para mapear o valor ao índice do balde
        int indice_balde = (int)(((double)vetor[i] / maxValor) * num_baldes);
        
        // Insere o elemento no balde correto de forma ordenada
        baldes[indice_balde] = inserirNoBalde(baldes[indice_balde], vetor[i], &metricas);
    }

    // passo 4 Juntar (Gather) os elementos dos baldes de volta no vetor original
    int indice_vetor = 0;
    for (int i = 0; i < num_baldes; i++) {
        No* no_atual = baldes[i];
        while (no_atual != NULL) {
            // Copia o valor de volta para o vetor principal
            vetor[indice_vetor++] = no_atual->valor;
            metricas.trocas++; // Conta a movimentação do balde de volta para o vetor

            // Guarda o ponteiro atual e avança para o próximo, antes de liberar a memória
            No* temp = no_atual;
            no_atual = no_atual->proximo;
            free(temp); // Libera a memória do nó que acabamos de processar
        }
    }

    free(baldes); // Libera a memória do array principal de baldes
    return metricas;
}

Metricas shellSort(int vetor[], int tamanho){
    Metricas metricas = {0, 0};
    int gap, i, j, temp;

    // Inicia o gap com metade do tamanho e o reduz pela metade a cada iteração
    for(gap = tamanho / 2; gap > 0; gap /= 2){
        // Faz uma passagem de insertion sort "distanciado" para este gap.
        for(i = gap; i < tamanho; i++){
            // 1. Salva o elemento atual
            temp = vetor[i]; 
            j = i;

            // 2. Desloca elementos anteriores (no intervalo do gap) que são maiores
            while(j >= gap && (metricas.comparacoes++, vetor[j - gap] > temp)){
                vetor[j] = vetor[j - gap];
                metricas.trocas++;
                j -= gap; 
            }
            
            // 3. Insere o elemento salvo na sua posição correta.
            vetor[j] = temp;
            if(i != j) {
                metricas.trocas++;
            }
        }
    }
    
    return metricas;
}

Metricas radixSort(int vetor[], int tamanho) {
    Metricas metricas = {0, 0};
    if (tamanho <= 0) return metricas;

    int i;
    int max = vetor[0];

    for (i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
   
        int* output = (int*) malloc(tamanho * sizeof(int));
        if (output == NULL) {
            fprintf(stderr, "ERRO: Falha ao alocar 'output' no RadixSort.\n");
            return metricas;
        }
        int count[10] = {0};

        for (i = 0; i < tamanho; i++) {
            count[(vetor[i] / exp) % 10]++;
        }

        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (i = tamanho - 1; i >= 0; i--) {
            output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
            metricas.trocas++; 
            count[(vetor[i] / exp) % 10]--;
        }

        for (i = 0; i < tamanho; i++) {
            vetor[i] = output[i];
            metricas.trocas++;
        }
        
        free(output);
    }
    return metricas;
}

static void criaHeap(int vetor[], int inicio, int tamanho, Metricas* metrica){
    int aux = vetor[inicio];
    int j = inicio * 2 + 1 ; // aka filho da esquerda

    while( j < tamanho ){
        if(j + 1 < tamanho && (metrica->comparacoes++, vetor[j] < vetor[j+1])){
            // se o filho da esquerda for menor que o da direita
            j++; // vai pro filho da direita
        }
        if((metrica->comparacoes++, aux < vetor[j])){
            vetor[inicio] = vetor[j]; // troca pai pelo filho
            inicio = j; // atualiza o pai
            j = inicio * 2 + 1; // atualiza o filho // calcula o indice no proximo filho 
        }else{
            j = tamanho; // sai do loop
        }
    }
    vetor[inicio] = aux; // coloca o pai na posição correta
    metrica->trocas++; // incrementa a troca
}

Metricas heapSort(int vetor[], int tamanho){
    Metricas metricas = {0, 0};
    int i = 0;
    // inicializa as metricas // a heap
    if (tamanho <= 0) return metricas; // se o tamanho for menor ou igual a zero, retorna as metricas
    // Constrói a heap (max heap)
    
    for(i = (tamanho - 1) / 2; i >= 0; i--){
        criaHeap(vetor, i, tamanho, &metricas); // cria a heap
    }

    for(i = tamanho - 1; i > 0; i--){
        // Move o maior elemento (raiz) para o final do vetor
        trocar(&vetor[0], &vetor[i], &metricas);
        // Reconstroi a heap reduzida
        criaHeap(vetor, 0, i, &metricas);

    }
    return metricas; // retorna as métricas
} 


