#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char data, unsigned freq) : data(data), freq(freq), left(NULL), right(NULL) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(struct Node* root, string str) {
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}


//time complexcity: O(nlog n)
//greedy algo
/*The time complexity of the Huffman coding algorithm is O(n log n), where n is the number of unique characters. 

Here's why:

1. Building a priority queue: This takes O(n) time, where n is the number of unique characters.

2. Extracting the two nodes with the lowest frequency from the priority queue: This operation is performed n-1 times and it takes O(log n) time to extract an item from the priority queue. So, the total time for this step is O(n log n).

3. Inserting a new node into the priority queue: This operation is also performed n-1 times and it takes O(log n) time to insert an item into the priority queue. So, the total time for this step is also O(n log n).

Therefore, the overall time complexity of the Huffman coding algorithm is O(n log n).*/