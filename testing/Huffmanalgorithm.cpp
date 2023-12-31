#include <bits/stdc++.h> 
 
using namespace std; 
 
map<char, string> codebook;
 
// A Huffman tree node 
struct MinHeapNode { 
 
    // One of the input characters 
    char data; 
 
    // Frequency of the character 
    unsigned freq; 
 
    // Left and right child 
    MinHeapNode *left, *right; 
 
    MinHeapNode(char data, unsigned freq) 
 
    { 
 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 
 
// For comparison of 
// two heap nodes (needed in min heap) 
struct compare { 
 
    bool operator()(MinHeapNode* l, MinHeapNode* r) 
 
    { 
        return (l->freq > r->freq); 
    } 
}; 
 
// Prints huffman codes from 
// the root of Huffman Tree. 
void printCodes(struct MinHeapNode* root, string str) 
{ 
 
    if (!root) 
        return; 
 
    if (root->data != '$') 
        codebook[root->data] = str;
 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 
 
// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
MinHeapNode* HuffmanCodes(char data[], int freq[], int size) 
{ 
    struct MinHeapNode *left, *right, *top; 
 
    // Create a min heap & inserts all characters of data[] 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, 
                compare> 
        minHeap; 
 
    for (int i = 0; i < size; ++i) 
        minHeap.push(new MinHeapNode(data[i], freq[i])); 
 
    // Iterate while size of heap doesn't become 1 
    while (minHeap.size() != 1) { 
 
        // Extract the two minimum 
        // freq items from min heap 
        left = minHeap.top(); 
        minHeap.pop(); 
 
        right = minHeap.top(); 
        minHeap.pop(); 
 
        // Create a new internal node with 
        // frequency equal to the sum of the 
        // two nodes frequencies. Make the 
        // two extracted node as left and right children 
        // of this new node. Add this node 
        // to the min heap '$' is a special value 
        // for internal nodes, not used 
        top = new MinHeapNode('$', 
                            left->freq + right->freq); 
 
        top->left = left; 
        top->right = right; 
 
        minHeap.push(top); 
    } 
 
    // Print Huffman codes using 
    // the Huffman tree built above 
    printCodes(minHeap.top(), ""); 
    return minHeap.top();
} 
 
string decodeHuffman(MinHeapNode* root, const string& encodedData) {
    string decodedString;
    MinHeapNode* current = root;
 
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
    freopen("original_text.txt", "r", stdin);
    string test = "Ly thuyet thong tin";
    getline(cin, test);
    
    map<char, int> cnt;
    for (auto c : test)
        cnt[c]++;
    int n = cnt.size();
    char arr[n];
    int freq[n];
    int i = 0;
    for (auto p : cnt) {
        arr[i] = p.first;
        freq[i] = p.second;
        i++;
    }
 
 
 
    int size = sizeof(arr) / sizeof(arr[0]); 
 
    MinHeapNode* root = HuffmanCodes(arr, freq, size); 
    string encoded = "";
    for (auto c : test)
        encoded += codebook[c];  
    cout << "Encoded: " << encoded << endl;
    string decoded = decodeHuffman(root, encoded);
    cout << "Decoded: " << decoded << endl;
 
 
 
    return 0; 
} 
 
