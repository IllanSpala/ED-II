#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 20

void bubbleSort(int array[], int size) { // to order
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j]; // swaping
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }    
}

int binarySearch(int array[], int size, int target){ // to find
    int left = 0;
    int right = size - 1;
    
    while (left <= right){
        int mid = left + (right - left) / 2;
        
        if (array[mid] == target){
            return mid; // encontrei meu valor no meio exato;
        }
        
        if(array[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1; 
        }
    }
    return -1; // não achei
}


int main() {
    int array[ARRAY_SIZE], num;
    char escolha[4]; 
    
    srand(time(NULL));
    
    // Generate and print initial array
    printf("Array original: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
        printf("%d|", array[i]);
    }
    
    // Get user input
    printf("\nDeseja ordenar o array? (sim/nao): ");
    scanf("%3s", escolha);  // Read up to 3 characters
    
    // Compare strings properly
    if(strcmp(escolha, "sim") == 0) {
        bubbleSort(array, ARRAY_SIZE);
        
        printf("Array ordenado: ");
        for(int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d|", array[i]);
        }
        
        printf("\nQual numero deseja encontrar? ");
        scanf("%d", &num);
        
        int resultado = binarySearch(array, ARRAY_SIZE, num);
        
        if(resultado != -1){
            printf("\nNumero %d encontrado na posicao %d", num, resultado);
        } else {
            printf("\nNumero %d não encontrado no array", num);
        }
        
    } else {
        printf("Saindo, obg!");
    }
    
    return 0;
}