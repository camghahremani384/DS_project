#include <iostream>
#include <fstream>
#include <iterator>
#include "../code/Trie.h"

using namespace std;

void toUpper(string& startStr) {
    for (size_t i = 0; i < startStr.length(); i++) {
           startStr[i] = toupper(startStr[i]);
    }
}

vector<string> retrieveList(string filename) {
    // citing https://www.youtube.com/watch?v=XajKINSkLII for importing from txt. 
    ifstream file;
    string dir = "../";
    string ext = ".txt";
    filename = dir + filename + ext;
    cout << filename << endl;
    file.open(filename);
    if (file.fail()) {
        cout << "File failed to open" << endl;
        return {};
    }
    vector<string> contacts;
    string line; 
    
    while (!file.eof()) {
        getline(file, line);
        contacts.push_back(line);
    }
    
    file.close();
    
    return contacts;
}

void exportList(vector<string> updatedList) {
    // citing https://stackoverflow.com/questions/6406356/how-to-write-vector-values-to-a-file for exporting vector to txt file
    string dir = "../";
    string ext = ".txt";
    string filename;
    cout << "Choose a file name to export to: ";
    getline(cin, filename);
    filename = dir + filename + ext;
    ofstream output_file(filename);
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(updatedList.begin(), updatedList.end(), output_iterator);
    cout << "Exported List!" << endl;
}

int menu(int& input) {
    cout << "CONTACT LIST MENU" << endl;
    cout << "0) Retrieve Contact List" << endl;
    cout << "1) Print All" << endl;
    cout << "2) Print Specific" << endl; 
    cout << "3) Add Contact" << endl;
    cout << "4) Remove Contact" << endl;
    cout << "5) Search for Contact" << endl;
    cout << "6) Export Contact List" << endl;
    int choice;
    cout << "Enter menu selection (Q to quit): ";
    cin >> choice;
    // citing https://stackoverflow.com/questions/21567291/why-does-stdgetline-skip-input-after-a-formatted-extraction for issues mixing cin/getline
    cin.ignore();
    cout << endl;
    return choice;
}

void useTrie(int choice, Trie& myTrie) {
    if (choice == 0) {
        string filename;
        cout << "choose file to import: ";
        getline(cin, filename);
        cout << "importing contact list" << endl;
        vector<string> contacts = retrieveList(filename);
        int length = contacts.size();
        if (length == 0) {
            cout << "Could not import contact list. " << endl;
        } else {
            for (int i = 0; i < length; i++) {
                myTrie.insert(contacts[i]);
            }
            cout << "contact list imported!" << endl;
        }
        cout << endl;
        cout << endl;
    } else if (choice == 1) {
        cout << "List of All Contacts:" << endl; 
        vector<string> allContacts = myTrie.getSpecificTree("");
        int length = allContacts.size();
        for (int i = 0; i < length; i++) {
            cout << allContacts[i] << endl;
        }
        cout << endl;
        cout << endl;
    } else if (choice == 2) {
        string prompt;
        cout << "choose a search parameter: ";
        // citing https://www.geeksforgeeks.org/cpp/take-long-string-input-with-spaces-in-cpp/ for prompts with spaces
        getline(cin, prompt); 
        vector<string> subContacts = myTrie.getSpecificTree(prompt);
        int length = subContacts.size();
        if (length == 0) {
            cout << "Found no contacts that start with: " << prompt << endl;
        } else {
            cout << "List of All Found Contacts: " << endl;
            for (int i = 0; i < length; i++) {
                cout << subContacts[i] << endl;
            }
        }
        cout << endl;
        cout << endl;
    } else if (choice == 3) {
        string name;
        cout << "choose a name to insert into the list: ";
        getline(cin, name);
        cout << endl;
        cout << "Adding " << name << "to the contact list " << endl;
        myTrie.insert(name);
        toUpper(name);
        bool foundName = myTrie.search(name);
        if (foundName) {
            cout << "Name successfully added!" << endl;
        } else {
            cout << "Name was not successfully added.." << endl;
        }
        cout << endl; 
        cout << endl;
    } else if (choice == 4) {
        string name; 
        cout << "What name would you like to delete from the contact list: ";
        getline(cin, name);
        toUpper(name);
        bool foundDeleted = myTrie.removeName(name);
        if (foundDeleted) {
            cout << "successfully found and deleted name!" << endl;
        } else {
            cout << "Name not found in the contact list." << endl;
        }
        cout << endl;
        cout << endl;
    } else if (choice == 5) {
        string name;
        cout << "choose a name to search for: ";
        getline(cin, name);
        toUpper(name);
        bool foundName = myTrie.search(name);
        if (foundName) {
            cout << name << " is in your contact list." << endl; 
        } else {
            cout << name << " is not in your contact list." << endl;
        }
        cout << endl;
        cout << endl;
    } else if (choice == 6) {
        cout << "getting list" << endl;
        vector<string> updatedList = myTrie.getSpecificTree("");
        cout << "exporting list" << endl;
        exportList(updatedList);
        cout << endl;
        cout << endl;
    }
    
}

int main(){
    Trie myTrie;
    cout << "CSPB 2270 PROJECT" << endl;
    cout << endl; 
    int menu_choice;
    while (!cin.fail()) {
        menu_choice = menu(menu_choice);
        if(!cin.fail()) {
            useTrie(menu_choice, myTrie);
        }
    }
    return 0;
}
