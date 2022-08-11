// Created by Mahmoud Haney on 8/10/2022.
#include <iostream>
#include <cstring>
#include "Trie.h"
using namespace std;


Trie::Trie() {
    memset(children, 0, sizeof(children));
}

void Trie::insert(string str, int idx) {
    if(idx == (int)str.size())
        isLeaf = true; // When string is done mark the last node as a leaf "end of the word".
    else{
        int cur = str[idx] - 'a'; // Char - a -> converts character to 0-25
        if(children[cur] == 0)
            children[cur] = new Trie();
        children[cur]->insert(str, idx + 1);
    }
}

bool Trie::wordExist(string str, int idx) {
    if (idx == (int) str.size())
        return isLeaf;	// When string is done return if the last node is a leaf or not
    int cur = str[idx] - 'a';
    if (!children[cur]) // Such path don't exist
        return false;
    return children[cur]->wordExist(str, idx + 1);
}

bool Trie::prefixExist(string str, int idx) {
    if (idx == (int) str.size())
        return true;	// All sub-words covered
    int cur = str[idx] - 'a';
    if (!children[cur]) // Such path don't exist
        return false;
    return children[cur]->prefixExist(str, idx + 1);
}
