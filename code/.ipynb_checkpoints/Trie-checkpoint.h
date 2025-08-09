#ifndef TRIE_H__
#define TRIE_H__

#include <memory>
#include <string>
#include <vector>
using namespace std;

struct trie_node {
    int data;
    trie_node* left;
    trie_node* right;
};

class Trie {
public:
    // constructor initializes class variables and pointers
    // set root to null
    Trie();
    
    // deconstructor - use to clean up memory
    ~Trie();
    
    // initializes trie node and returns a pointer to it. gives two null children
    trie_node* init_node(char data);

    // traverses the trie and assigns the new node to the new character
    void insert(trie_node* new_node);
    
private:
    // double pointer always will point to the root pointer of the trie
    trie_node** root;
};

#endif // TRIE_H__