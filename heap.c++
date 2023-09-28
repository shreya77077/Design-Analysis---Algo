#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool isMaxHeap) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((isMaxHeap && arr[left] > arr[largest]) || (!isMaxHeap && arr[left] < arr[largest])))
        largest = left;

    if (right < n && ((isMaxHeap && arr[right] > arr[largest]) || (!isMaxHeap && arr[right] < arr[largest])))
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, isMaxHeap);
    }
}

void heapSort(int arr[], int n, bool isMaxHeap) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is \n";
    printArray(arr, n);

    heapSort(arr, n, true);
    cout << "Sorted array using Max Heap is \n";
    printArray(arr, n);

    heapSort(arr, n, false);
    cout << "Sorted array using Min Heap is \n";
    printArray(arr, n);
}
