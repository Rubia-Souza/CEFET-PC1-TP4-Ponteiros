#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AMOUNT_CHARACTERS_READ 100000

char* findSubStringAddress(char reference[], const char subString[]);
void removeNewLine(char target[]);

int main() {
    char reference[MAX_AMOUNT_CHARACTERS_READ];

    printf("\nEscreva a string de referenência: ");
    fgets(reference, MAX_AMOUNT_CHARACTERS_READ, stdin);
    fflush(stdin);
    removeNewLine(reference);

    const size_t referenceSize = strlen(reference);
    char* subString = (char*) malloc(referenceSize * sizeof(char));
    printf("\nEscreva a substring que deve ser encontrada: ");
    fgets(subString, referenceSize, stdin);
    fflush(stdin);
    removeNewLine(subString);

    printf("\nO primeiro endereço da string referência: %X. Valor: %c.", &reference[0], reference[0]);
    
    char* firstSubstringAddress = findSubStringAddress(reference, subString);
    if(firstSubstringAddress == NULL) {
        printf("\nNão há ocorrencias da substring %s na referência %s.", subString, reference);
    }
    else {
        printf("\nO primeiro endereço da substring está em: %X. Valor: %c.", firstSubstringAddress, *firstSubstringAddress);
    }

    return 0;
}

char* findSubStringAddress(char reference[], const char subString[]) {
    const unsigned int totalMatchs = strlen(subString)-1;
    unsigned int matchCount = 0;
    int startMatchIndex = -1;

    for(int refIndex = 0, subIndex = 0; refIndex < strlen(reference); refIndex++) {
        if(totalMatchs == matchCount) {
            break;
        }

        if(reference[refIndex] == subString[subIndex]) {
            if(startMatchIndex == -1) {
                startMatchIndex = refIndex;
            }

            matchCount++;
            subIndex++;
        }
        else {
            matchCount = 0;
            subIndex = 0;
            startMatchIndex = -1;
        }
    }

    if(startMatchIndex == -1) {
        return NULL;
    }

    char* targetAddres = &reference[startMatchIndex];
    return targetAddres;
}

void removeNewLine(char target[]) {
    target[strcspn(target, "\n")] = '\000';
    return;
}
