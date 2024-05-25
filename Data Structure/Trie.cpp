// Arcording to: https://www.techiedelight.com/cpp-implementation-trie-data-structure/

// Example: Find problem count-substrings-that-differ-by-one-character.cpp

#include <iostream>

using namespace std;

#define CHAR_SIZE 256
#define nln '\n'

class Trie {
public:
	bool isLeaf;
	Trie* character[CHAR_SIZE];

	Trie() {
		this->isLeaf = false;
		for (int i = 0; i < CHAR_SIZE; ++i)
			this->character[i] = nullptr;
	}

	void insert(string);
	bool deletion(Trie*&, string);
	bool search(string);
	bool haveChildren(Trie const*);
	void print(Trie const*, string);
};

void Trie::insert(string key) {
    Trie* cur = this; // point to root of this tree
    for (auto c : key) {
        if (!cur->character[c])
            cur->character[c] = new Trie(); // create new node if not already exists
        cur = cur->character[c];
    }
    cur->isLeaf = true;
}

bool Trie::search(string key) {
	if (!this)
		return false;
	Trie* cur = this;
	for (auto c : key) {
		cur = cur->character[c];
		if (!cur) {
			return false;
		}
	}
	return cur->isLeaf;
}

bool Trie::haveChildren(Trie const* cur) {
	if (!cur)
		return false;
	for (int i = 0; i < CHAR_SIZE; ++i)
		if (cur->character[i])
			return true;
	return false;
}

bool Trie::deletion(Trie*& cur, string key) {
	if (!cur)
		return false;

	if (key.length()) {
		if (cur->character[key[0]] && deletion(cur->character[key[0]], key.substr(1))
		&& !cur->isLeaf && !haveChildren(cur)) {
			delete cur;
			cur = nullptr;
			return true;
		} else {
			return false;
		}
	} else {
		if (cur->isLeaf && !haveChildren(cur)) {
			delete cur;
			cur = nullptr;
			return true;
		} else {
			cur->isLeaf = false;
			return false;
		}
	}
}

void Trie::print(Trie const* cur, string word) {
	if (!cur)
		return;

	if (cur->isLeaf)
		cout << "word: " << word << nln;

	for (int i = 0; i < CHAR_SIZE; ++i)
		if (cur->character[i])
			print(cur->character[i], word + static_cast<char>(i));
}

// C++ implementation of Trie data structure
int main()
{
    Trie* head = new Trie();
 
    head->insert("hello");
    cout << head->search("hello") << " ";      // print 1
 	return 0;

    head->insert("helloworld");
    cout << head->search("helloworld") << " "; // print 1
 
    cout << head->search("helll") << " ";      // print 0 (Not found)
 
    head->insert("hell");
    cout << head->search("hell") << " ";       // print 1
 
    head->insert("h");
    cout << head->search("h");                 // print 1
 
    cout << endl;
 
    head->deletion(head, "hello");
    cout << head->search("hello") << " ";      // print 0
 
    cout << head->search("helloworld") << " "; // print 1
    cout << head->search("hell");              // print 1
 
    cout << endl;
 
    head->deletion(head, "h");
    cout << head->search("h") << " ";          // print 0
    cout << head->search("hell") << " ";       // print 1
    cout << head->search("helloworld");        // print 1
 
    cout << endl;
 
    head->deletion(head, "helloworld");
    cout << head->search("helloworld") << " "; // print 0
    cout << head->search("hell") << " ";       // print 1
 
    head->deletion(head, "hell");
    cout << head->search("hell");              // print 0
 
    cout << endl;
 		
 	cout << "Print Trie: " << nln;
 	head->print(head, "");

    if (head == nullptr) {
        cout << "Trie empty!!\n";              // Trie is empty now
    }
 
    cout << head->search("hell");              // print 0
 
    return 0;
}
