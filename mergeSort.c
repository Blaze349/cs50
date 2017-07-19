#include <stdio.h>

void merge(int arr[], int min, int mid, int max) {
    int i = min, j = mid;
    int temp[sizeof(arr)/sizeof(arr[0])]; 
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        temp[i] = arr[i];
    }
    int k = min;
    while(i < mid && j < max) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        } 
        else {
            arr[k] = temp[j];
            j++; 
        }
        k++;
    }
    while(i < mid) arr[k] = temp[i]; i++; k++;
    while(j < max) arr[k] = temp[j]; j++; k++;
}

void mergeSort(int arr[], int min, int max) {
    if (max > min) {
        int mid = min + (max - 1) / 2;
        mergeSort(arr, min, mid);
        mergeSort(arr, mid+1, max);
        merge(arr, min, mid, max);
    }
}

int main(void) {
    int arr[10] = {1,42,4,2,4,5,3,8,19,10};
    for (int i = 0; i < 10; i++) printf("%d, ", arr[i]);
    printf("\n");
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d, ", arr[i]);
}
