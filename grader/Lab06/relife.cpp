#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// Node for Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
    ~Node() {
        delete left;
        delete right;
    }
};

// Comparison object for priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Build Huffman tree and return root
Node* buildHuffmanTree(string text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Build priority queue of nodes
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('$', left->freq + right->freq, left, right);
        pq.push(parent);
    }

    // Return root of Huffman tree
    return pq.top();
}

// Traverse Huffman tree and store codes in a map
void traverseHuffmanTree(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->ch] = code;
    }
    traverseHuffmanTree(root->left, code + "0", codes);
    traverseHuffmanTree(root->right, code + "1", codes);
}

// Encode text using Huffman codes
string encode(string text, unordered_map<char, string>& codes) {
    string result;
    for (char ch : text) {
        result += codes[ch];
    }
    return result;
}

int main() {
    // Read input
    string text;
    getline(cin, text);

    // Convert all characters to uppercase
    for (int i = 0; i < text.size(); i++) {
        text[i] = toupper(text[i]);
    }

    // Build Huffman tree and codes
    unordered_map<char, string> codes;
    Node* root = buildHuffmanTree(text);
    traverseHuffmanTree(root, "", codes);

    // Encode text using Huffman codes
    string encodedText = encode(text, codes);

    // Print encoded text
    cout << encodedText << endl;

    // Clean up
    delete root;
}
