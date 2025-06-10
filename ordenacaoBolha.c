#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//Illan de Souza Spala 10/06/2025
void ordenacaoBolha(int array[], int tamanho){
    if (tamanho < 1 ) return; // Se tamanho é menor que 1 não há o que ordenar;
    int i = 0;
    int j = 0;
        for(i = 0; i < tamanho - 1; i++){
            for( j = 0; j < tamanho - 1 - i; j++){
                if(array[j] > array[j+1]){
                    int temp = array[j]; // alocando maior no temp
                    array[j] = array[j+1]; // passando prox p trás
                    array[j+1] = temp;  // passando temp pro prox
                }
            }
        }
    printf("Total de interações: %d\n", i);
}

void ordenacaoBolhaComParada(int array[], int tamanho){
    if(tamanho < 1) return;
    int i = 0;
    int j = 0;
    
    bool houveTrocas;
    do{
        houveTrocas = false;
            for(i = 0; i < tamanho - 1; i++){
                for( j = 0; j < tamanho - 1 - i; j++){
                    if(array[j] > array[j+1]){
                        int temp = array[j]; // alocando maior no temp
                        array[j] = array[j+1]; // passando prox p trás
                        array[j+1] = temp;  // passando temp pro prox
                    }
                }
            }
    }while(houveTrocas);
    
    printf("Total de interações: %d\n", i);
}



void imprimeBonitin(int array[], int tamanho){
    int i = 0;
    
    // printando teto
    for(i = 0; i < tamanho; i++){
        printf("┌───┐ ");
    }
    
    printf("\n");
    
    //printando meio
    for(i = 0; i < tamanho; i++){
        printf("│%03d│ ", array[i]);
    }
    
    printf("\n");
    
    //printando base
    for(i = 0; i < tamanho; i++){
        printf("└───┘ ");
    }
    
    printf("\n");
}

void imprimeBonitin2(int array[], int tamanho){
    int i = 0;
    
    // printando teto com ASCII
    for(i = 0; i < tamanho; i++){
        printf("+---+ ");
    }
    printf("\n");
    
    //printando meio com ASCII
    for(i = 0; i < tamanho; i++){
        printf("|%03d| ", array[i]);
    }
    printf("\n");
    
    //printando base com ASCII
    for(i = 0; i < tamanho; i++){
        printf("+---+ ");
    }
    printf("\n\n");
}

int main()
{
    int array[] = {8, 3, 6, 5, 1, 2, 4, 10, 9, 7};
    int tamanho = sizeof(array) / sizeof(array[0]); // 4bits btw
    
    printf("**Array Original**\n");
    imprimeBonitin2(array, tamanho);
    
    printf("**Array ordenado**\n");
    ordenacaoBolha(array, tamanho);
    imprimeBonitin2(array,tamanho);
    
    printf("**COM PARADA**\n");
    ordenacaoBolhaComParada(array, tamanho);
    imprimeBonitin2(array,tamanho);
    return 0;
}