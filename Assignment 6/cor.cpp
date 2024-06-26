#include <bits/stdc++.h>
using namespace std;

class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

class HuffmanDecoding {
private:
    HuffmanNode* root;
    unordered_map<char, int> freqMap;

    HuffmanNode* buildHuffmanTree() {
        auto cmp = [](HuffmanNode* left, HuffmanNode* right) {
            return left->freq > right->freq;
        };
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, decltype(cmp)> minHeap(cmp);

        for (const auto& pair : freqMap) {
            minHeap.push(new HuffmanNode(pair.first, pair.second));
        }

        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top(); minHeap.pop();
            HuffmanNode* right = minHeap.top(); minHeap.pop();

            int sum = left->freq + right->freq;
            HuffmanNode* node = new HuffmanNode('\0', sum);
            node->left = left;
            node->right = right;

            minHeap.push(node);
        }

        return minHeap.top();
    }

    void decode(HuffmanNode* node, const string& encodedString, string& decodedString, int& index) {
        if (!node) return;

        if (!node->left && !node->right) {
            decodedString += node->data;
            return;
        }

        if (index < encodedString.size()) {
            char bit = encodedString[index++];
            if (bit == '0')
                decode(node->left, encodedString, decodedString, index);
            else
                decode(node->right, encodedString, decodedString, index);
        }
    }

public:
    HuffmanDecoding(const unordered_map<char, int>& frequencies) : freqMap(frequencies) {
        root = buildHuffmanTree();
    }

    ~HuffmanDecoding() {
        function<void(HuffmanNode*)> deleteTree = [&](HuffmanNode* node) {
            if (!node) return;
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        };
        deleteTree(root);
    }

    void decode(const string& encodedString, string& decodedString) {
        int index = 0;
        while (index < encodedString.size()) {
            decode(root, encodedString, decodedString, index);
        }
    }
};

int main() {
    // Frequency map provided
    unordered_map<char, int> freqMap = {
        {'k', 2}, {'j', 1}, {'p', 8}, {'x', 1}, {'K', 1}, {'.', 3}, {'h', 7},
        {'c', 4}, {'e', 17}, {'d', 7}, {'y', 2}, {'C', 1}, {'o', 16}, {'n', 8},
        {'a', 6}, {'w', 1}, {' ', 29}, {'g', 6}, {'t', 14}, {'r', 7}, {'u', 6},
        {'l', 4}, {'i', 5}, {'s', 5}, {'I', 1}, {'f', 2}, {',', 1}
    };

    HuffmanDecoding decoder(freqMap);

    string compressedFileName = "compressed.txt";
    string decompressedFileName = "decompressed.txt";

    // Read the encoded data from the file
    ifstream inputFile(compressedFileName, ios::in);
    if (!inputFile.is_open()) {
        cerr << "Error opening compressed file!" << endl;
        return 1;
    }

    // Read the encoded string from the file
    string encodedString((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    string decodedString;
    decoder.decode(encodedString, decodedString);

    ofstream outputFile(decompressedFileName, ios::out);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    outputFile << decodedString;
    outputFile.close();

    cout << "Decompression complete." << endl;

    return 0;
}