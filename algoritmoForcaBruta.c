#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printingString(char *string){
    int lenght = strlen(string);
    for (int i = 0; i < lenght; i++) {
        printf("┌─┐ ");
    }
    printf("\n");
    for (int i = 0; i < lenght; i++) {
        printf("│%c│ ", string[i]);
    }
    printf("\n");
    for (int i = 0; i < lenght; i++) {
        printf("└─┘ ");
    }
    printf("\n");
}


void buscaForcaBruta(char *text, char *pattern){
    int sizeText = strlen(text);
    int sizePattern = strlen(pattern);
    int i,j;
    
    for(i = 0; i <= sizeText - sizePattern; i++){
        for(j = 0; j < sizePattern; j ++){
            if(text[i + j] != pattern[j]){
                break; // caracter isnt the same
            }
        } 
        if(j == sizePattern){
            printf("\nPattern found at position %d", i);
        }
    }
}

int main(){
                
    char *text = "ABCDABDABDABCDABCDABC";
    char *pattern = "ABCDABC";
    
    printingString(pattern);
    buscaForcaBruta(text, pattern);
    return 0;
}