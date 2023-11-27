#include <bits/stdc++.h> 

using namespace std; 

struct MinHeapNode { 
    // Character data of this node
    char data; 
    // Frequency of the character 
    unsigned freq; 
    // Pointer to its Left and right child 
    MinHeapNode *left, *right; 
    // Constructor
    MinHeapNode(char data, unsigned freq)  { 
        left = right = NULL; // at beginning, we just construct
        this->data = data;   // the leaves
        this->freq = freq; 
    } 
}; 
 
// For comparison of two heap nodes (needed in min heap) 
struct compare { 
    bool operator()(MinHeapNode* l, MinHeapNode* r) { 
        return (l->freq > r->freq); 
    } 
}; 
 
// The main function that builds a Huffman Tree
MinHeapNode* HuffmanCodes(map<char, int> data) { 
    // Create a min heap & inserts all characters of data[] 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 

    // Construct all charater as a leave node and push them to minHeap
    for (const auto &p : data)
        minHeap.push(new MinHeapNode(p.first, p.second)); 

    // Iterate while size of heap doesn't become 1 
    while (minHeap.size() != 1) { 
        struct MinHeapNode *left, *right, *top; 
        // Extract the two minimum freq items from min heap 
        left = minHeap.top();
        minHeap.pop(); // Pop out of min Heap
        right = minHeap.top();
        minHeap.pop(); // Pop out of min Heap
 
        // Create a new internal node with frequency equal to the sum of the 
        // two nodes frequencies. Make the two extracted node as left and right 
        // children of this new node. 

        // Add this node to the min heap '$' is a special value 
        // for internal nodes, mark that it doesn't contain the our data
        top = new MinHeapNode('$', left->freq + right->freq); 
        top->left = left, top->right = right; 

        minHeap.push(top); 
    }  
    // This function will return the root of Huffman Tree
    return minHeap.top();
}

void traversal(MinHeapNode* top, map<char, string> &codebook, string collect) {
    if (top->data != '$')
        codebook[top->data] = collect;
    traversal(top->left, codebook, collect + '0');
    traversal(top->right, codebook, collect + '1');
}

// This function to get the codebook from the Huffman tree
map<char, string> getCodebook(MinHeapNode* rootOfHuffmanTree) {
    map<char, string> codebook;
    traversal(rootOfHuffmanTree, codebook, "");
    return codebook;
}

string decodeHuffman(MinHeapNode* root, const string& encodedData) {
    string decodedString;
    MinHeapNode* current = root;
    // Just iterate all charater of the encoded string
    for (char bit : encodedData) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedString += current->data;
            current = root;  // Reset to the root for the next character
        }
    }
    return decodedString;
}
 
// Driver Code 
int main() 
{ 
    cout << "hi" << endl;
    return 0;
    // Read the Original text
    freopen("original_text.txt", "r", stdin);
    string original_text;
    getline(cin, original_text);

    // Count number of each unique charater appears
    map<char, int> data;
    for (const auto &c : original_text)
        data[c]++;

    // Build Huffman tree
    MinHeapNode* root = HuffmanCodes(data);

    // Get codebook from Huffman tree


 
    return 0; 
} 
 
