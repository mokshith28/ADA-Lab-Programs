#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int * a, int * b);
void generateRandomArray(int arr[], int n);

// Partition function
int partition(int arr[], int low, int high) {
    // initialize pivot to be the first element 
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // condition 1: find the first element greater than the pivot (from starting) 
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // condition 2: find the first element smaller than the pivot (from last) 
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap( & arr[i], & arr[j]);
        }
    }
    swap( & arr[low], & arr[j]);
    return j;

}
//Function to swap two elements
void swap(int * a, int * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call Partition function to find Partition Index 
        int partitionIndex = partition(arr, low, high);
        // Recursively call quickSort() for left and right half based on partition Index 
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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
    clock_t start, end;
    double time_taken[4];
    for (int i = 0; i < 4; i++) {
        int n = n_values[i];
        int * arr = (int * ) malloc(n * sizeof(int));
        generateRandomArray(arr, n);
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        time_taken[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arr);
    }
    printf("n\tTime Taken (s)\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\t%f\n", n_values[i], time_taken[i]);
    }
    return 0;
}