#include <stdio.h>
#include <stdlib.h>

void printArray(int * array, int start, int end) {
    printf("[");
    for (int i = start; i <= end - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]", array[end]);
}

void merge(int numbers[], int s1, int e1, int s2, int e2) {
    printf("Merge: ");
    printArray(numbers, s1, e1);
    printf(" ");
    printArray(numbers, s2, e2);

    int i1 = s1;
    int i2 = s2;
    int * sorted = (int *) malloc((e2 - s1) * sizeof(int));
    int s = 0;
    while (i1 <= e1 && i2 <= e2) {
        if (numbers[i1] <= numbers[i2]) {
            sorted[s] = numbers[i1];
            i1++;
        } else {
            sorted[s] = numbers[i2];
            i2++;
        }
        s++;
    }
    while (i1 <= e1) {
        sorted[s] = numbers[i1];
        i1++;
        s++;
    }
    while (i2 <= e2) {
        sorted[s] = numbers[i2];
        i2++;
        s++;
    }
    printf(" -> ");
    printArray(sorted, 0, e2 - s1);
    printf("\n");
    for (s = s1; s <= e2; s++) {
        numbers[s] = sorted[s - s1];
    }
    free(sorted);
}

void mergeSort(int numbers[], int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(numbers, start, mid);
    mergeSort(numbers, mid + 1, end);
    merge(numbers, start, mid, mid + 1, end);
}

int main(void) {
    int numbers[] = {4, 0, 5, 10, 2, 0, -34, 34, 100};
    int length = sizeof(numbers) / sizeof(int);
    mergeSort(numbers, 0, length - 1);
    printArray(numbers, 0, length - 1);
    return 0;
}