#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function for Bucket sort
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    vector<float> bucket[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(bucket[i].begin(), bucket[i].end());

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            arr[index++] = bucket[i][j];
}

// Function to print an array
void printArray(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main()
{
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    bucketSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
/*The time complexity of Bucket Sort is O(n + n^2/k + k), 
where n is the number of elements and k is the number of buckets. In the best 
case where the input is uniformly distributed, the complexity can be linear, i.e., O(n). 
The space complexity is O(nk), for n elements and k buckets.

*/