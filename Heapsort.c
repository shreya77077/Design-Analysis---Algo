#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((isMaxHeap && arr[left] > arr[largest]) || (!isMaxHeap && arr[left] < arr[largest])))
        largest = left;

    if (right < n && ((isMaxHeap && arr[right] > arr[largest]) || (!isMaxHeap && arr[right] < arr[largest])))
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, isMaxHeap);
    }
}

void heapSort(int arr[], int n, int isMaxHeap) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array is \n");
    printArray(arr, n);

    heapSort(arr, n, 1);
    printf("Sorted array using Max Heap is \n");
    printArray(arr, n);

    heapSort(arr, n, 0);
    printf("Sorted array using Min Heap is \n");
    printArray(arr, n);
}
/*This code first builds a heap from the input data. Then, it removes the maximum element from the heap (in the case of a max heap) or the minimum element (in the case of a min heap), and puts it at the end of the sorted array. After removing the element, it heapifies the reduced heap. This process is repeated until the heap is empty and the array is sorted. The heapify function is used to maintain the heap property.

*/