#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printingStrying(char *string){
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

void computePrefixFunction(const char *pattern, int *prefixTable){
    int patternLenght = strlen(pattern);
    prefixTable[0] = 0;
    int lenght = 0;
    for(int i =1; i <patternLenght; ){
        if(pattern[i] == pattern[lenght]){
            lenght++;
            prefixTable[i] = lenght;
            i++;
        }else{
            if(lenght != 0){
                lenght = prefixTable[lenght-1];
            }else{
                prefixTable[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *word, char *pattern){
    int wordLenght = strlen(word);
    int patternLenght = strlen(pattern);
    int *prefixTable = (int *)malloc(patternLenght * sizeof(int));
    computePrefixFunction(pattern, prefixTable);
    int i = 0;
    int j = 0;

    while(i < wordLenght){
        if(pattern[j] == word[i]){
            i++;
            j++;
        }
        if(j == patternLenght){
            printf("Pattern found at index %d\n", i - j);
            j = prefixTable[j - 1];
        } else if (i < wordLenght && pattern[j] != word[i]){
            if (j != 0){
                j = prefixTable[j-1];
            }else{
                i++;
            }
        }
    }
    free(prefixTable);
}

int main()
{
    char word[100];
    char pattern[100];
    
    printf("Type ur word, after that type the pattern u want to find! \nWORD: ");
    scanf("%s", word);
    printingStrying(word);
    printf("\nPATTERN:\n");
    scanf("%s", pattern);
    printf("\n");
    
    KMPSearch(word, pattern);
    
    return 0;
}