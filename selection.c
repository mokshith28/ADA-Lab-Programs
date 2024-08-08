#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort function
void selectionSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 2; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n - 1; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
// Function to generate an array of random integers
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}
int main() {
    int n_values[] = {
        5000,
        10000,
        15000,
        20000
    }; // Array of n values
    double time_taken[4];
    for (int i = 0; i < 4; i++) {
        int n = n_values[i];
        int * arr = (int * ) malloc(n * sizeof(int));
        generateRandomArray(arr, n);
        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();
        time_taken[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arr);
    }
    // Output time taken for sorting each value of n
    printf("n\tTime Taken (s)\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\t%f\n", n_values[i], time_taken[i]);
    }
    return 0;
}