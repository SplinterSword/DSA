// Implementation of Trie
// https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-interview-150

class TrieNode {
public:
    char value;
    TrieNode* children[256];
    bool terminal;

    TrieNode(char data) {
        
        value = data;

        for (int i=0;i<256;i++) {
            children[i] = NULL;
        }

        terminal = false;
    }
};

void insertinTrie(TrieNode* root, string word, int index) {

    if (index == word.size()){
        root->terminal = true;
        return;
    }

    char character = word[index];
    int characterIndex = character - '0';

    // Already Present in the trie
    if (root->children[characterIndex] != NULL){
        insertinTrie(root->children[characterIndex], word, index+1);
        return;
    }

    // Not Present In the Trie
    TrieNode* newNode = new TrieNode(character);
    root->children[characterIndex] = newNode;
    insertinTrie(root->children[characterIndex], word, index+1);
    return;
}

bool searchinTrie(TrieNode* root, string word, int index) {

    if (root == NULL) {
        return false;
    }

    if (index == word.size()){
        return root->terminal;
    }

    char character = word[index];
    int characterIndex = character - '0';

    // Already Present in the trie
    if (root->children[characterIndex] != NULL){
        return searchinTrie(root->children[characterIndex], word, index+1);  
    }

    // Not Present In the Trie
    return false;
}

bool startsWithinTrie(TrieNode* root, string word, int index) {

    if (root == NULL) {
        return false;
    }

    if (index == word.size()){
        return true;
    }

    char character = word[index];
    int characterIndex = character - '0';

    // Already Present in the trie
    if (root->children[characterIndex] != NULL){
        return startsWithinTrie(root->children[characterIndex], word, index+1);  
    }

    // Not Present In the Trie
    return false;
}

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertinTrie(root,word,0);
    }
    
    bool search(string word) {
        return searchinTrie(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return startsWithinTrie(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */