#ifndef TRIE_H__
#define TRIE_H__

#include <memory>
#include <string>
#include <vector>
using namespace std;

class Trie_Node {
public:
    Trie_Node* children[28];
    
    Trie_Node();

    string currString;
    
    vector<int> childNodes; // keep track of child nodes
};

class Trie {
public:
    // initialize the root Trie_Node and set children to nullptrs
    Trie();
    
    // deconstructor - use to clean up memory
    ~Trie();
    
    //returns index of character
    int getIndex(char c);

    // traverses the trie and assigns the string
    void insert(string word);
    
    // returns true/false if string is in the trie
    bool search(string word);
    
    // recursive helper for removal 
    bool removeRecursive(Trie_Node* node, string word, int charIndex);
    // removes the word from the trie
    bool remove(string word);
    
    void treeTraverse(vector<string>& stringVec, Trie_Node* startNode);
    
    // store and print specific subTree
    vector<string> getTree(Trie_Node* startNode);
    
    // get specific tree (a, b, c, etc)
    vector<string> getSpecificTree(string prompt);
private:
    //for access to the root of the trie
    Trie_Node* root;
};

#endif // TRIE_H__