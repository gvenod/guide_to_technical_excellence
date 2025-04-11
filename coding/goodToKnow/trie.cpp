#include <iostream>
using namespace std;
 
const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    //all childern  a - z
    TrieNode* children[ALPHABET_SIZE];//a at index 0; z at 26; b at index ['b' - 'a'] = 1;

    // Indicates end of word
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
	
	void insert(TrieNode* root, const string& key) {
		TrieNode* curr = root;		
		for (char c : key) { //iterate char by char 
			if (curr->children[c - 'a'] == nullptr) {// Check if the node with char exists
				TrieNode* newNode = new TrieNode();			  
				curr->children[c - 'a'] = newNode;//create and insert
			}
			curr = curr->children[c - 'a'];//move to the next node.
		}		
		curr->isLeaf = true;// Mark the end of the word
	}
	
	bool search(TrieNode* root, const string& key) {
		TrieNode* curr = root;		
		for (char c : key) { //iterate char by char 
			if (curr->children[c - 'a'] == nullptr) 
				return false;
			curr = curr->children[c - 'a'];// if the node exists then go next.
		}
		return curr->isLeaf;//return true if valid word
	}
};

int main() {
    TrieNode* root = new TrieNode();
    
	vector<string> arr = 
      {"and", "ant", "do", "geek", "dad", "ball"};
    
	for (const string& s : arr) {
        insert(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string& s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (search(root, s)) 
            cout << "Present\n";
        else 
            cout << "Not Present\n";        
    }
  
    return 0;
}