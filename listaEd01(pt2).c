#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 256 

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
    int comparisons = 0;
    
    for(i = 0; i <= sizeText - sizePattern; i++){
        for(j = 0; j < sizePattern; j ++){
            comparisons++;
            if(text[i + j] != pattern[j]){
                break; // caracter isnt the same
            }
        } 
        if(j == sizePattern){
            printf("\nPattern found at position %d (comparisons = %d)", i, comparisons);
        }
    }
}

// KMP SEARCH AREA (COMPUTE PREFIX TABLE AND THE KMP ALGORYTHM)

void computeLPS(char *pattern, int sizePattern, int *lps){ // LPS = LONGEST PROPER PREFIX
    int len = 0; // size of the last longer prefix sufix
    lps[0] = 0; // first index its always 0 on the TABLE
   
    
    int i = 1;
    while (i < sizePattern){
        if(pattern[i]== pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!= 0){
                len = lps[len-1]; // it goes 1 step back but dont come back to the begginning
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(char *text, char *pattern){
    int sizePattern = strlen(pattern);
    int sizeText = strlen(text);

    //malloc size for LPS TABLE
    int *lps = (int *)malloc(sizePattern * sizeof(int)); 
    
    //Pre-process the pattern (make the LPS TABLE)
    computeLPS(pattern, sizePattern, lps);
    
    int i = 0; //index for text[]
    int j = 0; //index for pattern[]
    int comparisons = 0;
    
    while(i < sizeText){
        comparisons++;
        if(pattern[j] == text[i]){
            i++;
            j++;
        }else{
            comparisons--;
        }
        
        if(j == sizePattern){
            printf("\nPattern found at position %d (comparisons = %d)", i - j, comparisons);
            j = lps[j-1];
        }else if(i <sizeText && pattern[j] != text[i]){
            if (j != 0){
                j = lps[j-1];        
            }else{
                i++;
            }
        }
    }
    free(lps); //free allocated memory
}


//BMH SEARCH AREA (PRE PROCESS THE BAD CHAR AND ALSO THE ALGORYTHM ITSELF)



int main(){
                
    char *text = "ABCDABDABDABCDABCDABC";
    char *pattern = "ABCDABC";
    
    printingString(pattern);
    buscaForcaBruta(text, pattern);
    
    printf("\n\nNow doing with kmpSearch Algorythm\n");
    
    KMPsearch(text, pattern);
    
    printf("\n\nNow doing with BMHSearch Algorythm\n");

    
    return 0;
}
