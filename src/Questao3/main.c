#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_RANDOM_NUMBER_GENERATED 1
#define MAX_RANDOM_NUMBER_GENERATED 50

typedef struct Vector {
    int size;
    int* content;
} Vector;

void setStartSettings();
Vector* createIntVector(const size_t size);
void fillVector(Vector* vector);
int generateRandomNumber(const int min, const int max);
Vector* interception(const Vector vector1, const Vector vector2);
bool vectorContains(const Vector vector, const int number);
void printVector(const Vector vector);

int main() {
    setStartSettings();

    Vector* qVector = createIntVector(12 * sizeof(int));
    printf("\n\n---- Valores vetor Q:");
    printVector(*qVector);

    Vector* rVector = createIntVector(20 * sizeof(int));
    printf("\n\n---- Valores vetor R:");
    printVector(*rVector);

    Vector* wVector = interception(*qVector, *rVector);
    printf("\n\n---- Valores vetor Q:");
    printVector(*wVector);

    free(qVector);
    free(rVector);
    free(wVector);
    return 0;
}

void setStartSettings() {
    srand(time(0));
    return;
}

Vector* createIntVector(const size_t size) {
    Vector* newVector = (Vector*) malloc(sizeof(Vector));
    newVector->content = (int*) malloc(size);
    newVector->size = (size / sizeof(int));

    fillVector(newVector);

    return newVector;
}

void fillVector(Vector* vector) {
    for(int i = 0; i < vector->size; i++) {
        vector->content[i] = generateRandomNumber(MIN_RANDOM_NUMBER_GENERATED, MAX_RANDOM_NUMBER_GENERATED);
    }

    return;
}

int generateRandomNumber(const int min, const int max) {
    return (rand() % (max - min + 1)) + min;
}

Vector* interception(const Vector vector1, const Vector vector2) {
    Vector* result = (Vector*) malloc(sizeof(result));
    result->size = 0;
    result->content = (int*) malloc(result->size * sizeof(int));
    unsigned int resultIndex = 0;

    for(int i = 0; i < vector1.size; i++) {
        for(int j = 0; j < vector2.size; j++) {
            if(vector1.content[i] == vector2.content[j] && !vectorContains(*result, vector1.content[i])) {
                result->size++;
                result->content = realloc(result->content, sizeof(Vector) + sizeof(*(result->content)) + sizeof(int));

                result->content[resultIndex] = vector1.content[i];
                resultIndex++;
            }
        }
    }

    return result;
}

bool vectorContains(const Vector vector, const int number) {
    for(int i = 0; i < vector.size; i++) {
        if(vector.content[i] == number) {
            return true;
        }
    }

    return false;
}

void printVector(const Vector vector) {
    for(int i = 0; i < vector.size; i++) {
        printf("\n[%d] Valor: %d.", i, vector.content[i]);
    }

    return;
}
