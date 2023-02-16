#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Tree node structure for Huffman coding
struct Node {
    char data;
    int freq;
    Node *left, *right;

    // Constructor
    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }

    Node(char data, int num, Node* left, Node* right)
    {
        this->data = data;
        this->freq = num;
        this->left = left;
        this->right = right;
    }
};

// Overload comparison operator to sort the nodes in a priority queue
struct Compare {
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

// Helper function to generate the codes
void encode_helper(Node *root, string code, unordered_map<char, string> &codes)
{
    if (!root) {
        return;
    }

    if (root->data != '\0') {
        codes[root->data] = code;
        return;
    }

    encode_helper(root->left, code + "0", codes);
    encode_helper(root->right, code + "1", codes);
}

// Function to build the Huffman tree and encode the text
void encode(string text)
{
    // Count frequency of each character in the text
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    // Create a priority queue to store the nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Add the nodes to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    // Create a map to store the codes for each character
    unordered_map<char, string> codes;
    string code = "";

    // Traverse the Huffman tree to generate the codes
    Node *root = pq.top();
    encode_helper(root, code, codes);

    // Print the encoded text
    for (char c : text) {
        cout << codes[c];
    }
    cout << endl;
}



int main()
{
    string text;
    cin >> text;

    // Convert the text to uppercase
    for (char &c : text) {
        c = toupper(c);
    }

    encode(text);

    return 0;
}
