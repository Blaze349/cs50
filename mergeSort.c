#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int min, int mid, int max);
void mergeSort(int arr[], int min, int max);

int main(void) {
    int arr[10] = {1,42,4,2,4,5,3,8,19,10};
    for (int i = 0; i < 10; i++) printf("%d, ", arr[i]);
    printf("Calling Mergesort");
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d, ", arr[i]);
    return 0;
}

void merge(int arr[], int min, int mid, int max) {
    int i = 0,j = 0,k = min;
    int size1 = mid - min + 1;
    int size2 = max - mid;

    int L[size1], R[size2];

    for (int i = 0; i < size1; i++) L[i] = arr[min + i];
    for (int i = 0; i < size1; i++) R[i] = arr[mid + i + 1];

    while (i < size1 && j < size2) {
        if (L[i] <= R[j]) {
         arr[k] = L[i];
         printf("I %d\n", i);
         i++;
        }
        else {
         arr[k] = R[j];
         printf("J %d\n", j);
         j++;
        }
        k++; 
    }
    while(i < size1) arr[k] = L[i]; i++; k++;
    while(j < size2) arr[k] = R[j]; j++; k++;
    
}

void mergeSort(int arr[], int min, int max) {
    printf("%d Max\n", max);
    printf("%d Min\n", min);
    if (max > min) {
        printf("Finding mid\n");
        int mid = (min + max) / 2;
        printf("Sorting left half\n");
        mergeSort(arr, min, mid);
        printf("Sorting right half\n");
        mergeSort(arr, mid+1, max);
        merge(arr, min, mid, max);
    }
}
