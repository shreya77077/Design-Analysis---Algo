/*The error you're seeing is because in C++, the size of an array must be a constant expression, 
and non-static variables (like max_val in this case) are not considered constant expressions.
A workaround for this is to dynamically allocate memory for the count array using
 the new keyword. Here's how you can do it:*/
#include<iostream>
using namespace std;

// Function for Counting sort
void countingSort(int arr[], int n)
{
    // Find the maximum element in the array
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Dynamically allocate memory for the count array
    int* count = new int[max_val + 1]();

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the count array to reflect the actual position of each element
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // Output array to store the sorted array
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Deallocate memory
    delete[] count;
    delete[] output;
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver program
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    countingSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
/*This code dynamically allocates memory for the count and output arrays, and 
then deallocates it when it's no longer needed. This should resolve the error you were seeing.*/
