#include "Trie.h"
#include <iostream>

Trie::Trie() {
    root = new trie_node*;
    *root = NULL;
}

Trie::~Trie() {}

trie_node* Trie::init_node(char data) {
    trie_node* ret(new trie_node);
    ret->data = data;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

void Trie::insert(trie_node* new_node) {
    cout << "TODO" << endl;
}
