#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> sortArrayUsingPriorityQueue(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

void printArray(const string& message, const vector<int>& nums) {
    cout << message;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {10, 5, 12, 7, 3, 8};
    printArray("Original array is: ", nums);
    vector<int> sortedNums = sortArrayUsingPriorityQueue(nums);
    printArray("Sorted array is: ", sortedNums);
    return 0;
}
