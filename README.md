# Contact List Using a Trie Data Structure

This program is a contact list interface that uses a trie data structure or prefix tree. 

# Explanation of Data Structure 

A trie or prefix tree is a type of tree that stores nodes within a vector of each node. Each index of the vector represents either letters, a space, or the end of the string. Each node will store the subsequent letter as a child node. For example, If the root node of the prefix tree has A as one of it's children, if App is then inserted into the trie, the child of the A node will be p and the child of that node will be p as well. Additionally, if the word Axe is then added into the trie, x will become a child of the A node and e will be the child of the x node. This allows for very quick insertion, deletion, and searching functionality for strings. The trade off is that it is very memory intensive since every node is essentially given 28 child nodes each. To improve runtime speed, each node is given a vector of childnode indices which are updated when they are initialized. When a character is searched, it will be converted to the index and checked to see if it is among the child nodes of the current node. 

# Installation 

The program has already been compiled using cmake. to run the program, navigate to the build directory and enter in the terminal "./run_app"

# Usage

There are 7 main program functions that can be used in this project:
0) Import List - This function will take a txt file from the root directory and insert all of its contents into the trie. The user does not need to put in the directory or extension. Just the name of the file. There is a demo contacts list of 1000 names if you would like to test out a preloaded trie. Just type in "democontacts".  

1) Print All - This will print everything that has been inserted into the trie thus far. 

2) Print Specific - The program will prompt the user to input a set of characters and will return a subtree of those names (i.e J will return names starting with J; John T will also work to return names starting with John T).

3) Add Contact - This will add a new contact to the trie.

4) Remove Contact - This will remove a contact from the trie.

5) Search for Contact - This will return true or false if there is a contact in the tree that the user is looking for.

6) Export List - This will extract the full list from the trie into a vector which will be exported to a txt file in the root directory of the project. 

Note: All of the names inserted will be converted to upper case and thus will be printed back the same way as well. The user does not need to worry about case sensitivity with their inputs. 

