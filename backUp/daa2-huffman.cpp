#include <bits/stdc++.h>
using namespace std;

// Define a class to represent a Huffman tree node
class HuffmanNode {
public:
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for the priority queue to create a min-heap
class CompareNodes {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Function to build the Huffman tree and return the root node
HuffmanNode* buildHuffmanTree(map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    // Create a leaf node for each character and add it to the min-heap
    for (const auto& entry : frequencies) {
        HuffmanNode* node = new HuffmanNode(entry.first, entry.second);
        minHeap.push(node);
    }

    // Build the Huffman tree by merging nodes
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of its children
        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

// Function to generate Huffman codes for each character
void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (!root)
        return;

    if (root->data != '\0') {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    map<char, int> frequencies;
    for (char c : text) {
        frequencies[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(frequencies);

    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (const auto& entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
