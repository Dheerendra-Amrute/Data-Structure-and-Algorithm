#include <stdio.h>

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    // The first element is the pivot
    int pivot = arr[low];
    
    // p starts from the left of the pivot
    int p = low + 1;
    // q starts from the high end
    int q = high;

    // The loop continues until p and q cross
    while (1) {
        // p want to arrange No. greater than pivot element
        // p move on RHS
        // Will stop on an element that is > pivot
        while (p <= high && arr[p] <= pivot) {
            p++;
        }

        // q want to arrange No. lesser than pivot element
        // q will move on LHS
        // Will stop on an element that is <= pivot
        while (q >= low && arr[q] > pivot) {
            q--;
        }

        // check: if p and q crossed or not
        if (p < q) {
            // If not crossed, then swap p and q elements
            swap(&arr[p], &arr[q]);
        } else {
            // If they have crossed, the partitioning is done
            break;
        }
    }

    // if crossed => Swap pivot element with q
    swap(&arr[low], &arr[q]);

    // Return the final position of the pivot
    return q;
}

// The main recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partitioning index
        int partition_index = partition(arr, low, high);

        // Recursively sort the left hand side (LHS)
        quickSort(arr, low, partition_index - 1);
        
        // Recursively sort the right hand side (RHS)
        quickSort(arr, partition_index + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; 
    int n;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }  
    printf("\nOriginal array: ");
    printArray(arr, n);
    
    // Call Quick Sort to sort the array
    quickSort(arr, 0, n - 1);
    printf("Sorted array:   ");
    printArray(arr, n);
    
    return 0;
}