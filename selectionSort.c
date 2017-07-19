#include <stdio.h>

void selectionSort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        int pos = i;

        for (int j = i; j < length; j++) {
            if (arr[j] < arr[pos]) pos = j;
        } 

        if (pos != i) {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
        }
    } 
}

int main(void) {
    int arr[10] = {1,42,4,2,4,5,3,8,19,10};
    for (int i = 0; i < 10; i++) printf("%d, ", arr[i]);
    printf("\n");
    selectionSort(arr, 10);
    for (int i = 0; i < 10; i++) printf("%d, ", arr[i]);
}
