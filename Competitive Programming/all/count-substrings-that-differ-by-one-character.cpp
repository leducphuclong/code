// Arcording to: https://www.techiedelight.com/cpp-implementation-trie-data-structure/
#include <iostream>

using namespace std;

#define CHAR_SIZE 26
#define nln '\n'

class Trie {
public:
	int isLeaf = 0;
	Trie* character[CHAR_SIZE];

	Trie() {
		this->isLeaf = 0;
		for (int i = 0; i < CHAR_SIZE; ++i)
			this->character[i] = nullptr;
	}

	void insert(string);
	bool deletion(Trie*&, string);
	int search(string);
	bool haveChildren(Trie const*);
	void print(Trie const*, string);
};

void Trie::insert(string key) {
    Trie* cur = this; // point to root of this tree
    for (auto c : key) {
        if (!cur->character[c-'a']) {
        	cur->noChild++;
            cur->character[c-'a'] = new Trie(); // create new node if not already exists
        }
        cur = cur->character[c-'a'];
    }
    cur->isLeaf++;
}

int Trie::search(string key) {
	if (!this)
		return false;
	Trie* cur = this;
	for (auto c : key) {
		cur = cur->character[c-'a'];
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
		bool child_deleted = cur->character[key[0]-'a'] && deletion(cur->character[key[0]-'a'], key.substr(1));
		if (child_deleted && !cur->isLeaf && !haveChildren(cur)) {
			delete cur;
			cur = nullptr;
			return true;
		} else {
			if (child_deleted)
				cur->noChild--;
			return false;
		}
	} else {
		if (cur->isLeaf && !haveChildren(cur)) {
			cur->isLeaf--;
			if (cur->isLeaf == 0) {
				delete cur;
				cur = nullptr;
				return true;
			} else {
				return false;
			}
		} else {
			if (cur->isLeaf)
				cur->isLeaf--;
			return false;
		}
	}
}

void Trie::print(Trie const* cur, string word) {
	if (!cur)
		return;

	if (cur->isLeaf)
		cout << "word: " << word << " - " << cur->isLeaf << nln;

	for (int i = 0; i < CHAR_SIZE; ++i)
		if (cur->character[i])
			print(cur->character[i], word + static_cast<char>(i+'a'));
}

// C++ implementation of Trie data structure
int main()
{
    Trie* head = new Trie();
    string s = "ab", t = "bb";

    int n = s.size(), m = t.size();
    for (int i = 1; i <= n; ++i)
    	for (int j = 0; j < n-i+1; ++j)
    		head->insert(s.substr(j, i));

    // head->print(head, "");
    // cout << nln << nln;
  
    int res = 0;
    for (int i = 1; i <= m; ++i)
    	for (int j = 0; j < m-i+1; ++j) {
    		string sub = t.substr(j, i);
    		for (int k = 0; k < sub.length(); ++k) {
    			for (char ch = 'a'; ch <= 'z'; ++ch) {
    				if (sub[k] != ch) {
    					char tmp = sub[k];
    					sub[k] = ch;
    					res += head->search(sub);
    					sub[k] = tmp;
    				}
    			}
    		}
    	}

    cout << res << nln;

    return 0;
}
