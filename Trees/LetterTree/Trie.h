// Created by Mahmoud Haney on 8/10/2022.
#ifndef DATASTRUCTURESTRAINING_TRIE_H
#define DATASTRUCTURESTRAINING_TRIE_H
using namespace std;
class Trie {
private:
    static const int MAX_CHAR = 26;
    Trie* children[MAX_CHAR];
    bool isLeaf { };
public:
    Trie();
    void insert(string str, int idx = 0);
    bool wordExist(string str, int idx = 0);
    bool prefixExist(string str, int idx = 0);
};
#endif //DATASTRUCTURESTRAINING_TRIE_H
