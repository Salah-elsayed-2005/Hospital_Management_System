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
    T* item;

    node(char val) : value(val), item(nullptr) {}
};

template <typename T>
class Trie {
    vector<node<T>*> roots;
    void printHelper(node<T>* current, string path);
    bool deleteHelper(node<T>* current, const string &s, int depth);
public:
    void print();
    void insert(string s, T* item);
    T* search(string s);
    void deleteWord(string s);
};

template <typename T>
void Trie<T>::insert(string s, T* item) {
    s += '#';  // Add the special character at the end of the word
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
    current->item = item;
}

template <typename T>
T* Trie<T>::search(string s) {
    s += '#';  // Add the special character at the end of the word
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
            return current->item;
        }
    }
    return nullptr;
}

template <typename T>
bool Trie<T>::deleteHelper(node<T>* current, const string &s, int depth) {
    if (!current) return false;

    if (depth == s.size()) {
        if (current->value == '#') {
            current->item = nullptr;
            return current->next.empty();  // If true, delete this node
        }
        return false;
    }

    char ch = s[depth];
    node<T>* child = nullptr;
    for (auto it = current->next.begin(); it != current->next.end(); ++it) {
        if ((*it)->value == ch) {
            child = *it;
            if (deleteHelper(child, s, depth + 1)) {
                current->next.erase(it);
                delete child;
                return current->next.empty() && current->item == nullptr;
            }
            return false;
        }
    }
    return false;
}

template <typename T>
void Trie<T>::deleteWord(string s) {
    s += '#';  // Add the special character at the end of the word
    for (auto it = roots.begin(); it != roots.end(); ++it) {
        if ((*it)->value == s[0]) {
            if (deleteHelper(*it, s, 1)) {
                delete *it;
                roots.erase(it);
            }
            break;
        }
    }
}

template <typename T>
void Trie<T>::printHelper(node<T>* current, string path) {
    if (!current) return;

    if (current->value == '#') {
        cout << path << endl;  // Print the complete path
        return;
    }
    path += current->value;

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
