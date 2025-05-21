/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int array[], int size, int target){
    int left = 0;
    int right = size -1;
    
    while(left<=right){
        int mid = left + (right - left) / 2;
        
        if(array[mid] == target){
            return mid; // target no meio exato
        }else if(array[mid] < target){
            left = mid + 1; // procura a metade a direita    
        }else{
            right = mid - 1; // procure a metade a esquerda
        }
    }
    return -1; // target não foi encontrado
}

int main()
{
    int array[] = {10, 15, 20, 25, 30, 35, 40, 45};
    int found;
    int size = sizeof(array) / sizeof(int);
    
    printf("Type the number u want to search:");
    scanf("%d", &found);
    
    for(int i = 0 ; i < size; i++){
        if(array[i] == found){
            printf("number founded, number of STEPS: %d", i);
        }
    }
    
    printf("\nNow doing bynary search: ");
    int resultado = buscaBinaria(array, size, found);
    
    if(resultado != -1){
        printf("Element found at %d", resultado);
    }else{
        printf("Element not found!\n");    
    }
    
/* teriamos como pior caso em busca binaria caso algum
    elemento fosse o de qualquer extremidade, e melhor caso
    qualquer elemento que estivesse exatamente no meio do 
    array, já na busca sequencial teriamos como pior caso
    se o elemento estivesse no final do array, e melhor caso
    no indice 0.
*/
    return 0;
}
