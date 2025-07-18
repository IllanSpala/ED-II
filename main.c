#include "funcionalidades.h"
#include "algoritmos.h" 

int main() {
    srand(time(NULL));
    
    // Define os tamanhos que serão testados
    int tamanhos_de_teste[] = {ARRAY_SIZE_1, ARRAY_SIZE_2, ARRAY_SIZE_3};
    int num_testes = 3;

    // Abre o arquivo de log
    FILE* logFile = fopen("logFile.txt", "w");
    if (logFile == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de log.\n");
        return 1;
    }
    printf("Arquivo logFile.txt aberto para escrita.\n");

    // Laço principal que executa o conjunto de testes para cada tamanho
    for (int i = 0; i < num_testes; i++) {
        executarTestesParaTamanho(tamanhos_de_teste[i], logFile);
    }
    
    // Fecha o arquivo de log no final de tudo
    fclose(logFile);
    printf("\nTodos os testes foram concluidos. Resultados salvos com sucesso em 'logFile.txt'.\n");

    return 0;
}
