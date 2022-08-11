// Created by Mahmoud Haney on 8/2/2022.
#ifndef DATASTRUCTURESTRAINING_BINARYTREE_H
#define DATASTRUCTURESTRAINING_BINARYTREE_H
#include "vector"
using namespace std;
class BinaryTree {
private:
    struct node {
        int data { };
        node* left { };
        node* right { };
        node(int data) : data(data) {}
    };
    node* root {};

    void preOrder(node* current);
    void inOrder(node* current);
    void postOrder(node* current);
    int treeMax(node* current);
    int treeHeight(node* current);

public:
    BinaryTree(int root_value) : root(new node(root_value)) {}
    bool isEmpty();
    void preOrder();
    void inOrder();
    void postOrder();
    void add(vector<int> values, vector<char> direction);
    int treeMax();
    int treeHeight();
};
#endif //DATASTRUCTURESTRAINING_BINARYTREE_H
