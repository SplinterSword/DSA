#include <iostream>
using namespace std;

class TrieNode
{
    public:

    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;

        for (int i=0 ; i<26 ; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
    TrieNode* root;

    Trie()
    {
        root = new TrieNode['\0'];
    }

    void insertUtil(TrieNode* root,string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        TrieNode* child;
        char letter = word[0];
        int index = letter-'A';

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode[letter];
            root->children[index] = child;
        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        TrieNode* child;
        char letter = word[0];
        int index = letter-'A';

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        searchUtil(child,word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }
};


int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCD");

    cout << t->searchWord("ABCD") << endl;
    return 0;
    return 0;
}