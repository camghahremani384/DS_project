#include "Trie.h"
#include <iostream>
#include <cctype>
#include <algorithm> 

Trie_Node::Trie_Node() {
    for (int i = 0; i < 28; i++) {
        children[i] = nullptr;
    }
    currString = "";
}

Trie::Trie() {
    root = new Trie_Node();
}    

Trie::~Trie() {}

int Trie::getIndex(char c) {
    int ascii = int(c);
    int index = 0;
    if (ascii >= 97 && ascii <= 122) {
        index = (ascii - 97) + 1;
    } else if (ascii >= 65 && ascii <= 90) {
        index = (ascii - 65) + 1;
    } else if (ascii == 32) {
        index = 27;
    } else {
        return -1;
    }
    return index;
}


void Trie::insert(string word) {
    Trie_Node* currNode = root;
    // citing geeksforgeeks on auto iterator https://www.geeksforgeeks.org/cpp/iterate-over-characters-of-a-string-in-c/
     cout << "Inserting: " << word << endl;
    for (char c : word) {
        c = toupper(c);
        int index = getIndex(c);
        if (index == -1) {
            cout << "please don't add any special characters to the name" << endl;
            return;
        }
        if (!currNode->children[index]) {
            currNode->children[index] = new Trie_Node();
            currNode->childNodes.push_back(index);
            sort(currNode->childNodes.begin(), currNode->childNodes.end());
        }
        currNode = currNode->children[index];
    }
    if (!currNode->children[0]) {
        currNode->children[0] = new Trie_Node();
        currNode->childNodes.push_back(0);
    }
}

    
bool Trie::search(string word) {
    Trie_Node* currNode = root;
    for (char c: word) {
        int index = getIndex(c);
        if (index == -1) {
            cout << "Please do not use any special characters" << endl;
            return false;
        }
        if (!currNode->children[index]) {
            return false;
        }
        currNode = currNode->children[index];
    }
    if (currNode->children[0]) {
        return true;
    }
    return false;
}

bool Trie::removeRecursive(Trie_Node* node, string word, int charIndex) {
    int length = word.length();
    
    if (charIndex == length) {
        if (node->children[0]) {
            delete node->children[0];
            node->children[0] = nullptr;
            return true;
        }
        return false; // string not found
    }
    int index = getIndex(word[charIndex]);
    if (index == -1) {
        cout << "please do not use any special characters" << endl;
        return false;
    }
    if (!node->children[index]) {
        return false;
    }
    Trie_Node* child = node->children[index];
    bool ret = removeRecursive(child, word, charIndex + 1);
    bool isEmpty = true;
    for (int i = 0; i < 27; i++) {
        if (child->children[i]) {
            isEmpty = false;
            break;
        }
    }
    if (isEmpty) {
        delete child;
        node->children[index] = nullptr;
    }
    return ret;
}


void Trie::treeTraverse(vector<string>& stringVec, Trie_Node* startNode) {
    for (int child : startNode->childNodes) {
        if (child == 0) {
            stringVec.push_back(startNode->currString);
        } else if (child == 27) {
            char character = char(32);
            Trie_Node* childNode = startNode->children[child];
            childNode->currString = startNode->currString + character;
            treeTraverse(stringVec, childNode);
        } else {
            char character = char(64 + child);
            Trie_Node* childNode = startNode->children[child];
            childNode->currString = startNode->currString + character;
            treeTraverse(stringVec, childNode);
        }
    }
}


vector<string> Trie::getTree(Trie_Node* startNode) {
    vector<string> currTree;
    treeTraverse(currTree, startNode);
    return currTree;
}

vector<string> Trie::getSpecificTree(string prompt) {
    Trie_Node* currNode = root;
    
    for (char c : prompt) {
        c = toupper(c);
        int index = getIndex(c);
        if (index == -1) {
            cout << "please do not use any special characters" << endl;
            return {};
        }
        cout << c << endl;
        cout << index << endl;
        cout << "Looking for index: " << index << " in children of currNode" << endl;
        if (!currNode->children[index]) {
            cout << "index wasn't found!" << endl;
            return {};
        }
        currNode->children[index]->currString = currNode->currString + c;
        currNode = currNode->children[index];
    }
    vector<string> resultVec = getTree(currNode);
    return resultVec;
}

bool Trie::remove(string word) {
    Trie_Node* currNode = root;
    return removeRecursive(currNode, word, 0);

}