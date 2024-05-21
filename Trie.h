using namespace std;
#include <iostream>
#include "vector"
#ifndef UNTITLED1_TRIE_H
#define UNTITLED1_TRIE_H
class node{
public:
    vector<node*>next;
    char value;
    bool isEndOfWord;

    node(char val) : value(val), isEndOfWord(false) {}

};
class Trie{
    vector<node*>roots;
    void printHelper(node* current, string path);
public:
    void print();
    void insert(string s);
};
#endif //UNTITLED1_TRIE_H
