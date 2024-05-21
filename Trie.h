using namespace std;
#include <iostream>
#include <vector>
#include <string>

#ifndef UNTITLED1_TRIE_H
#define UNTITLED1_TRIE_H

template <typename T>
class node {
public:
    vector<node*> next;
    char value;
    bool isEndOfWord;
    T* item;

    node(char val) : value(val), isEndOfWord(false), item(nullptr) {}
};

template <typename T>
class Trie {
    vector<node<T>*> roots;
    void printHelper(node<T>* current, string path);
public:
    void print();
    void insert(string s, T* item);
    T* search(string s);  // Modified return type
};

template <typename T>
void Trie<T>::insert(string s, T* item) {
    char rootval = s[0];
    bool found = false;
    node<T>* current = nullptr;

    for (auto it : roots) {
        if (it->value == rootval) {
            found = true;
            current = it;
            break;
        }
    }

    if (!found) {
        node<T>* toinsert = new node<T>(rootval);
        roots.push_back(toinsert);
        current = toinsert;
    }

    for (int i = 1; i < s.size(); ++i) {
        found = false;
        for (auto it : current->next) {
            if (it->value == s[i]) {
                current = it;
                found = true;
                break;
            }
        }
        if (!found) {
            node<T>* toinsert = new node<T>(s[i]);
            current->next.push_back(toinsert);
            current = toinsert;
        }
    }
    current->isEndOfWord = true;
    current->item = item;
}

template <typename T>
T* Trie<T>::search(string s) {
    for (auto root : roots) {
        if (s[0] == root->value) {
            int i = 1;
            node<T>* current = root;
            while (i < s.size()) {
                bool found = false;
                for (auto it : current->next) {
                    if (it->value == s[i]) {
                        current = it;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return nullptr;
                }
                i++;
            }
            if (current->isEndOfWord) {
                return current->item;
            } else {
                return nullptr;
            }
        }
    }
    return nullptr;
}

template <typename T>
void Trie<T>::printHelper(node<T>* current, string path) {
    if (!current) return;

    path += current->value;

    if (current->isEndOfWord) {
        cout << path;
        cout << endl;
    }

    for (auto child : current->next) {
        printHelper(child, path);
    }
}

template <typename T>
void Trie<T>::print() {
    for (auto root : roots) {
        printHelper(root, "");
    }
}

#endif //UNTITLED1_TRIE_H
