#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

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
};

struct comp {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

unordered_map<char, string> huffmanCode;

void encode(Node* root, string str) {
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0");
    encode(root->right, str + "1");
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }
    Node* root = pq.top();
    encode(root, "");
}

string encodeText(string text) {
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }
    return encodedText;
}
int main() {
    string text;
    getline(cin, text);
    for (int i = 0; i < text.size(); i++) {
        text[i] = toupper(text[i]);
    }
    buildHuffmanTree(text);
    string encodedText = encodeText(text);
    cout << encodedText << endl;
    return 0;
}
