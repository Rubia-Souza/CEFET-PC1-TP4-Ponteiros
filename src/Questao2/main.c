#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_RANDOM_NUMBER_GENERATED 1
#define MAX_RANDOM_NUMBER_GENERATED 1000

void setStartSettings();

int* createVector(const unsigned int vectorSize);
void fillVector(unsigned int vector[], const unsigned int vectorSize);
bool vectorContains(const unsigned int vector[], const unsigned int vectorSize, const unsigned int number);
void printVector(const unsigned int vector[], const unsigned int vectorSize);

unsigned int** createAddressVector(unsigned int vector[], const unsigned int  vectorSize);
void printAddressVector(unsigned int* vector[], const unsigned int vectorSize);

void createNotRepeatedNumber(unsigned int vector[], const unsigned int index, const unsigned int vectorSize);
unsigned int createRandomNumber(const unsigned int min, const unsigned int max);

void insertionSort(unsigned int* vector[], const unsigned int vectorSize);

int main() {
    setStartSettings();

    unsigned int vectorSize = 0;
    printf("Digite o tamanho do vetor de inteiros positivos: ");
    scanf("%d", &vectorSize);

    unsigned int* vector = createVector(vectorSize);
    printVector(vector, vectorSize);

    unsigned int** addressVector = createAddressVector(vector, vectorSize);
    printAddressVector(addressVector, vectorSize);

    insertionSort(addressVector, vectorSize);
    printAddressVector(addressVector, vectorSize);

    return 0;
}

void setStartSettings() {
    srand(time(0));
    return;
}

int* createVector(const unsigned int vectorSize) {
    int* vector = (int*) malloc(vectorSize * sizeof(int));
    fillVector(vector, vectorSize);
    return vector;
}

void fillVector(unsigned int vector[], const unsigned int vectorSize) {
    for(int i = 0; i < vectorSize; i++) {
        createNotRepeatedNumber(vector, i, vectorSize);
    }
}

void createNotRepeatedNumber(unsigned int vector[], const unsigned int index, const unsigned int vectorSize) {
    if(index >= vectorSize) {
        return;
    }

    unsigned int newNumber = createRandomNumber(MIN_RANDOM_NUMBER_GENERATED, MAX_RANDOM_NUMBER_GENERATED);
    if(vectorContains(vector, vectorSize, newNumber)) {
        createNotRepeatedNumber(vector, index, vectorSize);
    }
    else {
        vector[index] = newNumber;
        return;
    }

    return;
}

unsigned int createRandomNumber(const unsigned int min, const unsigned int max) {
    return (rand() % (max - min + 1)) + min;
}

bool vectorContains(const unsigned int vector[], const unsigned int vectorSize, const unsigned int number) {
    for(int i = 0; i < vectorSize; i++) {
        if(vector[i] == number) {
            return true;
        }
    }

    return false;
}

void printVector(const unsigned int vector[], const unsigned int vectorSize) {
    printf("\n\n---- Vetor de valores: ");

    for(int i = 0; i < vectorSize; i++) {
        printf("\n[%d] Valor: %d", i, vector[i]);
    }

    return;
}

unsigned int** createAddressVector(unsigned int vector[], const unsigned int vectorSize) {
    unsigned int** addressVector = (unsigned int**) malloc(vectorSize * sizeof(int*));

    for(int i = 0; i < vectorSize; i++) {
        addressVector[i] = &vector[i];
    }

    return addressVector;
}

void insertionSort(unsigned int* vector[], const unsigned int vectorSize) {
    for(int i = 0; i < vectorSize; i++) {
        for(int j = i + 1; j < vectorSize; j++) {
            if(*vector[i] < *vector[j]) {
                unsigned int* tempNumber = vector[i];
                vector[i] = vector[j];
                vector[j] = tempNumber;
            }
        }
    }

    return;
}

void printAddressVector(unsigned int* vector[], const unsigned int vectorSize) {
    printf("\n\n---- Vetor de endereços: ");

    for(int i = 0; i < vectorSize; i++) {
        printf("\n[%d] Endereço: %X - Valor: %d.", i, vector[i], *vector[i]);
    }

    return;
}
