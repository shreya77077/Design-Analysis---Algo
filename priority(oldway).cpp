#include <iostream>
using namespace std;

#define MAX_SIZE 100

class PriorityQueue {
    int size;
    int arr[MAX_SIZE];

public:
    PriorityQueue() : size(0) {}

    void push(int val) {
        int i;
        for (i = size - 1; (i >= 0 && arr[i] > val); i--)
            arr[i + 1] = arr[i];
        arr[i + 1] = val;
        size++;
    }

    int pop() {
        return arr[--size];
    }

    bool empty() {
        return size == 0;
    }
};

void printArray(const string& message, int arr[], int n) {
    cout << message;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int nums[] = {10, 5, 12, 7, 3, 8};
    int n = sizeof(nums) / sizeof(nums[0]);
    printArray("Original array is: ", nums, n);

    PriorityQueue pq;
    for (int i = 0; i < n; i++)
        pq.push(nums[i]);

    for (int i = 0; i < n; i++)
        nums[i] = pq.pop();

    printArray("Sorted array is: ", nums, n);
    return 0;
}
