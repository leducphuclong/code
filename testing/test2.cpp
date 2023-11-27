#include <bits/stdc++.h>

using namespace std;

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

map<char, int> getCharsFrequency(const string& str)
{
    map<char, int> data;
    for (const auto& c : str)
        data[c]++;
    return data;
}

MinHeapNode* HuffmanCoding(map<char, int> data)
{
    if (data.size() == 1) {
        MinHeapNode* root = new MinHeapNode('$', data.begin()->second);
        root->left = new MinHeapNode(data.begin()->first, data.begin()->second);
        return root;
    }

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (const auto& p : data)
        minHeap.push(new MinHeapNode(p.first, p.second));

    while (minHeap.size() != 1) {
        struct MinHeapNode* left, *right, *top;
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left, top->right = right;
        minHeap.push(top);
    }
    return minHeap.top();
}

void traversal(MinHeapNode* top, map<char, string>& codebook, string collect)
{
    if (top == nullptr)
        return;
    if (top->data != '$')
        codebook[top->data] = collect;
    traversal(top->left, codebook, collect + '0');
    traversal(top->right, codebook, collect + '1');
}

map<char, string> getCodebook(MinHeapNode* rootOfHuffmanTree)
{
    map<char, string> codebook;
    traversal(rootOfHuffmanTree, codebook, "");
    return codebook;
}

string encode(const string& original_text, MinHeapNode* rootOfHuffmanTree)
{
    map<char, string> codebook = getCodebook(rootOfHuffmanTree);
    string result = "";
    for (const auto& c : original_text)
        result += codebook[c];
    return result;
}

string decodeHuffman(MinHeapNode* root, const string& encodedData)
{
    string decodedString;
    MinHeapNode* current = root;
    for (char bit : encodedData) {
        if (bit == '0') {
            current = current->left;
        }
        else if (bit == '1') {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedString += current->data;
            current = root;
        }
    }
    return decodedString;
}

void printHuffmanTreeAndEncodedText(MinHeapNode* root, const string& encodedText, ofstream& outFile)
{
    if (root == nullptr) {
        outFile << "0 "; // Indicate a null pointer
        return;
    }

    outFile << "1 " << root->data << " " << root->freq << " ";
    printHuffmanTreeAndEncodedText(root->left, encodedText, outFile);
    printHuffmanTreeAndEncodedText(root->right, encodedText, outFile);

    // After printing the tree structure, add a separator
    outFile << "0\n"; // '0' indicates the separation between tree structure and encoded text
    outFile << encodedText << endl; // Print the encoded text
}

int main()
{
    freopen("original_text.txt", "r", stdin);
    ofstream outFile("encoded_text.txt");

    string original_text;
    getline(cin, original_text);

    MinHeapNode* root = HuffmanCoding(getCharsFrequency(original_text));
    string encoded_text = encode(original_text, root);

    printHuffmanTreeAndEncodedText(root, encoded_text, outFile);

    cout << "Encoded: " << encoded_text << endl;
    return 0;
}
