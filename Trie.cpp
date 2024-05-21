//
// Created by salah elsayed on 5/21/2024.
//

#include "Trie.h"

using namespace std;
void Trie::insert(string s) {
    char rootval=s[0];
    bool found= false;
    node*current= nullptr;
    for (auto it:roots) {
        if (it->value==rootval) {
            found = true;
            current=it;
            break;
        }
    }
    if (!found) {
        node* toinsert=new node(rootval);
        roots.push_back(toinsert);
        current=toinsert;
    }

    for (int i = 1; i < s.size(); ++i) {
        bool found= false;
        for (auto it : current->next) {
            if (it->value==s[i]) {
                current = it;
                found= true;
                break;
            }
        }
        if (!found){
            node* toinsert=new node(s[i]);
            current->next.push_back(toinsert);
            current=toinsert;
        }
    }
    current->isEndOfWord= true;
}
void Trie::printHelper(node* current, string path) {
    if (!current) return;

    path += current->value;

    if (current->isEndOfWord) {
        cout << path << endl;
    }

    for (auto child : current->next) {
        printHelper(child, path);
    }
}

void Trie::print() {
    for (auto root : roots) {
        printHelper(root, "");
    }
}